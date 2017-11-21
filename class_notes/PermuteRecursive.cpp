#include<iostream>
using namespace std;

class Permute {
private:
    int* p;
    int N;
public:
    Permute(int x[], int N) : p(x), N(N) {
        this->generate(N-1);
    }

    void generate(int n){
        if(n == 0){
            doit();
            return; 
        }
        for (int c = 0; c <= n; c++){
            swap(p[c], p[n]);
            generate(n-1);
            swap(p[c], p[n]);
        }
    }

    void doit(){
        for (int i = 0; i<N; i++)
            cout<< p[i];
        cout<< "\n";
    }
};

int main(){
    int x[] = {1, 2, 3, 4};
    Permute perm(x, 4);
}