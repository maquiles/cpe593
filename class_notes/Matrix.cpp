#include<iostream>
#include<fstream>
using namespace std;

class Matrix{
private:
    int rows, cols;
    double* m;
    Matrix(int r, int c) : rows(r), cols(c), m(new double[r*c]) {
    }
public:
    Matrix(int r, int c, double val) : rows(r), cols(c), m(new double[r*c]){
        for (int i = 0; i< r*c; i++){
            m[i] = val;
        }
    }
    ~Matrix() {
        delete [] m; //O91)
    }
    Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new double[rows*cols]){
        for (int i = 0; i < rows*cols; i++){
            m[i] = orig.m[i]; //O(r*c)
        }
    }
    //copy and swap
    Matrix& operator =(const Matrix& orig){
        Matrix copy(orig);
        swap(m, copy.m);
        rows = copy.rows;
        cols = copy.cols
        return *this;
    }
    double operator[] (int i) const{
        return m[i];
    }
    double& operator[](int i){
        return m[i];
    }
    //move constructor
    Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols) {
        m = orig.m;
        orig.m = nullptr;
    }

    friend Matrix operator +(const Matrix& a, const, Matrix& b){
        if(a.rows != b.rows || a.cols != b.cols){
            throw "Bad matrix size";
        }
        Matrix ans(a.rows,a.cols);
        for(int i = 0; i < a.rows*a.cols; ++i){
            ans[i] = a[i] + b[]i];
        }
        return ans;
    }

    double operator() (int i, int j) const{
        //return m[i*cols.]
    }
}

int main(){
    Matrix a(3,4,0.0); //O(mn) = O(3*4)
    Matrix b(4,2,1.0) //O(n*p) = O(4*2)
    Matrix c = b;
    Matrix d = a * b; //O(mnp)
    Matrix e = a + a; //(mn)
    b(1,1) = 5.2;
    c = b;

    ifstream f("hw5.dat");
    Matrix A = Matrix::read(f);
    vector<double> B = read(A.getRows(), f);
    vecotr<double> x = A.solve(B);
    for (auto v : x) {
        cout<< v<< '\t';
    }
}