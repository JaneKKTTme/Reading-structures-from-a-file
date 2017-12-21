#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct package{
    char str[256];
	int integer;
	float fl;
} Pack;

void read_file(char *file_name){
	FILE *fp = fopen(file_name, "rb");
	int int_number;
	float fl_number;
	char str_number[256];

	if (fp == NULL)
        {
            printf("Error opening file");
            exit(1);
        }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    while(!feof(fp))
    {
        fread(&int_number, sizeof(int), 1, fp);
        fread(&str_number, sizeof(char)*256, 1, fp);
        fread(&fl_number, sizeof(float), 1, fp);
        printf("\ninteger number: %d\nString: %s\nFloat number: %f\n", int_number, str_number, fl_number);
    }
    printf("\nSize of file: %d Byte", file_size);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Rus");
    if (argc==2)
    {
        read_file(argv[1]);
    }
    else
    {
        printf("LOSER!");
    }
    return 0;
}
