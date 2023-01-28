//
//  AsianOption.hpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef AsianOption_hpp
#define AsianOption_hpp

#include <stdio.h>
#include <vector>
#include "PayOff.hpp"

using namespace std;

class AsianOption
{
public :
    AsianOption(PayOff* _pay_off);
    virtual ~AsianOption() {};
    
    // This will determine Arithmetic or Geometric Asian option type
    virtual double pay_off_price(const vector<double>& spot_prices) const = 0;
    
protected:
    PayOff* pay_off;  // Pay-Off class (in this instance call or put - Polymorphism)
    
};

class AsianOptionArithmetic : public AsianOption
{
public :
    AsianOptionArithmetic(PayOff* _pay_off);
    virtual ~AsianOptionArithmetic() {};
    
    //Override pure virtual function to produce arithemetic asian option
    virtual double pay_off_price(const vector<double>& spot_prices) const;
    
    
};

class AsianOptionGeometric : public AsianOption
{
public :
    AsianOptionGeometric(PayOff* _pay_off);
    virtual ~AsianOptionGeometric() {};
    
    //Override pure virtual function to produce Geometric asian option
    virtual double pay_off_price(const vector<double>& spot_prices) const;
    
    
};

#endif /* AsianOption_hpp */
