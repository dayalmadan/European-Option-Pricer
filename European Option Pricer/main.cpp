//
//  main.cpp
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#include <iostream>
#include "EuropeanVanilla.h"

using namespace std;

int main()
{
    const double S0 = 15;
    const double K = 15;
    const double T = 1277.5; // in days
    const double r = 0.05;
    const double sigma = 0.2;
    EuropeanVanilla pricer(K);
    pricer.UpdatePriceAndGreeks(S0, r, T, sigma);
    
    cout << "Call Price: " << pricer.CallPrice << endl;
    cout << "Put Price: " << pricer.PutPrice << endl;
    
    return 0;
}
