#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

using namespace std;

double memo[53][53] = {0};
//so this wont work if it is greater than 52

double choose(int n, int r)
{
    if (memo[n][r] != 0){
        return memo[n][r];
    }
    
    if (r==0 || r==n)
    {
        return memo[n][r] = 1;
    }
    else
    {
        return memo[n][r] = choose(n-1, r-1) + choose(n-1, r);
    }
}

int main()
{
    //calculate random n from 1 - 52
    //calculate random r from 0 - n
    //do this 100M times
    int n, r;
    srand(time(NULL));
    for (int i = 0; i< 100000000; i++){
        n = rand() % 52 + 1;
        r = rand() % n;

        //cout<< n<< ' '<< r<< ' '<< choose(n,r)<< endl;
    }

    cout<< n<< ' '<< r<< ' '<< choose(n,r)<< endl;
    return 0;
}
