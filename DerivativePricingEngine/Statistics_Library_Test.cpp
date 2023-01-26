//
//  Statistics_Library_Test.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/26/23.
//

#include <stdio.h>
#include "Statistics.h"

int statistics_library_test_main()
{
    // create the standard normal distribution and random draw vectors
    StandardNormalDistribution snd;
    vector<double> uniform_draw(20,0.0);
    vector<double> normal_draw(20,0.0);
    
    // Random number generation based on RAND
    for(int i =0; i < uniform_draw.size() ; ++i)
        uniform_draw[i] = rand()/ static_cast<double>(RAND_MAX);
    
    snd.random_draws(uniform_draw, normal_draw);
    for(auto nd : normal_draw)
        cout << nd << '\n';
    
    return 0;
    
}
