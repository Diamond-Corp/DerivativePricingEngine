//
//  SABR_Library_Test.cpp
//  DerivativePricingEngine
//
//  Created by Shashank Choudhary on 1/28/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include "AlphaSABR.hpp"
#include "FindAlpha.hpp"

using namespace std;

double ** createMatrix(unsigned int rows, unsigned int cols)
{
    double **matrix;
    matrix = (double**)calloc(rows,sizeof(double *));
    for(int i = 0; i < rows; ++i)
        matrix[i] = (double *)calloc(cols, sizeof(double));
    
    return matrix;
}

void print_2Dmatrix2(double** matrix, std::vector<double>& headers, std::vector<double>&labels) {
    int rows = labels.size();
    int cols = headers.size();
    // first header is 'p' correlation.  This is not in headers.
    std::cout << "\tp\t";
    for (int i = 0; i < headers.size(); ++i) {
        cout << "K =" << (int)headers[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        cout  << labels[i] << "\t";
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    // Required inputs
        double F = 100;            // Futures price
        double T = 0.5;            // Maturity in years
        double beta = 0.999;         // beta SABR parameter
        double nu = 0.5;            // vol - of - vol SABR parameter
        double ATMvol = 0.30;      // Market ATM volatility
    
    // Define the strikes and correlation levels
    std::vector<double> K = { 70, 80, 90, 100, 110, 120, 130 };
    // Correlation levels are simply incremented by .25 about a mean of zero
    std::vector<double> rho = { -0.75, -0.50 ,-0.25, 0.00, 0.25, 0.50, 0.75 };
    
    auto I = rho.size();
    auto J = K.size();
    
    
    double** SABR_vol = createMatrix(I, J);
    double** alpha = createMatrix(I, J);
    
    
    for(int i =0; i < I ; ++i)
    {
        for(int j = 0; j < J ;++j)
        {
             alpha[i][j] = findAlpha(F, K[i], T, ATMvol, beta, rho[i], nu);
            SABR_vol[i][j] = SABRVolatility(F, K[i], T, alpha[i][j], beta, rho[i], nu);
        }
    }
    
    std::cout << "SABR Black-76 Equivalent Volatilies (%)" << std::endl << std::endl;
    print_2Dmatrix2(SABR_vol,K, rho);
    std::cout << std::endl;
    std::cout << "Alpha Parameter Values" << std::endl << std::endl;
    print_2Dmatrix2(alpha, K, rho);
    std::cout << std::endl;
    
    
    
    
}
