//
//  FindAlpha.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include "FindAlpha.hpp"
#include <vector>
#include <iostream>
#include "CubicRoot_Solver.hpp"

double findAlpha(double F, double K, double T , double atmVol, double beta, double rho, double nu)
{
    double Alpha= 0.0;
    //Find coefficients for solving the cubic equation for Alpha
    double c3 = pow(1- beta,2)*T /(24 * pow(F, 2 - 2*beta));
    double c2 = rho*beta*nu*T/(4 * pow(F, 1-beta));
    double c1 = 1 + (2-3*pow(rho,2))/24 * pow(nu,2)*T;
    double c0 = -atmVol*pow(F, 1-beta);
    
    Alpha = CRoot(c3, c2, c1, c0);
    return Alpha;
    
}


    

