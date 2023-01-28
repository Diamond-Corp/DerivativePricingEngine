//
//  Option.hpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef Option_hpp
#define Option_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "PayOff.hpp"
#include <cmath>


using namespace std;

class Option
{
public :
    PayOff* pay_off;
    double K;
    double r;
    double T;
    
    Option(double _k, double _r, double _T, PayOff* _pay_off);
    virtual ~Option(){};
    
    
};

#endif /* Option_hpp */
