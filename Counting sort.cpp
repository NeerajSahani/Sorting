/* Counting sort	*/
#include <stdio.h>
#include <conio.h>

void counting_sort(int a[], int len)
{
	int i, max = -99999, b[30], c[30];
	for (i = 1; i <= len; i++)
	{
		if (max < a[i])
			max = a[i];
	}

	for (i = 0; i <= max; i++)
		c[i] = 0;

	for (i = 1; i <= len; i++)
		c[a[i]]++;

	for (i = 1; i <= max; i++)
		c[i] += c[i - 1];

	for (int j = len; j > 0; j--)
	{
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
	for (int j = len; j > 0; j--)
		a[j] = b[j];
}

int main()
{
	int a[30], n;
	printf("Enter No. of elements :");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	counting_sort(a, n);

	printf("Sorted array is...\n");

	for (int i = 1; i <= n; i++)
		printf("%4d", a[i]);
	getch();
}
