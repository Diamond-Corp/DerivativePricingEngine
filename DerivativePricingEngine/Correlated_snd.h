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
    CorrelatedSND(const double _rho, const vector<double>* _uncorr_draws);
    virtual ~CorrelatedSND();
    
    //Obtain a sequence of correlated random draws from another set of SND draws
    virtual void random_draws(const vector<double>& uniform_draws, vector<double>& dist_draws);
    
};




#endif /* Correlated_snd_h */
