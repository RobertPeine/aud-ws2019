#include <stdio.h>

int fib_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_tail_helper(int n, int p, int q) {
    if (n == 0) return p;
    
    return fib_tail_helper(n - 1, q, p + q);
}

int fib_tail(int n) {
    return fib_tail_helper(n, 0, 1);
}

int fib_it(int n) {
    int p = 0, q = 1, result;
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    for (int i = 2; i <= n; ++i) {
        result = p + q;
        p = q;
        q = result;
    }
    
    return result;
}

int main() {
    int x = 4;
    
    printf("fib_rec(%d) = %d\n", x, fib_rec(x));
    printf("fib_tail(%d) = %d\n", x, fib_tail(x));
    printf("fib_it(%d) = %d\n", x, fib_it(x));
    
    return 0;
}
