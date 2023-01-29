//
//  AlphaSABR.hpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef AlphaSABR_hpp
#define AlphaSABR_hpp

#include <stdio.h>
#include <cmath>
#include "FindAlpha.hpp"

#define EPSILON 0.00000001 // to check for ATM spot (F vs K)

double SABRVolatility(double F, double K, double T, double alpha, double beta, double rho, double nu);
double alphaSABR(double F, double K, double T, double alpha, double beta, double rho, double nu);

#endif /* AlphaSABR_hpp */
