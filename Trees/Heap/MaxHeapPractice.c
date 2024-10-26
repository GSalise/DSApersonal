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


void delete(MaxHeap *h, int val){
    int n = doesExist(*h, val);

    if(h->count > 0 && n > -1){
        h->elems[n] = h->elems[h->count - 1];
        h->count--;

        while(1){
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
                n = largest;
            }else{
                break;
            }

        }
    }
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

    return 0;
}