//
//  main.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/26/23.
//

#include <iostream>
#include <vector>
#include "Correlated_snd.h"
#include "AsianOption.hpp"
#include "PayOff.hpp"
#include "Path_Generation_Asian.h"
#include "Option.hpp"
#include "Heston_mc.hpp"
#include "CubicRoot_Solver.hpp"


using namespace std;

int main(int argc, const char * argv[])
{
    vector<int> vec{1,2,3,4,5};
    for(auto v : vec)
        cout << v << '\n';
    
}
