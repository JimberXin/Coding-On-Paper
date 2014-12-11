/**
 * Created by JimberXin on 14/12/11.
 */
public class BubbleSort {
    public static void bubble_sort(int[] A){
        if(A==null) return;
        int n = A.length;
        boolean exchange;
        for(int i=0; i<n; ++i){
            exchange = false;
            for(int j=n-1;j>i;--j){
                if(A[j] < A[j-1]){ //smaller one bubbles to front
                    int temp = A[j];
                    A[j] = A[j-1];
                    A[j-1] = temp;
                    exchange = true;
                }
            }//end for j
            if(!exchange) return;
        }// end for i
    }

}
