#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

//function to find the gcd of 2 ints using brute force
int bruteForceGCD(int a, int b){
    for (int i=min(a,b); i>=2; i--){
        if(a%i == 0 && b%i ==0){
            return i;
        }
    }
    return 1;
}

//function to find gcd of 2 ints iteratively
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

//function to find gcd of 2 int using recursion
int recGCD(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return recGCD(b, a%b);
    }
}

//function to compute the lcm using gcd
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

//function to find out if a number is prime using brute force
bool bruteForceIsPrime(int n){
    for (int i = 2; i < n-1; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

//function to compute if a number is prime with O(sqrt(n))
bool isPrime(int n){
    for (int i = 2; i<=sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

//function to compute the number of primes up to an int n
int countPrimes(int n){
    int count = 0;
    for (int i = 2; i<=n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}

//functions using eratosthenes sieve algorithm to calculate the number of primes <= n
//most efficient way of computing this
void Eratosthenes(int n){
    vector<bool> primes(n, true);
    for (int i = 2; i<n; i++){
        if(primes[i] == true){
            for (int j = i*2; j<n; j+=i){
                primes[i] = false;
            }
        }
    }

    for (int k = 2; k<n; k++){
        if(primes[k] == true){
            cout<< k<< "\n";
        }
    }
}//i dont know why this doesnt work, i think its something wrong with the vector

//modified eratosthenes
void modifiedEratosthenes(int n){
    vector<bool> primes(n, true);
    for (int i = 2*2; i<n; i+=2){
        primes[i] = false;
    }
    for (int j = 3; j<n; j+=2){
        if(primes[j] == true){
            for (int k = j*j; k<n; k+=2*j){
                primes[k] = false;
            }
        }
    }

    for (int l = 2; l<n; l++){
        if(primes[l] == true){
            cout<< l<< "\n";
        }
    }
}//this one works, so im really not sure why the other one doesnt work, i must be missing something

int main(){
    // cout<< bruteForceGCD(44,256)<<"\n";
    // cout<< gcd(44,256)<<"\n";
    // cout<< recGCD(44,256)<<"\n";
    // cout<< lcm(44,256)<<"\n";
    // cout<< bruteForceIsPrime(9)<< "\n";
    // cout<< isPrime(7)<< "\n";
    // cout<< countPrimes(11)<< "\n";
    modifiedEratosthenes(20);
}