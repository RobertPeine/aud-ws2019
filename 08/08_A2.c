#include <stdlib.h>
#include <stdio.h>

struct node {int key; struct node *left, *right;};

int count(struct node *t, int k) {
    if (t == NULL) return 0;
    
    int c = 0;
    if (t->key == k) c = 1;
    
    return c + count(t->left, k) + count(t->right, k);
}

struct node *baz(struct node *s, struct node *t) {
    if (s == NULL) return NULL;
    
    struct node *result = malloc(sizeof(*result));
    result->key = count(t, s->key);
    result->left = baz(s->left, t);
    result->right = baz(s->right, t);
    
    return result;
}



struct node *cons(int key, struct node *l, struct node *r) {
    struct node *t = malloc(sizeof(*t));
    t->key = key;
    t->left = l;
    t->right = r;
    return t;
}

void printTree(struct node *t, int depth) {
    if (t) {
        for (int i = 0; i < depth; i++) printf("\t");
        printf("%d\n", t->key);
        printTree(t->left, depth+1);
        printTree(t->right, depth+1);
    }
}



int main() {
    struct node *s = cons(2, cons(3, cons(2, NULL, NULL), cons(4, NULL, NULL)), cons(1, NULL, NULL));
    struct node *t = cons(2, cons(2, NULL, NULL), cons(3, NULL, NULL));
    
    printf("\ns:\n");
    printTree(s, 0);
    
    printf("\nt:\n");
    printTree(t, 0);
    
    struct node *x = baz(s, t);
    printf("\nbaz(s, t):\n");
    printTree(x, 0);
    
    return 0;
}
