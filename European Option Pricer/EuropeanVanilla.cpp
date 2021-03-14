//
//  EuropeanVanilla.cpp
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#include "EuropeanVanilla.h"

double EuropeanVanilla::PDF(double x) const // probability density function
{
    const double PI = atan(1.0) * 4;
    return (1.0/sqrt(2.0 * PI)) * exp(-0.5 * x * x);
}

double EuropeanVanilla::CDF(double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) * 0.5;
}

double EuropeanVanilla::DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const
{
    return (log(UnderlyingPrice / mStrikePrice) + (InterestRate + 0.5 * pow(Volatility,2.0)) * YearsToExpiry) /(Volatility * sqrt(YearsToExpiry));
}

void EuropeanVanilla::UpdatePriceAndGreeks(const double UnderlyingPrice, const double InterestRate, const double DaysToExpiry, const double Volatility) // update call/put price and greeks
{
    const double YearsToExpiry = DaysToExpiry / 365.0;
    const double d1 = DPlus(UnderlyingPrice, InterestRate, YearsToExpiry, Volatility);
    const double d2 = d1 - Volatility * sqrt(YearsToExpiry); // d- = d+ - sigma * sqrt(T)

    const double PD_d1 = PDF(d1); // probability density
    const double CD_d1 = CDF(d1); // cumumative density

// Calculate delta of call and put using put call parity
    CallDelta = CD_d1;
    PutDelta = CallDelta - 1;
    
// Apply BSM formula to get call and put price
    const double CD_d2 = CDF(d2);
    const double DiscountFactor = exp(-InterestRate * YearsToExpiry);
    CallPrice = UnderlyingPrice * CD_d1 - mStrikePrice * DiscountFactor * CD_d2;
    PutPrice = mStrikePrice * DiscountFactor * CDF(-d2) + UnderlyingPrice * PutDelta;
    
// Gamma calculation, call and put have same gamma
    CallGamma = PD_d1 / (UnderlyingPrice * Volatility * sqrt(YearsToExpiry));
    PutGamma = CallGamma;
    
// Theta calculation
    CallTheta = -UnderlyingPrice * PD_d1 * Volatility / (2 * sqrt(YearsToExpiry)) - InterestRate * mStrikePrice * DiscountFactor * CD_d2;
    PutTheta = -UnderlyingPrice * PDF(-d1) * Volatility / (2 * sqrt(YearsToExpiry)) + InterestRate * mStrikePrice * DiscountFactor * CDF(-d2);
    
// Vega calculation, call and put have same vega
    CallVega = UnderlyingPrice * PD_d1 * sqrt(YearsToExpiry);
    PutVega = CallVega;
    
    return;
}
