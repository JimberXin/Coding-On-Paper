/**
 * Created by JimberXin on 14/12/11.
 */
public class ShellSort {
    public static void shell_sort(int[] A){
        if(A == null) return;
        int n = A.length;
        int gap = n;
        while(gap>1){
            gap /= 3;
            int i,j;
            for(i=gap; i<n; ++i){
                int temp = A[i];
                for(j=i-gap; j>=0 && A[j]>temp; j -= gap)
                    A[j+gap] = A[j];
                A[j+gap] = temp;
            }//end for i
        }//end for while
    }
}
