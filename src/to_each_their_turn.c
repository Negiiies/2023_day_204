/*
 * E89 Pedagogical & Technical Lab
 * project:     204
 * created on:  2023-05-26 - 09:42 +0200
 * 1st author:  dylan.le - dylan.le
 * description: fork
 */

#include "stu.h"
#include <unistd.h>
#include <sys/wait.h>
void to_each_their_turn(char *str)
{
    pid_t fork_res;
    int statut;

    fork_res = fork();
    if (fork_res == -1) {
        write(1,"ERROR", 5);
        return;
    }
    if (fork_res == 0) {
        write(1,"\nGosse", 6);
        write(1, str, stu_strlen(str));
        write (1, "\n", 1);
    } else {
        waitpid (fork_res, &statut, 0);
        write(1,"\nParent", 7);
        write(1, str, stu_strlen(str));
        write (1, "\n", 1);
    }
}
