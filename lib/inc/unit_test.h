#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

#include <stdbool.h>

void check_int(const char *message, int expected, int actual);
void check_unsigned(const char *message, unsigned int expected, unsigned int actual);
void check_char(const char *message, char expected, char actual);
void assert_true(const char *message, bool result);
void test_passed(const char *target);

#endif