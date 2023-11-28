#include <stdio.h>
#include <lib.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    message m;
    int group_nr;
    int my_pid;

    if (argc < 2) {
        printf("Group number for the proc must be provided. (A-1, B-2, C-3)\n");
        return 1;
    }

    group_nr = atoi(argv[1]);
    if(group_nr < 1 || group_nr > 3) {
        printf("Group number must be 0 - A, 1 - B or 2 - C.\n");
        return 1;
    }
    my_pid = getpid();

    m.m1_i1 = my_pid;
    m.m1_i2 = group_nr;
    _syscall(MM, SETGROUP, &m);

    while(1);

    return 0;
}
