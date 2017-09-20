#include <stdio.h>
#include <stdlib.h>

int reset(char** p, int size, int new_size)
{
    int ret = 1;
    int i = 0;
    int len = 0;
    char* pt = NULL;
    char* temp = NULL;
    char* pp = *p;

    if((p != NULL) && (new_size > 0))
    {
         pt = (char *)malloc(new_size);
         temp = pt;
         len = (size < new_size) ? size : new_size;

         for(i = 0; i < len; ++i)
         {
              *temp++ = *pp++;
         }
         free(*p);
         *p = pt;
    }
    else
    {
         ret = 0;
    }
    return ret;
}

int main()
{
    char* p = (char*)malloc(5);

    printf("%0x\n", p);

    if(reset(&p, 5, 3))
    {
        printf("%0x\n", p);
    }

    return 0;
}
