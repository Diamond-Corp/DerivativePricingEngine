//
//  Correlated_snd.h
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/26/23.
//

#ifndef Correlated_snd_h
#define Correlated_snd_h

#include "Statistics.h"

class CorrelatedSND : public StandardNormalDistribution
{
protected:
    double rho;
    const vector<double>* uncorr_draws;
    
    // Modify an uncorrelated set of distribution draws to be correlated
    virtual void correlation_calc(vector<double>& dist_draws);
    
public:
    
    
};




#endif /* Correlated_snd_h */
