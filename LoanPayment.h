//
// Created by _edd.ie_ on 25/05/2024.
//

#ifndef LOANPAYMENT_H
#define LOANPAYMENT_H
#include <cmath>


inline double loan(const double rate, const double amount, const int years )
{
    return (amount*(rate/1200))/(1-1/(std::pow((1+rate),(years*12))));
}

inline double total(const double monthly, const int years)
{
    return monthly*12*years;
}

#endif //LOANPAYMENT_H
