#include "interface.h"
#include <string.h>

int main()
{
struct node *root = getNode(); 

    char word[WORD];
    char ch;
    int i = 0;
    while (ch != '/0' && ch != ' ')
    {
        scanf(" %c", &ch);
        *(word + i) = ch;
        i++;
    }
    *(word + i + 1) = '\0';
    insert(root, word);
}