#include<stdio.h>
#include<stdlib.h> 

float **M;

// interpolates
void terrain_inter(int size)
{
	// interpolate here
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			float y = 
		}
	}

	// after interpolating
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			printf("%f\t", M[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int size;
	printf("Enter size of the matrix: ");
	scanf("%d", &size);
	printf("%dx%d matrix\n", size, size);
	size = size+1;

	M = (float**)malloc(size*sizeof(float*));
	for (int i = 0; i < size; i++){
		M[i] = (float*)malloc(size*sizeof(float));
	}

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if(i%10 == 0 & j%10==0){
				int number = (rand() % (1000 - 1 + 1)) + 1;
				M[i][j] = number;
			}
		}
	}

	// before interpolating
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			printf("%f\t", M[i][j]);
		}
		printf("\n");
	}

	// terrain_inter here


	
	free(M);

	return 0;
}