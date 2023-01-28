//
//  AsianOption_Library_Test.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include <stdio.h>
#include <iostream>
#include "PayOff.hpp"
#include "AsianOption.hpp"
#include "Path_Generation_Asian.h"

using namespace std;

int AsianOption_Library_Test_main()
{
    unsigned num_sims= 100000; // number of simulated asset paths
    unsigned num_intervals = 250; // numsber of intervals for the asset path to be sampled
    double S = 30.0;
    double K = 29.0;
    double r = 0.08;
    double v = 0.3;
    double T = 1.00;
    
    std::vector<double> spot_prices(num_intervals, S);
    // Create a payoff object
    PayOff *pay_off_call = new PayOffCall(K);
    //Asian option Object
    AsianOptionArithmetic asian(pay_off_call);
    // update the spot price vector with simulated spot price paths at constant intervals
    double pay_off_sum  = 0.0;
    for(int i = 0; i < num_sims ; ++i)
    {
        calc_path_spot_prices(spot_prices, r, v, T);
        pay_off_sum += asian.pay_off_price(spot_prices);
    }
    
    double discounted_payoff_avg = (pay_off_sum/ static_cast<double>(num_sims)) * exp(-r*T);
    delete pay_off_call ;
    
    cout<< "Number of paths : " <<  num_sims << '\n';
    cout<< "Number of intervals : " <<  num_intervals << '\n';
    cout<< "Underlying price : " <<  S << '\n';
    cout<< "Strike : " <<  K << '\n';
    std::cout << "Risk-Free Rate: " << r << std::endl;
    std::cout << "Volatility: " << v << std::endl;
    std::cout << "Maturity:  " << T << std::endl;
    
    cout << "Asian Arithmetic Option Price : " << discounted_payoff_avg << '\n';
    
    
    
}
