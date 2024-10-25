#include <stdio.h>
#include <stdlib.h>
#define MAX 0xA

typedef struct{
    int elems[MAX];
    int count;
}MinHeap;


/*
    Formula for finding children
    2n+1 = Left
    2n+2 = Right

    Formula for parent
    (n-1)/2


    What the insert basically does is:
    1. Insert the newest value to the current available space
        a. This is done with h->count
    
    2. Compare the inserted value with its parents
        a. See if the inserted value is smaller than its parents
        b. If it is smaller then we move it up/bubble it up
    
    3. Take the value of the parent and store it with the inserted value's position
        a. We take the parent's position using the formula (n-1)/2
        b. We then place the value of the parent to the inserted value's position
        c. Update the inserted value's position to the parent's position

    4. Place the inserted value to the parent's position

    5. Do it until the inserted value is bigger than its parent


    In the current insert function we don't immediately insert the new value
    to the current available position but rather use that position to swap
    the parents downwards. Once the condition has been broken, we will then
    insert the new value.


*/

void insert(MinHeap *h, int val){

    if(h->count < MAX){
        int n = h->count;

        while(n > 0 && val < h->elems[(n - 1) / 2]){
            h->elems[n] = h->elems[(n-1) / 2];          //3.b
            n = (n-1)/2;                                //3.c
        }

        h->elems[n] = val;
        h->count++;
    }

}


int doesExist(MinHeap h, int val){
    int n = 0;
    while(n<h.count && h.elems[n] != val){
        n++;
    }

    return (n < h.count) ? n : -1;
}

/*
    The doesExist function ensures that the value to be deleted exists and provides the
    index of said value.

    What delete basically does is:
    1. Swaps the deleted value with the rightmost value (i.e., the last value in the array)
        a. Decrement the count by 1 so that the righmost value will no longer be accessed.

    2. Fix the MinHeap tree by finding the smallest children of the parent

    3. Smallest is set to n
        a. n refers to the index of the deleted value which is now replaced by the rightmost value
    
    4. Find the smallest children
        a. Find the smallest children by checking out which of the two children (left and right) is smaller
        b. Also ensure that the index of both left and right children don't go beyond the current count
    
    5. Compare if the smallest is equal to n
        - i.e., Compare if the index that is set to the smallest value is the same as the index of the replaced value
        a. If false, swap the 2 elements
        b. With the two elements swapped, set n to the corresponding swapped index
            - This is to ensure that n still points to the replaced value
    
    6. Repeat the cycle until smallest is equal to n


*/

void delete(MinHeap *h, int val){
    int n = doesExist(*h, val);

    if(h->count > 0 && n != -1){

        h->elems[n] = h->elems[h->count - 1];
        h->count--;


        while(1){
            int left = (2 * n) + 1;
            int right = (2 * n) + 2;
            int smallest = n;

            if(left < h->count && h->elems[smallest] > h->elems[left]){            //4.a-b
                smallest = left;
            }

            if(right < h->count && h->elems[smallest] > h->elems[right]){          //4.a-b
                smallest = right;
            }


            if(smallest != n){                                              //5.a
                int temp = h->elems[n];
                h->elems[n] = h->elems[smallest];
                h->elems[smallest] = temp;
                n = smallest;                                               //5.b
            }else{
                break;
            }
        }
    }
}



int main(){
    MinHeap a;
    a.count = 0;
    for(int i = 0; i<MAX; i++){
        a.elems[i] = 0;
    }

    insert(&a, 58);
    insert(&a, 26);
    insert(&a, 8);
    insert(&a, 18);
    insert(&a, 2);
    insert(&a, 98);
    


    for(int i = 0; i<a.count; i++){
        printf("%d ", a.elems[i]);
    }

   delete(&a, 2);

   printf("\n");
   for(int i = 0; i<a.count; i++){
        printf("%d ", a.elems[i]);
    }



    return 0;
}