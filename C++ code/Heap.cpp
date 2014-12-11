#include<iostream>
#include<string>

using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

struct Heap{
    int capacity;
    int size;
    int* elem;
};

Heap* createHeap(int capacity){
    Heap* H = (Heap*)malloc(sizeof(Heap));
    H -> capacity = capacity;
    H -> size = 0;
    H -> elem = (int*)malloc(sizeof(int)*capacity);
    return H;
}

//minimum heap, from root to down
void sift_down(Heap* H, int start){
    int i = start, j;
    int key = H -> elem[start];  // i is the parent of j
    for(j = 2*i + 1; j < H -> size; j = 2*i + 1){
        if( j < H->size -1 && H -> elem[j] > H -> elem[j+1])
	    j = j + 1; // find the minimun of the left(j) or right(j+1) child
	if(H -> elem[j] >= key) break;
	H -> elem[i] = H -> elem[j];
	i = j;
    }
    H -> elem[i] = key;
}

//********minimum heap, from down to root
void sift_up(Heap* H, int start){
     int j  = start;
     int i = (j -1)/2;  // i is the parent of j
     int key = H -> elem[start];
     while(j > 0){
         if( H -> elem[i] <= key) break;
	 H -> elem[j] = H -> elem[i];
	 j = i;
	 i = (i-1)/2;
     }
     H -> elem[j] = key;
}

void Heap_Push(Heap* H, int key){
    if(H -> size == H -> capacity){  // realloc the array
      int* tmp = (int*)realloc(H -> elem, H -> capacity * 2 * sizeof(int));
      H -> elem = tmp;
      H -> capacity *= 2;
    }
    H -> elem[ H -> size++] = key;
    sift_up(H, H->size -1);  //from down to root
}

void Heap_Pop(Heap* H){
    if(H -> size == 0)  return;
    H -> elem[0] = H -> elem[H -> size -1];
    H -> size --;
    sift_down(H, 0);  // from root to down
}

void Heap_Sort(int A[], int n){
    Heap* H = createHeap(2*n);
    H -> size = n;
    H -> elem = A;

    int i = (H -> size -2)/2;  //H -> size - 1 is last elem, i is parent
    while( i >= 0){
      sift_down(H, i--);
    }
    // get the top of the hea;
    for(int i = H -> size - 1;  i > 0; --i){
      swap(H -> elem[0], H -> elem[i]);
      H -> size --;
      sift_down(H,0);
    }	  
}

int main(void){
    int arr[] = {3, 2, 9, 8, 5, 7, 6, 4, 1,0};
    int n = sizeof(arr)/sizeof(int);
    Heap* H = createHeap(2*n);
    H -> size = n;
    H -> elem = arr;
    Heap_Push(H, 13);
    sift_down(H, 0);
    Heap_Push(H, 34);
    //Heap_Sort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
       cout << arr[i] << " " ;
    getchar();
    return 0;
}
