/**
 * Created by JimberXin on 14/12/11.
 */
public class QuickSort {
    public static int partition(int[] A, int left, int right){
        if(A == null) return -1;
        int i = left;
        int j = right;
        int pivot = A[left];
        while(i < j){
            while(i<j && A[j] >= pivot) --j;
            A[i] = A[j];
            while(i<j && A[i] <= pivot) ++i;
            A[j] = A[i];
        }
        A[i] = pivot;
        return i;
    }
    public static void quick_sort(int[] A, int left, int right){
        if(A == null)  return;
        if(left < right){
            int index = partition(A,left,right);
            quick_sort(A,left,index-1);
            quick_sort(A,index+1,right);
        }
    }
}
