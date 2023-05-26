/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-05-21 - 14:25 +0200
 * 1st author:  dylan.le - dylan.le
 * description: include
 */

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <stdio.h>

#ifndef _STU_H_
#define _STU_H_

unsigned int stu_strlen(const char *str);
void to_each_their_turn(char *str);
int stu_system(char *str);

#endif /* stu.h */
