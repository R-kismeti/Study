#include <stdio.h>
#include <stdlib.h>

int Merge(int a[], int n)
{
	int s1, s2, mid, i = 0, k = 0;
	int b[n];
	mid = n/2, s1 = 0, s2 = mid;
	while(s1<mid && s2 < n)
	{
		if(a[s1] <= a[s2])
            b[k++] = a[s1++];
        else
            b[k++] = a[s2++];
	}
	if(s1 < mid)
		for(i = s1; i < mid; i++)
		{
			b[k++] = a[i];
		}
	else
		for(i = s2; i < n; i++)
		{
			b[k++] = a[i];
		}
    for(k = 0; k < n; k++)
    {
        a[k] = b[k];
    }
    return 1;
}

int MergeSort(int a[], int n)
{
	if(n <= 1)
		return 1;
	MergeSort(a, n/2);
	MergeSort(a+n/2, n-n/2);
	Merge(a, n);
	return 1;
}

int main()
{
	int n = 0;
	while(scanf("%d", &n) != EOF)
	{
		int i = 0;
		int *a = (int *)malloc(sizeof(int) * n);
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		MergeSort(a, n);
		for(int j = 0; j < n; j++)
			printf("%d ", a[j]);
		putchar(10);
		free(a);
	}
	return 0;
}