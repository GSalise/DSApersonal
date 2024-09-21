#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Data.h"
#include "Stack.h"

bool addProductBaseOnExpiry(Inventory *i, Product p) {
	
	//Motherfucker karon pa nuon ko naka solve og sabot nga mana ang premid
	//yawa
	
	Inventory temp;
	initInventory(&temp);
	NodePtr neww = malloc(sizeof(NodeType));
	neww->prod = p;
	
	if(i->currQty + p.prodQty <= 100){
		if(i->top != NULL){
			
			// hold basically serves as holder for the next link of the item
			// this allows me to move my "i" and "temp" to the next item
			NodePtr hold;
			
			while(i->top != NULL && dateDifference(i->top->prod.expiry, p.expiry) > 0){
				
					//store the next link of "i" to top
					hold = i->top->link;
					
					
					// temp.top initial is set to NULL so i->top->link points to NULL;
					// this is only true for the first run of the while loop
					// as temp.top will hold i->top once the 3rd line of the loop runs
					i->top->link = temp.top;
					
					
					// temp.top now i->top
					// initial temp.top was NULL but bow its temp.top
					// what about temp.top->link?
					// this is basically reflected with the 2nd line of the loop where "i->top->link = temp.top"
					temp.top = i->top;
					
					
					// i->top now proceeds to move the next link cause hold has the next link
					// cause we set it up on the first line of the loop
					i->top = hold;
			}
			
			// the loop stop once the item in the invetory "i" has a lower expiry date than the new product "p"
			// or if i->top has reached NULL
			
			// neww now links with i->top
			// i->top then takes neww
			neww->link = i->top;
			i->top = neww;
			
			
			// this then transfers all of the items in temp
			// same idea with the first loop just reverse
			while(temp.top!=NULL){
				hold = temp.top->link;
				temp.top->link = i->top;
				i->top = temp.top;
				temp.top = hold;
			}
			
			i->currQty += p.prodQty;
			
		}else{
			neww->link = i->top;
			i->top = neww;
			i->currQty += p.prodQty;
		}
		
		return true;
		
	}else{
		return false;
	}

}

int main() {
    ProductList myProd;
    int numCount, selection;

    printf("Enter sequence or selection: (1-6): ");
    scanf("%d", &selection);
    printf("Enter the number of data: ");
    scanf("%d", &numCount);

    createAndPopulate(&myProd, selection, numCount);

    Inventory myInventory;
    initInventory(&myInventory);

    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }
    
    for(int i = 0; i < myProd.count; ++i) {
        printf("\n[%d.] Adding %s (%d): %s\n", i+1, myProd.prods[i].prodName, myProd.prods[i].prodQty, addProductBaseOnExpiry(&myInventory, myProd.prods[i])? "Success":"Fail");
        visualize(myInventory);
    }

    printf("\nUSING ADD PRODUCT:\n");
    visualize(myInventory);


    return 0;
}
