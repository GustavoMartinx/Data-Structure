#include <stdio.h>
#include "tablehash_oa.h"

int main(int argc, char** argv) {
    HTOA* t;
    t = HTOA_create(10);

    HTOA_insert(t, 10, 10);
    HTOA_insert(t, 21, 21);
    HTOA_insert(t, 44, 44);
    HTOA_insert(t, 32, 32);
    HTOA_insert(t, 12, 12);
    HTOA_insert(t, 37, 37);
    HTOA_insert(t, 43, 43);
    printf("-------------------------\n");

    for(int i = 0; i < t->m; i++) {
        const char s = t->HT[i].state == S_BUSY ? 'O'
            : (t->HT[i].state == S_FREE ? 'L' : 'A');
        
        printf("%d: %d, %c\n", i, t->HT[i].key, s);
    }

    printf("3?  %d\n", HTOA_search(t, 3));
    printf("10? %d\n", HTOA_search(t, 10));
    printf("7?  %d\n", HTOA_search(t, 7));
    printf("37? %d\n", HTOA_search(t, 37));
    printf("43? %d\n", HTOA_search(t, 43));
    printf("44? %d\n", HTOA_search(t, 44));
    printf("-------------------------\n");

    printf("Removing 44...\n");
    HTOA_remove(t, 44);
    printf("-------------------------\n");

    printf("44? %d\n", HTOA_search(t, 44));
    printf("43? %d\n", HTOA_search(t, 43));
    printf("-------------------------\n");

}