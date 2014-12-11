/**
 * Created by JimberXin on 14/12/11.
 */
public class InsertionSort {
    public static void insert_sort(int[] A){
        if(A == null) return;
        int n = A.length;
        int i,j;
        for(i=1; i<n; ++i){
            int key = A[i];
            for(j=i-1; j>=0 && A[j]>key; --j){
                A[j+1] = A[j];
            }//end for j
            A[j+1] = key;
        }//end for i
    }
}
