//
//  PayOff.hpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#ifndef PayOff_hpp
#define PayOff_hpp

#include <stdio.h>
#include <algorithm>
class PayOff
{
public:
    PayOff();
    virtual ~PayOff() {};
    
    // Turns Payoff into abstract function object
    virtual double operator()(const double & S) const = 0;
    
};

class PayOffCall : public PayOff
{
private :
    double K ; // Strke Price
    
public :
    PayOffCall(const double& K_);
    virtual ~PayOffCall() {};
    
    // Virtual fucntion is now overriden
    virtual double operator()(const double & S) const;

};

class PayOffPut : public PayOff
{
private :
    double K ; // Strke Price
    
public :
    PayOffPut(const double& K_);
    virtual ~PayOffPut() {};
    
    // Virtual fucntion is now overriden
    virtual double operator()(const double & S) const;

};

#endif /* PayOff_hpp */
