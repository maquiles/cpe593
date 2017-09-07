#include <iostream>
#include <stdio.h>

using namespace std;

int memo[53][53] = {0};
//so this wont work if it is greater than 52

int choose(int n, int r)
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
    cout<< choose(52,6) << endl;
    return 0;
}
