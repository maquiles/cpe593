/** Test 3 Topics
 *** GrowArray
 *** LinkedLists (all types: LL, LL2, DLL, DLL2)
 *** Deallocation of memory - destructors
 *** Stacks
 *** Queues
 * 
 * Matrix
 * representation and mapping rules for regular matrix
 * m[r*cols + c] triangular
 * diagonal
 * if(i != j) return 0;
 * return m[i]
 * 
 * tridiagonal: m[3*i + (j-i) + 1] --> m[i+i + j]
 * 
 * know definition and complexity for:
 * addition, subtraction, multiplication, gauss-jordan, partial pivoting, full-pivoting
 * be able to show partial or full pivoting on a matrix (just 1, not the whole thing)
 * be able to compute complexity
 * for nxn matrix A and column vector x
 * Ax is O(n^2)
 * 
 * LU factorization. should be able to demonstrate a single row of the algorithm (simple numbers, no calculator required)
 * Ex: 
 * 2 1 3 1 0 0
 * 1 3 1 0 1 0
 * 
 * to wupe out the number below the 2 in the first column, multiply first row by -1/2
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


