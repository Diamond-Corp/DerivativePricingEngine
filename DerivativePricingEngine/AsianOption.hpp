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
    virtual double pay_off_price(const vector<double>& spots) const = 0;
    
protected:
    PayOff* pay_off;
    
    
    
};

#endif /* AsianOption_hpp */
