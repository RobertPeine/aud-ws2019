#include <stdlib.h>
#include <stdio.h>

struct element {int key; struct element *next;};
struct node {int key; struct node *left, *right;};

void append(struct element **lp, int n) {
    if (*lp != NULL) {
        append(&(*lp)->next, n);
    } else {
        *lp = malloc(sizeof(**lp));
        (*lp)->key = n;
        (*lp)->next = NULL;
    }
}

void treeToListRec(struct node *t, struct element **lp) {
    if (t == NULL) return;
    
    treeToListRec(t->left, lp);
    if (t->key % 2 == 0)
        append(lp, t->key);
    treeToListRec(t->right, lp);
}

struct element *treeToList(struct node *t) {
    struct element *l = NULL;
    treeToListRec(t, &l);
    return l;
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

void printList(struct element *l) {
    printf("[");
    while(l) {
        printf("%d", l->key);
        if(l->next) printf(", ");
        l = l->next;
    }
    printf("]\n");
}



int main() {
    struct node *t = cons(8, cons(6, cons(4, NULL, NULL), cons(7, NULL, NULL)), cons(10, cons(9, NULL, NULL), cons(12, NULL, NULL)));
    
    struct element *l = treeToList(t);
    printf("t:\n"); printTree(t, 0);
    printf("l: "); printList(l);
    
    return 0;
}
