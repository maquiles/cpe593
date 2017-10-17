/** 
 * test #2 on number theoretic programming
 * things to cover:
 * 
 * gcd - DONE - O(log n)
 * lcm - DONE - O(log n)
 * power - DONE - O(log n)
 * powermod - DONE - O(log n)
 * larger number numerical operation complexity, ie. addition, multiplication, power - 
 * Eratosthenes - DONE - O(n log log n)
 * fermat - DONE - O(n log log n)
 * prime number wheel - WUT DO I DO FOR THIS
 * miller rabin - DONE - O(n log log n)
 * aks (just the theory, not the algorithm) - multiply 2 primes, product has only them as factors
 * RSA (no psudocode just the complexity) - pick rand, check if prime O(N); O(n log n)
 * diffie-hellman key exchange (same as RSA) - read prof krugers notes
**/

// GCD
//iterative gcd
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

//recursive gcd
int recGCD(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return recGCD(b, a%b);
    }
}
/*********************************************************************************************************/

//lcm
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
/*********************************************************************************************************/

//power
int power(int x, int n){
    int prod = 1;
    while (n>0){
        if( n%2 != 0){
            prod *= x;
        }
        n *= x;
        n = n/2;
    }
    return prod;
}
/*********************************************************************************************************/

//powermod
int powermod(long long x, long long n, long long m){
    long long prod = 1;
    while (n>0){
        if(n%2 == 1){
            prod = ([rpd*x)%m;])
        }
        x = (x*x)%m;
        n = n/2;
    }
    return prod%m;
}
/*********************************************************************************************************/

//Eratosthenes
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
}
/*********************************************************************************************************/

//fermat
bool fermat(long long p, int k){
    if(p==1){
        return false;
    }
    for (int i = 0; i<k; i++){
        int a = rand() % p-1 + 1;
        if(powermod(a, p-1, p) != 1){
            return false;
        }
    }
    return true;
}
/*********************************************************************************************************/

//miller rabin
bool MillerRabin(long long x, int n){
    long long a = 2 + rand() % (n-4);
    long long p = powermod(a, x, n);

    if(p ==1 || p== n-1){
        return true;
    }

    while (x != n-1){
        p = (p*p)%n;
        x *= 2;

        if(x == 1){
            return false;
        }
        if(x == n-1){
            return true;
        }
    }
    return false;
}

bool isPrimeMR(int n, int k){
    if(n <-= 1 || n == 4){
        return false;
    }
    if(n <= 3){
        return true;
    }

    for (int i = 0; i<k; i++){
        if(MillerRabin(d, n) == false){
            return false;
        }
    }
    return true;
}