#include <stdio.h>
#include <conio.h>
void sort(int a[], int n);
void swap(int *a, int *b)
{
	*a = *a ^ *b;
}
int main()
{
	int i, j, a[50], n;

	printf("Enter Number of elements to insert :");
	scanf("%d", &n); // length of array

	printf("Enter data .....\n");

	for (i = 0; i < n; i++) //loop form 0 to length of array
	{
		printf("\tA[%2d] :", i); //print index for input
		scanf("%d", &a[i]);		 // insert array elements
	}

	for (i = 0; i < n; i++)
		printf("%5d", a[i]); //print array elements before sorting

	printf("\n sorted array is ......\n");

	sort(a, n - 1); // calling sort method a is array and n-1 is last index

	for (i = 0; i < n; i++) // printing sorted array
		printf("%5d", a[i]);

	getch();
}

void sort(int a[], int n, int x)
{
	int i, j, t;
	for (i = 0; i < n; i++) // loop for index
	{
		for (j = 0; j < n; j++) // loop for values
		{
			if (x == 1) // condition for ascendind order
			{
				if (a[j] > a[j + 1]) // if number is greater than next number
				{					 // then swap
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
	}
}
