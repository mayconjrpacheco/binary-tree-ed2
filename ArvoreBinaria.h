typedef struct node* Tree;
typedef struct node* Node;

Tree* create_binary_tree();
Tree* insert_binary_tree(Tree* t, int data);
void free_node(struct node* n);
void free_tree(Tree* t);