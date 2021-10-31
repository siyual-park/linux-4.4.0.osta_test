#include <stdio.h>
#include <sys/syscall.h>

int main() {
    int pid, operator;
    scanf("%d %d", &pid, &operator);
    
    if (operator == 0) {
        syscall(326, pid);
    } else {
        syscall(327, pid);
    }
    
    return 0;
}