#include<stdio.h>
#include<stdlib.h> 
#include <time.h>

float interpolate(float y1, float y2, float x1, float x2, float x){
	float y = y1 + ((x-x1)/(x2-x1)) * (y2-y1);
}

// interpolates
void terrain_inter(int size, float **M)
{
	// interpolate the rows with given randomized values
	int count = 0;
	for (int row = 0; row < size; row++)
	{
		if(row % 10 == 0)
		{
			for (int col = 0; col < size-1; col++)
			{
				
				int minimum, maximum;
				if (col % 10 == 0)
				{
					minimum = count *10;
					count = count + 1;
					maximum = count * 10;
				}

				if (col % 10 != 0)
				{
					float y = interpolate(M[row][minimum], M[row][maximum], minimum, maximum, col);
					M[row][col] = y;
				}
			}
		}
		count = 0;
	}
	
	// interpolate all other values here
	int count2 = 0;
	for (int row = 0; row < size; row++)
	{
		int minimum, maximum;
		
		if (row % 10 == 0)
		{
			minimum = count2 * 10;
			count2 = count2 + 1;
			maximum = count2 * 10;
		}
		
		if(row % 10 == 0)
		{ 
			continue; 
		} else
		{
			for (int col = 0; col < size; col++)
			{
				float y = interpolate(M[minimum][col], M[maximum][col], minimum, maximum, row);
				M[row][col] = y;
			}
		}
	}
}

int main()
{
	int size;
	float **M;
	clock_t time_before, time_after;
    double time_elapsed;

	printf("Enter size of the matrix: ");
	scanf("%d", &size);
	printf("%d x %d matrix\n", size, size);
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

	printf("\nBefore interpolating\n");
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			printf("%d ", (int) M[i][j]);
		}
		printf("\n");
	}
     
    time_before = clock();

	// terrain_inter here
	terrain_inter(size, &*M); 

	time_after = clock();

	// computing final run time in seconds
    time_elapsed = ((double) (time_after - time_before)) / CLOCKS_PER_SEC;

	printf("\nAfter interpolating or Resulting Matrix\n");
	printf("Note: Resulting matrix values are type casted to int for better viewing.\n");
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			printf("%d ", (int) M[i][j]);
		}
		printf("\n");
	}

	printf("\nTime elapsed: %f seconds\n", time_elapsed);

	free(M);
	return 0;
}