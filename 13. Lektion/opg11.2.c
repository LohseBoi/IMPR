#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_palindrome_iter (char*);
int is_palindrome_rec (char*);
int get_string_size (const char*);

int main (void) {
    char *s; // = malloc(20);
    printf("Input a string (max 20 characters): ");
    scanf("%s", s);

    char *sc = malloc(get_string_size(s)+1);
    strcpy(sc, s);

    int itrRes = is_palindrome_iter(sc),
        recRes = is_palindrome_rec(sc);

    printf("Is %s a palindrome? Iterative says: %d | Recursive says: %d\n", s, itrRes, recRes);

    return 0;
}

int is_palindrome_iter (char *s) {
    int i = 0,
        j = get_string_size(s) - 1;
    for (; i < j; i++, j--) {
        if (s[i] != s[j])
            return 0;
    }
    return 1;
}

int is_palindrome_rec (char *s) {
    int last = get_string_size(s) - 1;

    if(s[0] != s[last])
        return 0;
    else if (last == 0 || last == 1)
        return 1;
    else {
        s[last] = '\0';
        return is_palindrome_rec(s+1);
        }

}

int get_string_size (const char *s) {
    int res = 0,
        i = 0;
    while (s[i] != '\0') {
        res++;
        i++;
    }
    
    return res;
}
