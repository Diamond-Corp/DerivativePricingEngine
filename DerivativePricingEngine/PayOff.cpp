//
//  PayOff.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include "PayOff.hpp"

PayOff::PayOff() {}

PayOffCall::PayOffCall(const double & _K) {K = _K;}
double PayOffCall::operator() (const double& S)const
{
    return std::max(S-K, 0.0 ); // Standard European Call Payoff
}

PayOffPut::PayOffPut(const double & _K) {K = _K;}
double PayOffPut::operator()(const double &S) const
{
    return std::max(K-S, 0.0); // Standard European Put Payoff
}

