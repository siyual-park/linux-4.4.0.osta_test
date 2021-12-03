#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

int main() {
    unsigned long max_mem;
    scanf("%ld", &max_mem);
    
    syscall(326, getpid(), max_mem);

    while (1) {
        unsigned long mem;
        printf("mem size: ");
        scanf("%ld", &mem);

        malloc(mem);
    }
    
    
    return 0;
}