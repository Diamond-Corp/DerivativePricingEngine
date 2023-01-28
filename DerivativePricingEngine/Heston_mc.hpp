//
//  Heston_mc.hpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef Heston_mc_hpp
#define Heston_mc_hpp

#include <stdio.h>
#include "Option.hpp"

class HestonEuler
{
private:
    Option * pOption;
    double kappa;
    double theta;
    double xi;
    double rho;
    
public:
    HestonEuler(Option *_pOption, double _kappa, double _theta, double _xi, double _rho);
    virtual ~HestonEuler() {};
    
    //Calculate volatiliy path
    void calc_vol_path(const vector<double>& vol_draws, vector<double> & vol_path);
    
    // Calculate asset price path
    void calc_spot_path(const vector<double>& spot_draws,const vector<double>& vol_path, vector<double>& spot_path);
    
};

#endif /* Heston_mc_hpp */
