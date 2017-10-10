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

using namespace std;

int ComputePrimes(int a, int b){
    vector<bool> primes(b-a, true);
    int count = 0;

    //first compare the numbers and switch them if a > b
    //then remove all even numbers
    if(a%2==0){
        for (int i = 0; i<a-b; i+=2){
            primes[i] = false;
        }
        
    }
    //then remove multiples of 3 and up

}

int main(){
    return 0;
}