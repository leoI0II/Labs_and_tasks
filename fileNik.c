#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{   
    // char* name = (char*) malloc (40);

    // fgets(name, 40, stdin);
    // name[strlen(name) - 1] = '\0';

    // FILE* file = fopen(name, "r");
    // FILE* res = fopen("result.txt", "w");

    // char str[40];

    // while (fgets(str, 40, file) != NULL)
    //     fputs(str, res);

    char *_name = malloc (2*sizeof(char));

    char ch; int i = 0;

    while ((ch = getchar()) != '\n')
    {
        _name[i] = ch;
        ++i;
        _name = realloc(_name, i+1);
    }
    _name[i+1] = '\0';

    printf("%s\n", _name);
        

    // fclose(file);
    // free(name);


    return 0;
}