//
//  CorrelatedSnd_Library_Test.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/26/23.
//

#include <stdio.h>
#include "Statistics.h"
#include "Correlated_snd.h"

int main()
{
    int vals = 30;
    
    // Example of Uncorrelated SND
    StandardNormalDistribution snd;
    vector<double> snd_uniform_draws(vals, 0.0);
    vector<double> snd_normal_draws(vals, 0.0);
    
    // Simple random number generation
    for(int i =0; i < snd_uniform_draws.size() ; ++i)
        snd_uniform_draws[i] = rand()/static_cast<double>(RAND_MAX);
    
    snd.random_draws(snd_uniform_draws, snd_normal_draws);
    
    // Example of Correlated SND
    double rho = 0.5;
    CorrelatedSND csnd(rho, &snd_normal_draws);
    vector<double> csnd_uniform_draws(vals, 0.0);
    vector<double> csnd_normal_draws(vals, 0.0);
    
    // Uniform generation for correlated SND
    for(int i =0; i < csnd_uniform_draws.size() ; ++i)
        csnd_uniform_draws[i] = rand()/static_cast<double>(RAND_MAX);
    
    // Create the correlated standard normal draw series
    csnd.random_draws(csnd_uniform_draws, csnd_normal_draws);

    
    // Output the values of the standard normal random draws (correlated and uncorrelated)
      for (int i=0; i<snd_normal_draws.size(); i++) {
        std::cout << snd_normal_draws[i] << ", " << csnd_normal_draws[i] << std::endl;
      }
    
    
}
