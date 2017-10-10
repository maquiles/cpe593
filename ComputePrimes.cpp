/* HW1a Compute Primes
** Write a program that accepts 2 whole numbers a and b, with a<b<10^14
** must use Eratosthenes sieve
** program should account for the number of primes between a and b inclusive and output the number
** 
** Matthew Aquiles
** CPE 593
** due 10/10/2017
*/

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

bool isPrime(long int n){
    for (long int i = 2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int ComputePrimes(long int a, long int b){
    long int delta = b-a;
    vector<bool> primes(delta+1, true);
    long int count = 0;

    //remove even numbers
    if(a%2==0){
        if(a == 2){//so if a is 2 it does not get marked false
            for (long int i = 2; i<=delta; i+=2){
                primes[i] = false;
            }
        }
        else{
            for (long int i = 0; i<=delta; i+=2){
                primes[i] = false;
            }
        }
    }
    else{ //a%2 == 1
        if(a == 1){//in case a is 1, 2 does not get marked false, but 1 does
            primes[0] = false;
            for (long int i = 3; i<=delta; i+=2){
                primes[i] = false;
            }
        }
        else{
            for (long int i = 1; i<=delta; i+=2){
                primes[i] = false;
            }
        }
    }

    //loop through odd numbers and remove primes
    for (long int j = 3; j<=sqrt(b); j+=2){
        if(isPrime(j)){
            long int x = a/j;
            long int y = x*j;
            if(y >= a){
                for (long int k = y; k<=b; k+=j){
                    if (primes[k-a] == true && k != j){
                        primes[k-a] = false;
                    }
                }
            }
            else{
                for (long int k = y+j; k<=b; k+=j){
                    if (primes[k-a] == true && k != j){
                        primes[k-a] = false;
                    }
                }
            }
        }
    }

    //loop through primes, return count of true
    for (long int p = 0; p<primes.size(); p++){
        if(primes[p] == true){
            count++;
        }
    }

    return count;
}

int main(){
    cout<< ComputePrimes(2000000000000, 2000000100000)<< "\n";

    return 0;
}