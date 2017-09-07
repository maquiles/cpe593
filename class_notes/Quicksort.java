//5 september 2017
//in class psudo code for quicksort
public class Quicksort {
    public static void quicksort(int[] x, int, L, int R) {
        if (L>=R)
            return;

        int i = L, j = R;
        while (i<j){}
            while (x[i] < pivot)
                i++;
            while (x[j] > pivot)
                j--;
            swap(x[i], x[j]);
        }
        //partition into 2 halves

        quicksort(x, L, i);
        quicksort(x, i+1, R);
    }
}