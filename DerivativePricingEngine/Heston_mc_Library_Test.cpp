//
//  Heston_mc_Library_Test.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include <stdio.h>
//#include "PayOff.hpp"
//#include "Option.hpp"
#include "Correlated_snd.h"
#include "Heston_mc.hpp"

void generate_normal_correlation_paths(double rho, vector<double>& spot_normals , vector<double> &cor_normals)
{
    auto vals = spot_normals.size();
    StandardNormalDistribution snd;
    vector<double> snd_uniform_draws(vals, 0.0);
    
    //uniform generation for uncorrelated SND
    for(int i = 0; i < snd_uniform_draws.size() ; ++i)
        snd_uniform_draws[i] = rand()/static_cast<double>(RAND_MAX);
    
    //Create standard normal random draws
    snd.random_draws(snd_uniform_draws, spot_normals);
    
    //Create correlated standard normal distribution
    CorrelatedSND csnd(rho, &spot_normals);
    vector<double> csnd_uniform_draws(vals, 0.0);
    
    //uniform generation for correlated SND
    for(int i = 0; i < csnd_uniform_draws.size() ; ++i)
        csnd_uniform_draws[i] = rand()/static_cast<double>(RAND_MAX);
    
    // create correlated standard normal draw series
    csnd.random_draws(csnd_uniform_draws, cor_normals);
    
    
}


int main()
{
    // Paramter list
    auto num_sims = 100000; // number of simulated asset paths
    auto num_intervals = 1000; // number of intervals for asset path to be sampled
    
    double S_0 = 100.0;
    double K = 100.0;
    double r = 0.0319;
    double v_0 = 0.010201;
    double T = 1.00;
    
    double rho = -0.7;
    double kappa = 6.21;
    double theta = 0.019;
    double xi = 0.61;
    
    //create payoff, option and heston objects
    PayOff* pPayoffCall = new PayOffCall(K);
    Option *pOption =  new Option(K,r,T,pPayoffCall);
    HestonEuler hest_euler(pOption, kappa, theta, xi, rho);
    
    vector<double> spot_draws(num_intervals ,0.0);
    vector<double> vol_draws(num_intervals , 0.0);
    vector<double> spot_prices(num_intervals, S_0);
    vector<double> vol_prices(num_intervals, v_0);
    
    // Monte Carlo Option Pricing
    double payoff_sum = 0.0;
    for(unsigned i =0 ; i < num_sims ;++i)
    {
        cout << "calculating path " <<  i+1 << " of" << num_sims << '\n';
        generate_normal_correlation_paths(rho, spot_draws, vol_draws);
        hest_euler.calc_vol_path(vol_draws, vol_prices);
        hest_euler.calc_spot_path(spot_draws, vol_prices, spot_prices);
        payoff_sum += pOption->pay_off->operator()(spot_prices[num_intervals - 1]);
        
        
    }
    
    double option_price = (payoff_sum / static_cast<double>(num_sims))* exp(-r*T);
    cout << "Option price : " << option_price << endl;
    
    delete pOption;
    delete pPayoffCall;
    
    
    
    
    
    
}



