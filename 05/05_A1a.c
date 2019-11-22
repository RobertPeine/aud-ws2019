#include <stdio.h>

int main() {
    int a, b;
    
    printf("Zahl a eingeben: ");
    scanf("%d", &a);
    
    printf("Zahl b eingeben: ");
    scanf("%d", &b);
    
    if (a > b) {
        printf("%d", a);
    } else {
        printf("%d", b);
    }
    
    return 0;
}
