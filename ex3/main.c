#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    char* curr = NULL;
    size_t sz;
    int i=0;
    int dictsize=0;
    FILE *fp;
    fp = fopen("words.txt", "r");
    while((getline(&curr, &sz, fp)) != -1)
    {
        dictsize++;
    }
    fclose(fp);
    char* words = malloc(dictsize*sizeof(char*));
    fp = fopen("words.txt", "r");
    while((getline(&curr, &sz, fp)) != -1)
    {
        words[i]=malloc((strlen(curr)+1)*sizeof(char));
        words[i] = strdup(curr);
        // words[i][strlen(curr)-1]='\0';
        i++;
    }
    // qsort(words, dictsize, sizeof(ItemType), myCompare);
    for(int i=0; i<dictsize; i++)
        printf("%s",words[i]);
    return 0;
}