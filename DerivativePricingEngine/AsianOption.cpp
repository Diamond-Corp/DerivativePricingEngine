//
//  AsianOption.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include "AsianOption.hpp"

#include <numeric>
#include <cmath>

AsianOption::AsianOption(PayOff* _pay_off) : pay_off(_pay_off){}

AsianOptionArithmetic::AsianOptionArithmetic(PayOff *_pay_off) : AsianOption(_pay_off){}

double AsianOptionArithmetic::pay_off_price(const vector<double> &spot_prices) const
{
    auto num_times = spot_prices.size();
    double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0);
    double arith_mean = sum / static_cast<double>(num_times);
    return (*pay_off)(arith_mean);
    
}

AsianOptionGeometric::AsianOptionGeometric(PayOff* _pay_off): AsianOption(_pay_off){}

double AsianOptionGeometric::pay_off_price(const vector<double> &spot_prices) const
{
    auto num_times = spot_prices.size();
    double log_sum = 0;
    for(auto spot : spot_prices)
        log_sum += log(spot);
    
    double geom_mean = exp(log_sum)/ static_cast<double>(num_times);
    return (*pay_off)(geom_mean);
    
}

                                             

