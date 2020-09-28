#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*3.

The program must read in an NxN matrix with floating point numbers.
The program must determine the index of columns, which contains
one element that is equal to the average of the values in the same
column.The outputs are the indices of the columns.

*/

//***************************************************************************************//



//User Input part :
/*
int main(int args)
{
	//if (args == 0)return 0;
	int N,matches;
	int local_sum = 0;
	float *avg,*ptr, **arr;// array pointers to keep results and traverse the main array
	int i, j, z;// counters
	int k = 0, l = 0;// counters too
	FILE *fptr;
	char exit = '1';

	while (exit != '0')
	{
		printf("What is the length of your square matrix ?");
		scanf("%d", &N);//user input
		int length = sizeof(float *) * N + sizeof(float) * N * N;

		arr = (float **)malloc(length);// allocating memory dynamically
		avg = (float *)malloc(N);
		// ptr points to the first element in the square array
		ptr = (float *)(arr + N);


		for (i = 0; i < N; i++)
			arr[i] = (ptr + N * i);

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%f", &arr[i][j]);  // entering array values by the user






		// The algorithm is simply 
		// 1 ) finding the average of each column
		// 2 ) comparing the indivual values to the average
		// 3 ) writing the matching results

	   // 1 ) finding the average of each column

		z = arr[0][0];
		for (j = 0; j < N; j++)
		{
			local_sum = 0;
			for (i = 0; i < N; i++)
			{
				local_sum += arr[i][j];

			}
			avg[j] = local_sum / (float)N;
			
		//comparing the indivual values to the average
			matches = 0;
			for (i = 0; i < N; i++)
			{
				if (arr[i][j] == avg[j])
					matches += 1;
			}
		// writing the results
			if (matches >= 1)
				
			printf("we have a match in column %d  ,  the value matches the average of elements in the column.(%d time/s) \n", j,matches);


			fptr = fopen("D:\\Output.txt", "a"); // creating the output file and opening it

			fprintf(fptr, "We have a match in column %d ", j);// writing results to the file
			fprintf(fptr, " , we matched  %d time/s\n", matches);// writing results to the file
			

		
		}

		////writing to a file 
		// I chose not to delete the contents of the file everytime I run the program
		// that's why I used this : fopen("D:\\Output.txt", "a") 
		//and not this :			fopen("D:\\Output.txt", "w")
		fprintf(fptr, " ************** end of this part ************** ");





		printf("\nThe output file is on the disk D...\nPress any key to do it again and 0 to exit ... ");
		scanf(" %c", &exit);
	}
	return 0;


}

*/









// passing an input file from command prompt as an argument 
// I couldn't find out why It doesn't work from the first try,
// however it works ok the second time
int main(int argc, char **argv) {



	

	int i, sum = 0, newi = 0, k = 0;
	int n, I, J;




	
	char *str = NULL;
	double *d = NULL;
	double **ptr;
	ptr = d;
	str = (int *)malloc( sizeof(double));
	d = (double*)malloc( sizeof(double));
	FILE *fp = argc > 1 ? fopen(argv[1], "r") : stdin;
	FILE *fptr;

	float local_sum, *avg;
	int matches;




	if (!fp)
	{  //validate file open for reading 
		fprintf(stderr, "error: file open failed '%s'.\n", argv[1]);
		return 1;
	}



	for (i = 1;i < argc;i++)
	{
		while (fscanf(fp, "%s", str) != EOF)
		{
			//printf("%s\n", str);//just checking 
			newi++;// count the values in a file to validate the size of the matrix 
			sscanf(str, "%lf", &d[k]);//storing the values as double in a vector 
			k++;
		}


	}
	

	printf("Array D:\n");


	for (i = 0;i < newi;i++)
	{
		printf("%lf\n", d[i]);

	}
	

	if (fp != stdin) fclose(fp);   // close file if not stdin 

	printf("number of elements in the file is %d\n", newi);

	int length =(int) sqrt((double)newi);

	// without math.h
	/*int length = -1;
	 for (int k = 0;k <= (newi / 2);k++)
	 {
		 if (k*k == newi)
			 {
				 length = k;
				 break;
			 }
	 }

	 */




	printf("number of elements in  a row is %d\n", length);

	int r = length;
	float **arr = (int **)malloc(r * sizeof(int *));
	int w = 0;
	for (i = 0; i < r; i++)
		arr[i] = (int *)malloc(r * sizeof(int));

	avg = (float *)malloc(length);//dont forget to allocate memory 

	// I would like to make the array two dimensional 

	//  arr[i][j] is same as *(*(arr+i)+j)

	//populate the 2 dimensional array 


	for (i = 0; i < length; i++)
	{ 

		for (int j = 0; j < length; j++)
		{
			arr[i][j] = d[w];

			//printf("%lf\n", d[w]); giving arr integer type is a big problem it cast to float and populate with zeros 
			printf("%lf\n", arr[i][j]);

			w += 1;
		}
	}




		// 1 ) finding the average of each column
		// 2 ) comparing the indivual values to the average
		// 3 ) writing the matching results


			 // 1 ) finding the average of each column
	
	
	
		for (int j = 0; j < length; j++)
	    {
				local_sum = 0;
				for (i = 0; i < length; i++)
				{
					local_sum += arr[i][j];
					
				}
				//printf("%lf\n", local_sum);//delete

				avg[j] = local_sum / length;
				printf("%lf\n", avg[j]);//

				//comparing the indivual values to the average
				matches = 0;


				for (i = 0; i < length; i++)
				{
					if (arr[i][j] == avg[j])
						matches += 1;
				}

			fclose(fp);
				// writing the results
			if (matches >= 1)

			{
				
				printf("we have a match in column %d  the value matches the average of elements in the column.(%d time/s) \n", j, matches);
				 // creating the output file and opening it to Write without deleting previous results
				fptr = fopen("D:\\OutputfromFile.txt", "a");;
				fprintf(fptr, "We have a match in column %d ", j);// writing results to the file
				fprintf(fptr, " , we matched  %d time/s\n", matches);// writing results to the file
			}


					////fptr = fopen("D:\\Output.txt", "a"); // creating the output file and opening it

					////fprintf(fptr, "We have a match in column %d ", j);// writing results to the file
					////fprintf(fptr, " , we matched  %d time/s\n", matches);// writing results to the file
				

	    }


		fclose(fptr);

}


