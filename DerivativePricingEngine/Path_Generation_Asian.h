//
//  Path_Generation.h
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef Path_Generation_Asian_h
#define Path_Generation_Asian_h

#include <vector>
#include <cmath>

using namespace std;

// Box_Muller method for random gaussian geenration
double gaussian_box_muller()
{
    double x = 0.0;
    double y = 0.0;
    double euclid_sq = 0.0;
    
    // Continue generating two uniform random variables
    // until the square of their "euclidean distance"
    // is less than unity
    
    do{
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) -1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) -1;
        euclid_sq = x*x + y*y;
    }
    while(euclid_sq >=1 );
    return x*sqrt(-2*log(euclid_sq)/euclid_sq);
    
}

//This provides a vector containing sampled points of a GBM stock price path
void calc_path_spot_prices(vector<double>& spot_prices, // evctor of spot prices to be filled
                           const double& r, // risk free interest rate
                           const double& v, // volatility of the underlying
                           const double&T) // Expiry
{
    double dt = T / static_cast<double>(spot_prices.size());
    double drift = exp(dt*(r - 0.5*v*v));
    double vol = sqrt(v*v*dt);
    
    for(int i = 1 ; i < spot_prices.size() ; ++i)
    {
        double gauss_bm = gaussian_box_muller();
        spot_prices[i] = spot_prices[i-1]*drift*exp(vol*gauss_bm);
        
    }
    
}


#endif /* Path_Generation_h */
