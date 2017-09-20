#include <stdio.h>

int main(int argc, char* argv[], char* env[])
{
    int i = 0;
    printf("------Begin argv------\n");

    for(i = 0; i < argc; ++i)
    {
        printf("%s\n", argv[i]);
    }

    printf("------End argv------\n\n\n");

    /*
    printf("------Begin env------\n");

    for(i = 0;env[i] != NULL; ++i)
    {
         printf("%s\n", env[i]);
    }

    printf("------End env------\n\n\n");
    */
    return 0;
}
