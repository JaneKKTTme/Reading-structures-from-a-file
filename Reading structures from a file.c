#include <stdio.h>
#include <stdlib.h>

struct package
{
    int integer;
    char string[255];
    float number;
};

int load(char* s)
{
    FILE *fp;
    char *c;
    int *size;
    int k, i, n, m = sizeof(int);

    size = (int *)malloc(m);

    if ((fp = fopen(s, "r")) == NULL)
    {
        perror("File did not opened");
    }

    c = (char *)size;
    while (m>0)
    {
        i = getc(fp);
        if (i==EOF) break;
        *c=i;
        c++;
        m--;
    }

    n = *size;

    struct package *allsize;
    allsize = (struct package *)malloc(n *sizeof(struct package));
    c = (char *)allsize;

    for ( k=0; k<n; k++ )
    {
        printf("%4d %256s %4.2f", (allsize+k)->integer, (allsize+k)->string, (allsize+k)->number);
    }

    free(size);
    free(allsize);
    fclose(fp);

    return 0;
}

int main(int argc, char* argv[])
{
    if ( argc==2 )
    {

        load(argv[2]);
    }
    else
    {
        printf("Please, tell me the name of file");
        if ( argc==2 )
        {

            load(argv[2]);
        }
        else
        {
        printf("Loser!");
        }
    }

    return 0;
}
