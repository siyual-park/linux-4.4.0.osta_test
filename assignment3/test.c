#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>

int main() {
    int pid;
    unsigned long max_mem;
    scanf("%d %ld\n", &pid, &max_mem);
    
    syscall(326, pid, max_mem);

    while (1) {
        unsigned long mem;
        printf("mem size: ");
        scanf("%ld\n", &mem);

        malloc(mem);
    }
    
    
    return 0;
}