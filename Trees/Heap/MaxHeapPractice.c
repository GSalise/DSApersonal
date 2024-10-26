#include <stdio.h>
#include <stdlib.h>
#define MAX 0xA

typedef struct{
    int elems[MAX];
    int count;
}MaxHeap;


void init(MaxHeap *h){
    h->count = 0;
    for(int i = 0; i<MAX; i++){
        h->elems[i] = 0;
    }
}


//parent = (n-1)/2

void insert(MaxHeap *h, int val){

    if(h->count < MAX){
        int n = h->count;

        while(n > 0 && h->elems[(n - 1) / 2] < val){
            h->elems[n] = h->elems[(n-1) / 2];
            n = (n-1) / 2;
        }

        h->elems[n] = val;
        h->count++;
    }

}


int doesExist(MaxHeap h, int val){
    int i = 0;

    while(i < h.count && h.elems[i] != val){
        i++;
    }
    return (i < h.count) ? i : -1;

}

void heapify(MaxHeap *h, int n){
    int left = (2 * n) + 1;
    int right = (2 * n) + 2;
    int largest = n;

    if(left < h->count && h->elems[largest] < h->elems[left]){
        largest = left;
    }

    if(right < h->count && h->elems[largest] < h->elems[right]){
        largest = right;
    }

    if(largest != n){
        int temp = h->elems[n];
        h->elems[n] = h->elems[largest];
        h->elems[largest] = temp;
        heapify(h, largest);
    }
}

void delete(MaxHeap *h, int val){
    int n = doesExist(*h, val);

    if(h->count > 0 && n > -1){
        h->elems[n] = h->elems[h->count - 1];
        h->count--;
        if(n < h->count){
            heapify(h, n);
        }
    }
}

/*
    Heapsort is basically just a sorting algorithm for arrays
    where you turn the array into a heap (either min or max)
    then proceed to sort it by calling heapify.

    What heapsort does is
    1. Swap the root value with the rightmost value (i.e., last element of the array) of the tree
    
    2. We then decrease the count so that the swapped value (refering to the root value) will not be touched
        - In our case since our heap is a max heap the array will be sorted into ascending order
        - With the root value being the largest value in the entire heap moving it at the end of the
        array making it the first value of the sorted array
    
    3. Heapify the heap
        - We call heapify to restore the heap order
        - This also moves the largest value of the current heap into the root
        - Which will then be used to move the next position in the sorted array
    
    4. Repeat until i reaches goes out of bounds


*/

MaxHeap heapsort(MaxHeap *h){
    MaxHeap neww = *h;

    for(int i = neww.count - 1; i >=0; i--){
        int temp = neww.elems[0];
        neww.elems[0] = neww.elems[i];
        neww.elems[i] = temp;
        neww.count--;
        heapify(&neww, 0);
    }

    neww.count = h->count;

    return neww;
}

int main(){
    MaxHeap h;
    init(&h);
    insert(&h, 8);
    insert(&h, 3);
    insert(&h, 1);
    insert(&h, 6);
    insert(&h, 100);
    insert(&h, 9);

    for(int i = 0; i<h.count; i++){
        printf("%d ", h.elems[i]);
    }

    printf("\n");
    delete(&h, 100);
    for(int i = 0; i<h.count; i++){
        printf("%d ", h.elems[i]);
    }

    printf("\n");
    MaxHeap a = heapsort(&h);
    for(int i = 0; i<a.count; i++){
        printf("%d ", a.elems[i]);
    }

    return 0;
}