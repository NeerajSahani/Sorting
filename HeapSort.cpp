#include <stdio.h>
#include <conio.h>

int a[] = {9, 1, 8, 2, 7, 3, 6, 4, 5}, n = 9;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void display()
{
	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");
}

void insert(int num, int loc)
{
	int parent;
	while (loc > 0)
	{
		parent = (loc - 1) / 2;
		if (num <= a[parent])
		{
			a[loc] = num;
			return;
		}

		a[loc] = a[parent];
		loc = parent;
	}
	a[0] = num;
}

void createHeap()
{
	for (int i = 0; i < n; i++)
		insert(a[i], i);
}

void delRoot(int last)
{
	int left, right, temp, i = 0;
	temp = a[i];
	a[i] = a[last];
	a[last] = temp;
	left = 2 * i + 1;
	right = 2 * i + 2;
	while (right < last)
	{
		if (a[i] >= a[left] && a[i] >= a[right])
			return;

		if (a[right] <= a[left])
			swap(&(a[i]), &(a[left])), i = left;

		else
			swap(&(a[i]), &(a[right]));

		left = 2 * i + 1;
		right = 2 * i + 2;
	}
	if (left == last - 1 && a[i] < a[left])
		swap(&(a[i]), &(a[left]));
}

void heapSort()
{
	for (int last = n - 1; last > 0; last--)
		delRoot(last);
}

int main()
{
	int i;
	printf("Unsorted data \n");
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);

	createHeap();
	heapSort();
	printf("\n\nSorted data \n");
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	getch();
}
