#include <iostream>
using namespace std;

int main()
{
	int a[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11};
	int (*p)[4];
	int i = 0, j = 0;
	p = a;
	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < 4; ++j)
		{
			//cout<<*(*(p + i)) + j<<" ";
			//cout<<(*(*p + i) + j)<<" ";
			cout<<(p + i)<<" ";
			//cout<<*(p + i)<<" ";
		}
		cout<<endl;
	}
	return 0;
}