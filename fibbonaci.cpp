//
// Created by epm04 on 04/02/2024.
//

#include <iostream>
#include "fibbonaci.h"

//Fibonnaci recursive alg
int fibX(int nthFib) {
    if (nthFib <= 2) return 1;
    return fibX(nthFib - 1) + fibX(nthFib - 2);
}

//space optimised
int fibSpaceComOpt(int nthFib) {
    int fibMin1 = 1;
    int fibMin2 = 1;
    for(int i = 2; i < nthFib; i++){
        int mem = fibMin1;
        fibMin1 = fibMin1 + fibMin2;
        fibMin2 = mem;
    }
    return fibMin1;
}

//recursive dynamic programming
//memorizing each calculation we make until result
//algorithm uses previous results to calculate new rather than 2^n recursive stack
int fibDynProg(int nthFib){
    int fibArr[nthFib + 2];
    fibArr[0] = 0;
    fibArr[1] = 1;

    for(int i = 2; i <= nthFib; i++){
        fibArr[i] = fibArr[i-1] + fibArr[i-2];
    }

    return fibArr[nthFib];
}


#include "fibbonaci.h"
