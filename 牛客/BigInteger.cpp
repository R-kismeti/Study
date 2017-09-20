#include <string.h>
#include <iostream>
using namespace std;

//同版本的c语言无法进行结束排序

int main()
{
    char a[200][1000];
    char b[1000];//大整数必须存为字符型的数组才可以保存；
    int N;
    while (cin >> N)
    {
        if (N>100 || N<1)
            continue;
        for (int i = 0; i<N; i++)
            cin >> a[i];
        for (int i = 0; i<N; i++)
        {
            for (int j = i + 1; j<N; j++)
            {
                if (strlen(a[i]) >strlen(a[j]) || ((strlen(a[i]) == strlen(a[j])) && strcmp(a[i], a[j])>0))
                {
                    strcpy(b, a[i]);
                    strcpy(a[i], a[j]);
                    strcpy(a[j], b);
                }
            }
        }

        for (int i = 0; i<N; i++)
        {
            cout << a[i] << endl;
        }
    }
    return 0;
}