
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *input;
    input = fopen("input.txt","r");
    int size = 0;
    char tmp;
    while ((tmp = fgetc(input))!=EOF)
        size++;
    fclose(input);
    input = fopen("input.txt","r");
    tmp = fgetc(input);
    char *Archieved;
    Archieved = malloc(size*sizeof(char));
    char pretmp = tmp;
    int counter = 1,archPos = 0;
    while (1)
    {
        if (tmp==EOF)
            break;
        tmp = fgetc(input);
        if (tmp == pretmp)
        {
            counter++;
        }
        else
        {
            if (counter == 1)
            {
                Archieved[archPos] = pretmp;
            }
            else if(counter == 2)
            {
                Archieved[archPos] = pretmp;
                Archieved[archPos+1] = pretmp;
                archPos++;
            }
            else
            {
                Archieved[archPos] = counter+'0';
                Archieved[archPos+1] = pretmp;
                archPos++;
            }
            archPos++;
            pretmp = tmp;
            counter = 1;
        }
    }
    FILE * output = fopen("output.txt","w");
    fprintf(output,"%s",Archieved);
    fclose(output);
    fclose(input);
    return 0;
}