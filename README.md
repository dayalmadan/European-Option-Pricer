# European Option Pricer

European Vanilla Call and Put Option pricing and Implied Volatility calculation in C++

## Installation

Add EuropeanVanilla.h and EuropeanVanilla.cpp in your project.

## Option Price and Greeks Example

### The 'UpdatePriceAndGreeks' method gives prices, deltas, gammas, thetas, and vegas of both call and put option

double StrikePrice = 20;<br>
EuropeanVanilla pricer(StrikePrice); // class object requires strike price <br>

double StockPrice = 15;<br>
double DaysToExpiry = 30;<br>
double InterestRate = 0.05;<br>
double Volatility = 0.2;<br>

pricer.UpdatePriceAndGreeks(StockPrice, InterestRate, DaysToExpiry, Volatility); // calculate price and greeks and updates public members <br>

#### Option Price

cout << pricer.CallPrice << endl;<br>
cout << pricer.PutPrice << endl;<br>

#### Option Delta

cout << pricer.CallDelta << endl;<br>
cout << pricer.PutDelta << endl;<br>

#### Option Gamma

cout << pricer.CallGamma << endl;<br>
cout << pricer.PutGamma << endl;<br>

#### Option Theta

cout << pricer.CallTheta << endl;<br>
cout << pricer.PutTheta << endl;<br>

#### Option Vega

cout << pricer.CallVega << endl;<br>
cout << pricer.PutVega << endl;<br>

## Implied Volatility Example

#### The class implements Newton-Raphson method which converges faster

cout << "Call IV: " << pricer.ImpliedVolatility(StockPrice, InterestRate, DaysToExpiry, CallPrice, 'C') << endl;<br>

cout << "Put IV: " << pricer.ImpliedVolatility(StockPrice, InterestRate, DaysToExpiry, PutPrice, 'P') << endl;<br>

