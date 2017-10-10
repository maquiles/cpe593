/*
** Matthew Aquiles
** CPE 593 hw1a Compute Primes
** due 10/10/2017
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include<sstream>

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
    ifstream infile("hw1a.dat");
    string line;

    while (getline(infile, line)){
        stringstream iss(line);
        long int n;
        vector<long int> vec;
        while (iss >> n){
            vec.push_back(n);
        }

        if(vec.size() == 1){
            //do nothing
        }
        else{
            cout<< ComputePrimes(vec[0], vec[1])<< "\n";;
        }
    }

    return 0;
}