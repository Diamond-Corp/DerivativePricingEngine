//
//  Option.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include "Option.hpp"


Option::Option(double _k, double _r, double _T, PayOff* _pay_off):
K(_k), r(_r), T(_T), pay_off(_pay_off){}




