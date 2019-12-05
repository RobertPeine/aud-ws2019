#include <stdio.h>

int skalarProdukt(int a[], int m, int b[], int n) {
    int k = m;
    if (n < m) k = n;
    
    int sum = 0;
    for (int i = 0; i <= k - 1; i++) {
        sum += a[i] * b[i];
    }
    
    return sum;
}

int main() {
    int x[] = {1, 2, 3};
    int y[] = {4, 5, 6, 7};
    
    printf("%d\n", skalarProdukt(x, 3, y, 4));
    
    return 0;
}
