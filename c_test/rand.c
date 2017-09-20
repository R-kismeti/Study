#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int i = 0;
	srand ((unsigned)time(NULL));
	for(i = 0; i > -1 ++i)
	{
		printf("%-3d", rand()%14);
		getchar();
	}
	return 0;
}