/*
 * E89 Pedagogical & Technical Lab
 * project:     204
 * created on:  2023-05-26 - 11:08 +0200
 * 1st author:  dylan.le - dylan.le
 * description: system
 */
#include "stu.h"
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int stu_system(char *str)
{
    int statut;
    pid_t fork_res;

    fork_res = fork();
    if (fork_res == 0) {
        execl("/bin/sh", "sh", "-c", str, NULL);
    } else {
        waitpid (fork_res, &statut, 0);
        while (!WIFEXITED(statut)) {
            waitpid (fork_res, &statut, 0);
        }
    }
        return (WIFEXITED(statut));
}
