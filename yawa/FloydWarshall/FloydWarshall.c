#include <stdio.h>
#include <stdlib.h>

#define INF 9999



void solve(int matrix[5][5]){
	int i, j, k;
	
	/*
		FLoydWarshall Alogrithm
		
		Basically "k" serves as your reference point which is why it is the outermost loop
			- it replaces the positions of "i" and "j" for the comparison between matrix[i][j]
		
		"i" and "j" serves as your traversal, they basically traverse the entire 2d array
			- Each update of "k" the "i" resets to 0 like how "j" resets to 0 once "i" updates
			- Follows the basic 2d array traversal rules
		
		The switch happens once matrix[i][k] + matrix[k][j] < matrix[i][j]
	
	*/
	
	for(k = 0; k < 5; k++){
		for(i = 0; i < 5; i++){
			for(j = 0; j < 5; j++){
				if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				} 
			}
		}
	}
	
	
	for(int a = 0; a < 5; a++){
		for(int b = 0; b < 5; b++){
			if(matrix[a][b] == INF){
				printf("INF\t");
			}else{
				printf("%d\t", matrix[a][b]);
			}
		}
		printf("\n");
	}
	
}


int main(){
	int matrix[5][5] = {
		{0, INF, 2, INF, INF},
		{INF, 0, 1, INF, 2},
		{12, INF, 0, INF, 4},
		{3, INF, 10, 0, INF},
		{INF, 3, INF, 1, 0}
	};	
	
	solve(matrix);
	
	return 0;
}
