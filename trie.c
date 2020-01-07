#include <ctype.h>
#include <stdio.h>
#include "interface.h"

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;
typedef struct node
{
    char letter;
    boolean endWord;
    char string[WORD];
    long unsigned int count;
    struct node *children[NUM_LETTERS];
} node;

// Returns new trie node (initialized to NULLs)
struct node *getNode(void)
{
    struct node *newNode = NULL;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode)
    {
        int i;

        newNode->endWord = false;

        for (i = 0; i < NUM_LETTERS; i++)
            newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(struct node *root, const char *word)
{
    int i;
    int length = strlen(word);
    int index;
    char c;
    char temp[WORD];

    struct node *current = root;

    for (i = 0; i < length; i++)
    {
        c = tolower(word[i]);
        index = CHAR_TO_ARRAY(c);
        if (!current->children[index])
            current->children[index] = getNode();
temp = current->string;
        current = current->children[index];
    
        //set the letter of the child.
        current->letter = c;
        current->string = temp+current->string;
    }

    // mark last node as leaf
    current->endWord = true;
    current->count++;
}

}