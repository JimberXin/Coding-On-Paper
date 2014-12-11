/**
 * Created by JimberXin on 14/12/11.
 */
public class MergeSort {
    public static void merge_sort(int[] A, int[] temp, int left, int right) {
        if(A == null) return;
        if(left < right){
            int mid = left + ((right - left)>>1);
            merge_sort(A,temp,left,mid);
            merge_sort(A,temp,mid+1,right);
            merge(A,temp,left,mid,right);
        }
    }

    public static void merge(int[] A, int[] temp, int left, int mid, int right){
        if(A == null || temp == null) return;
        for(int i=left; i<=right; ++i)
            temp[i] = A[i];

        int i = left, j = mid+1, k = left;
        while(i<=mid && j <=right){
            if(A[i] <= A[j])
                A[k++] = temp[i++];
            else
                A[k++] = temp[j++];
        }
        while(i<=mid) A[k++] = temp[i++];
        while(j<=right) A[k++] = temp[j++];
    }

    //counts the reverse pairs of the array
    public static int merge_count(int[] A,int[] temp,int left,int mid,int right){
        for(int i=left;i<=right;++i)
            temp[i] = A[i];

        int i = mid, j = right, k = right;
        int count = 0;
        while(i>=left && j>= mid+1){
            if(temp[i] > temp[j]){
                A[k--] = temp[i--]; //inverse pairs;
                count += j - mid;
            }else
                A[k--] = temp[j--];
        }
        while(i>=left) A[k--] = temp[i--];
        while(j>=mid+1) A[k--] = temp[j--];
        return count;
    }

    public static int merge_reverse(int[] A, int[] temp, int begin, int end){
        if(A == null) return -1;
        if(begin < end){
            int mid   = begin + ((end-begin)>>1);
            int left  = merge_reverse(A,temp,begin,mid);
            int right = merge_reverse(A,temp,mid+1,end);
            int mer = merge_count(A,temp,begin,mid,end);
            return left+right+mer;
        }
        return 0; // if begin >= end
    }
}
