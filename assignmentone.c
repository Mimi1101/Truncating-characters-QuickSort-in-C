#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 9

// Sample comparison function for qsort():
int cmp(const void *p1, const void *p2)
{
    const char *str1 = *(const char **)p1;
    const char *str2 = *(const char **)p2;
    return strcmp(str1, str2);
}

int main(int argc, char *argv[])
{
    char **stringArray = NULL;
    int i, n;
    char buf[BUFSIZE];
    int maximum_length = 8;

    printf("Enter # of strings:");
    fflush(stdout);
    fgets(buf, BUFSIZE, stdin);
    n = atoi(buf);
    stringArray = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        printf("Enter string # %d.\n", i + 1);
        fgets(buf, BUFSIZE, stdin);
        buf[strcspn(buf, "\n")] = '\0'; // Remove the newline character

        if (strlen(buf) > maximum_length) {
            buf[maximum_length] = '\0'; // Truncate to 512 characters
        }

        stringArray[i] = strdup(buf);
        fflush(stdin);
    }

    qsort(stringArray, n, sizeof(char *), cmp);

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", stringArray[i]);
    }

    // Free allocated memory
    //for (i = 0; i < n; i++) {
    // free(stringArray[i]);
    //}
    free(stringArray);

    return 0;
}