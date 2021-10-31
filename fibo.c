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
    
    time_t start;
    time(&start);
    
    fibo(n);
    
    time_t end;
    time(&end);

    printf("diff time: %f\n", difftime(end, start));

    return 0;
}