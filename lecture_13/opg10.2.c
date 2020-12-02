#include<stdio.h>
#include<stdlib.h>


int strcmp(const char*, const char*);

int main(void) {
    char *s1 = malloc(20);
    char *s2 = malloc(20);
    printf("Input two strings (max 20 characters: ");
    scanf("%s %s", s1, s2);
   
    char *res = (strcmp(s1,s2) ? "the same." : "not the same.");
    printf("%s and %s is %s\n", s1, s2, res);
    return 0;
}

int strcmp(const char *s1, const char *s2) {
    if (s1[0] != s2[0])
        return 0;    
    else if (s1[0] == '\0')
        return 1;
    else
        return strcmp(s1+1, s2+1);
}
