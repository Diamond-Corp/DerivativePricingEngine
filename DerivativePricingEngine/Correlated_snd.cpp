//
//  Correlated_snd.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/26/23.
//

#include <stdio.h>
#include "Correlated_snd.h"

CorrelatedSND::CorrelatedSND(const double _rho, const vector<double>* _uncorr_draws)
: rho{_rho} , uncorr_draws{_uncorr_draws}{}

CorrelatedSND::~CorrelatedSND(){}

// Actual Correlation Calculation based on Formula to generate correlated asset paths
// if rho = 0.0, then dist_draws is unmodified whereas if rho = 1.0 then dist_draws is set equal to uncorr_draws
void CorrelatedSND::correlation_calc(vector<double> &dist_draws)
{
    for(int i=0; i < dist_draws.size() ; ++i)
        dist_draws[i] = rho * (*uncorr_draws)[i] + dist_draws[i] * sqrt(1- rho*rho);
}

void CorrelatedSND::random_draws(const vector<double> &uniform_draws, vector<double> &dist_draws)
{
    //Check that the uniform draws and dist_draws have the same size
    if(uniform_draws.size() != dist_draws.size())
    {
        std::cout << "Draws vectors are of unequal size in standard normal dist." << endl;
        return;
    }
    
    // Check that the uniform_draws have even number of elements (Necessary conditon for Box-Muller Metho   d)
    if(uniform_draws.size() %2 != 0){
        std::cout << "Uniform draw vector size not an even number." << std::endl;
        return;
    }
    
    for(int i =0; i < uniform_draws.size()/2 ; ++i)
    {
        dist_draws[2*i] = sqrt(-2.0*log(uniform_draws[2*i]))*sin(2*M_PI*uniform_draws[2*i +1]);
        dist_draws[2*i + 1] = sqrt(-2.0*log(uniform_draws[2*i]))*cos(2*M_PI*uniform_draws[2*i +1]);
    }
    
    // Modify the random draws via the correlation calculation
    correlation_calc(dist_draws);
    
    return ;
    
}







