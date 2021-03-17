//
//  EuropeanVanilla.h
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#pragma once
#include <cmath>

class EuropeanVanilla
{
    const double mStrikePrice; // strike price of the option
    
    double CDF(double x) const; // return cdf of standard normal distribution
    double PDF(double x) const; // pdf of x
    double DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const; // d+ = (log(S0/K) + (r + sigmaˆ2) * T) / (sigma * sqrt(T))
    
    double NewtonRaphsonSolver(double (EuropeanVanilla::*BSMPrice) (const double, const double, const double, const double), const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Target, const double Guess); // non-linear solver using Newton-Raphson method
    double PutPriceByBS(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility); // put price using black scholes
    double CallPriceByBS(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility); // call price using black scholes
    
public:
    
    EuropeanVanilla(const double StrikePrice): mStrikePrice(StrikePrice) {};
    
    void UpdatePriceAndGreeks(const double UnderlyingPrice, const double InterestRate, const double DaysToExpiry, const double Volatility); // update call/put price and greeks
    
    double CallPrice, PutPrice, CallDelta, PutDelta, CallGamma, PutGamma, CallTheta, PutTheta, CallVega, PutVega;
    
    double ImpliedVolatility(const double UnderlyingPrice, const double InterestRate, const double DaysToExpiry, const double OptionPrice, const char CallPut); // calculate implied volatility of call or put option given market parameters
};
