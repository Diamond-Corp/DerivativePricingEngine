//
//  CubicRoot_Solver.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include "CubicRoot_Solver.hpp"
#include <math.h>

// Signum function
int sgn(double num)
{
    if(num > 0)
        return 1;
    else if(num < 0)
        return -1;
    else
        return 0;
}

//Chapter 5.6 - Numerical Recipes (2007) - Page 227
double CRoot(double cubic, double quadratic, double linear, double constant)
{
    double roots[3];
    double a,b,c;
    double R, Q;
    double capA, capB, theta;
    double ret = 0.0;
    
    a = quadratic/cubic;
    b = linear/cubic;
    c = constant/cubic;
    
    Q = (pow(a,2)- 3*b)/ 9;
    R = (2*pow(a,3) - 9*a*b + 27*c)/54;
    
    if((pow(R,2) > pow(Q,3)) >= 0)
    {
        capA = -sgn(R) *(fabs(R) + pow(sqrt(pow(R,2) - pow(Q,3)), (1/3)));
        if(capA == 0)
            capB = 0;
        else
            capB = Q/capA;
        ret = capB + capA - a/3;
        
    }
    
    else
    {
        theta = acos(R/ pow(Q,1.5));
        roots[0]= -2 * sqrt(Q) * cos(theta/3) - a/3;
        roots[1] = -2 * sqrt(Q) * cos(theta / 3 + 2.0943951023932) - a / 3;
        roots[2] = -2 * sqrt(Q) * cos(theta / 3 - 2.0943951023932) - a / 3;
        
        if(roots[0] > 0)
            ret = roots[0];
        else if(roots[1] > 0)
            ret = roots[1];
        else
            ret = roots[2];
        
        if(roots[1] > 0 && ret > roots[1])
            ret = roots[1];
        if(roots[2] > 0 && ret > roots[2])
            ret = roots[2];
    }
    
    
    return ret;
}

