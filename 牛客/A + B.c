#include <stdio.h>
#include <string.h>
#define N 100

int main()
{
  	char A[N],
  		 B[N];
  	int len1 = 0, len2 = 0;
  	int a = 0, b = 0;
  	int i, j;

  	while(scanf("%s%s", A, B) != EOF)
  	{
      	len1 = strlen(A);
      	len2 = strlen(B);
      	a = 0;
      	b = 0;

	    for(i = 0; i < len1; i++)
	    {
	        if(A[i] >= '0' && A[i] <= '9')
	        {
	            a = a*10 + A[i] - '0';
	        }
	    }
	    if(A[0] == '-')
	    {
	       a = -a;
	    }

	    for(j = 0; j < len2; j++)
	    {
	        if(B[j] >= '0' && B[j] <= '9')
	        {
	           b = b*10 + B[j] - '0';
	        }
	    }
	    if(B[0] == '-')
	    {
	      	b = -b;
	    }

	    printf("%d", a+b);
	    putchar(10);
	}
  return 0;
}