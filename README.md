# European Option Pricer

European Vanilla Call and Put Option pricing and Implied Volatility calculation in C++

## Installation

Add EuropeanVanilla.h and EuropeanVanilla.cpp in your project.

## Code Example

double StrikePrice = 20;
EuropeanVanilla pricer(StrikePrice);


double StockPrice = 15;
double DaysToExpiry = 30;
double InterestRate = 0.05;
double Volatility = 0.2;

pricer.UpdatePriceAndGreeks(StockPrice, InterestRate, DaysToExpiry, Volatility);


The UpdatePriceAndGreeks method gives prices, deltas, gammas, thetas, and vegas of both call and put option


// Option Price

cout << pricer.CallPrice << endl;

cout << pricer.PutPrice << endl;


// Option Delta

cout << pricer.CallDelta << endl;

cout << pricer.PutDelta << endl;


// Option Gamma

cout << pricer.CallGamma << endl;

cout << pricer.PutGamma << endl;


// Option Theta

cout << pricer.CallTheta << endl;

cout << pricer.PutTheta << endl;


// Option Vega

cout << pricer.CallVega << endl;

cout << pricer.PutVega << endl;
