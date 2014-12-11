/**
 * Created by JimberXin on 14/12/11.
 */
public class SelectSort {
    public static void select_sort(int[] A){
        if(A == null) return;
        int n = A.length;
        for(int i=0; i<n; ++i){
            int min_index = i;
            for(int j=i+1;j<n;++j){
                if(A[j] < A[min_index])
                    min_index = j;
            }
            if(min_index != i){//select the minum num from i to end
                int temp = A[i];
                A[i] = A[min_index];
                A[min_index] = temp;
            }
        }//end for j
    }

}
