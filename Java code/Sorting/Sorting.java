/**
 * Created by JimberXin on 14/12/11.
 */
public class Sorting {
    public static void main(String[] args){
        System.out.println("Different Sorting Algorithm:");
        int[] A = {32,12,45,2,8,7,5,1,19,26,9,7};
        int n = A.length;
        BubbleSort bs = new BubbleSort();
        InsertionSort is = new InsertionSort();
        QuickSort  qs = new QuickSort();
        ShellSort ss = new ShellSort();
        SelectSort ses = new SelectSort();
        //bs.bubble_sort(A);
        //is.insert_sort(A);
        //qs.quick_sort(A,0,n-1);
        //ss.shell_sort(A);
        ses.select_sort(A);
        for(int x:A)
            System.out.print(x+ " ");
    }

}
