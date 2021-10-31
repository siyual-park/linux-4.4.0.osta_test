#include <stdio.h>
#include <time.h>

int fibo(int n) {
	if (n <= 1) {
        return n;
    }
    
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    
    time_t start = time(NULL);
    fibo(n);
    time_t end = time(NULL);

    printf("diff time: %f", difftime(start, end));

    return 0;
}