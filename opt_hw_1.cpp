#include <iostream>
#include <stdio.h>

using namespace std;

struct Memoize{
    int memo[53][53] = {0};
}

int choose(int n, int r)
{
    int Memoize.memo[n+1][r+1];

    if (memo[n][r] != 0){
        return Memoize.memo[n][r];
    }
    
    if (r==0 || r==n)
    {
        return Memoize.memo[n][r] = 1;
    }
    else
    {
        return Memoize.memo[n][r] = choose(n-1, r-1) + choose(n-1, r);
    }
}

int main()
{
    cout<< choose(10,2) << endl;
    return 0;
}
