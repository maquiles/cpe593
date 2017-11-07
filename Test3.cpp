/** Test 3 Topics
 *** GrowArray
 *** LinkedLists (all types: LL, LL2, DLL, DLL2)
 *** Deallocation of memory - destructors
 *** Stacks
 *** Queues
 * 
 * Matrix - complexity O(nmp) if n=m=p O(n^3)
 * row major: m[i*cols + j]
 * column major: m[j*rows +i]
 * 
 * lower triangular - O(n^2)
 * upper triangular - O(n^2)
 * 
 * diagonal
 * if(i != j) return 0;
 * return m[i]
 * 
 * tridiagonal: O(n)
 * m[3*i + (j-i) + 1] --> m[i+i + j +1] --> [i*2 +j]
 * 
 * know definition and complexity for:
 * addition
 * subtraction
 * multiplication
 * gauss-jordan
 * partial pivoting
 * 
 * full-pivoting
 * be able to show partial or full pivoting on a matrix (just 1, not the whole thing)
 * be able to compute complexity
 * for nxn matrix A and column vector x
 * Ax is O(n^2)
 * 
 * LU factorization - O(n^3)
 * should be able to demonstrate a single row of the algorithm (simple numbers, no calculator required)
 * Ex: 
 * 2 1 3 1 0 0
 * 1 3 1 0 1 0
 * 
 * to wipe out the number below the 2 in the first column, multiply first row by -1/2
 * 2 1     3   1 0 0
 * 1 2.5 -.5 -.5 1 0
 * 
 * complexity of this operation = 2n = O(n)
 * 
 * Complexity of wiping out fist column using the 2 = O(n^2)
 * Complexity of gauss-jordan O(n^3)
 * 
 * would be nice to know the existance of Strassen O(n^2.807) and Coppersmith-Winograd(2.37) but you will not have to do anything 
 * do not have to do grahm-schmidt
 * 
**/

//triangular matrix psudo code
double getTriangleMatrix(int i, int j){
    if(j >i){
        return 0;
    }
    return m[i*(i+1)/2+j];
}

double get(int i, int j){ //O(1)
    if(Math.abs(i-1) > 1){ //this is a java thing i beleive
        return 0;
    }
    return m[3*i + j-i + 1]; // return m[2*i + j];
}
