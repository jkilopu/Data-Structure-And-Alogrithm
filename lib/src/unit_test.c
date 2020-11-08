#include <stdio.h>
#include <stdbool.h>
#include "unit_test.h"

static bool passed = true;

void check_int(const char *message, int expected, int actual)
{
    if (expected != actual)
    {
        fprintf(stderr, "*%s* expected: %d, actual: %d\n", message, expected, actual);
        passed = false;
    }
}

void check_unsigned(const char *message, unsigned int expected, unsigned int actual)
{
    if (expected != actual)
    {
        fprintf(stderr, "*%s* expected: %u, actual: %u\n", message, expected, actual);
        passed = false;
    }
}

void check_char(const char *message, char expected, char actual)
{
    if (expected != actual)
    {
        fprintf(stderr, "*%s* expected: %c, actual: %c\n", message, expected, actual);
        passed = false;
    }
}

void assert_true(const char *message, bool result)
{
    if (!result)
    {
        fprintf(stderr, "*%s* assert true failed", message);
        passed = false;
    }
}

void test_passed(const char *target)
{
    if (passed)
        fprintf(stderr, "--All *%s* test passed--\n", target);
    else
        fprintf(stderr, "--Test *%s* failed--\n", target);
}