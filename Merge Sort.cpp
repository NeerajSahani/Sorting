#include <stdio.h>
#include <conio.h>

void merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low, temp[50];

	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= mid)
		temp[k++] = a[i++];

	while (j <= mid)
		temp[k++] = a[j++];

	for (k = low; k <= high; k++)
		a[k] = temp[k];
}

void merge_sort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = int(low + high) / 2;

		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	int a[20], i, n;
	printf("Enter Number of Elements :");
	scanf("%d", &n);
	printf("Enter Elements.....\n");

	for (i = 0; i < n; i++)
	{
		printf("A[%d] :", i);
		scanf("%d", &a[i]);
	}

	printf("Entered Array is ......\t\t");

	for (i = 0; i < n; i++)
		printf("%4d", a[i]);

	merge_sort(a, 0, n); //a is array, 0 is starting index, n is end index

	printf("\nSorted Array is ......\t\t");

	for (i = 0; i < n; i++)
		printf("%4d", a[i]);

	getch();
}
