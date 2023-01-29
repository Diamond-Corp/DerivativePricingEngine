//
//  FindAlpha.hpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef FindAlpha_hpp
#define FindAlpha_hpp

#include <stdio.h>
#include <cmath>
#include <numeric>

double findAlpha(double F, double K, double T , double atmVol, double beta, double rho, double nu);

#endif /* FindAlpha_hpp */
