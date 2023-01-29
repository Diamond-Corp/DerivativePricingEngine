//
//  AlphaSABR.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include "AlphaSABR.hpp"

double SABRVolatility(double F, double K, double T, double atmvol, double beta, double rho, double nu)
{
    return alphaSABR(F, K, T, findAlpha(F,K,T,atmvol, beta, rho,nu), beta, rho, nu);
}

double alphaSABR(double F, double K, double T, double alpha, double beta, double rho, double nu)
{
    
    double SABR[3];
    double sabrz, y;
    
    SABR[0] = alpha / (pow(F*K, (1 - beta) / 2) *
                    (1 +(pow(1 - beta, 2) / 24)
                    * pow(log(F / K), 2)
                    + (pow(1 - beta, 4) / 1920) * pow(log(F / K), 4)));
    if(fabs(F-K) > EPSILON)
    {
        sabrz= (nu/alpha) * pow(F*K, (1-beta)/2) * log(F/K);
        y = (sqrt(1 - 2*rho*sabrz + pow(sabrz,2)) + sabrz - rho) / (1 -  rho);
        if(fabs(y-1) < EPSILON)
            SABR[1] = 1;
        else if(y > 0)
            SABR[1] = sabrz/log(y);
        else
            SABR[1] = 1;
        
    }
    
    else
        SABR[1] = 1;
    
    SABR[2] = 1 + (((pow(1 - beta, 2) / 24)* pow(alpha, 2) / (pow(F*K, (1 - beta))))
            + rho*beta*nu*alpha / (4 * (pow(F*K, (1 - beta) / 2)))
            + (2 - 3 * pow(rho, 2)) * pow(nu, 2) / 24) * T;

        return SABR[0] * SABR[1] * SABR[2];
    
    
}
