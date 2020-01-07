#define NUM_LETTERS ((int)26) 
#define CHAR_TO_ARRAY(c) ((int)c - (int)'a')
#define WORD 30
#define LINE 256


void insert(struct node *root, const char *word);
struct node *getNode(void);
void printWords(struct node *root);