#include <stdio.h>
#include <conio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int low, int high)
{
	int i, j, pivot;
	pivot = a[high];
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (a[j] <= pivot)
			swap(&(a[++i]), &(a[j]));
	}
	return i;
}

void quick_sort(int a[], int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(a, low, high);
		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);
	}
}

int main()
{
	int n, i, a[50];
	printf("Enter Number of Elements :");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("A[%d] :", i);
		scanf("%d", &a[i]);
	}
	printf("Your Array is.....\t\t");

	for (i = 1; i <= n; i++)
		printf("%5d", a[i]);
	printf("\n");

	quick_sort(a, 1, n);

	printf("\nsorted Array is.....\t\t");

	for (i = 1; i <= n; i++)
		printf("%5d", a[i]);

	getch();
}
