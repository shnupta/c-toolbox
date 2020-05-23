#include "test.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int test_int(const int got, const int expected, const char* name) {

	print_result(got == expected, "(int)  %d == %d  (?)  %s", got, expected, name);	

	return got == expected;
}

int test_bool(const int got, const char* name) {

	print_result(got, "(bool)  got = %d  (?)  %s", got, name);	

	return got;
}


int test_char(const char got, const char expected, const char* name) {

	print_result(got == expected, "(char)  %c == %c  (?)  %s", got, expected, name);	

	return got == expected;
}


int test_string(const char* got, const char* expected, const char* name) {

	print_result(got == expected, "(string)  %s == %s  (?)  %s", got, expected, name);	

	return got == expected;
}


void print_result(int passed, const char* fmt, ...) {
	fprintf(stdout, "[\x1b[93m TEST \x1b[0m]  -  ");
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
	fprintf(stdout, "  -  ");
	fprintf(stdout, passed ? "\x1b[92mPASS\x1b[0m" : "\x1b[91mFAIL\x1b[0m");
	fprintf(stdout, "\n");
	fflush(stdout);
}

void run_test_suite(const int (*tests[])(void), const int count, const char* filename) {
	char* buffer = (char*) calloc(MAX_TEST_STRING_LENGTH, sizeof(char));
	char* passed = (char*) calloc(count * MAX_TEST_STRING_LENGTH, sizeof(char));
	char* failed = (char*) calloc(count * MAX_TEST_STRING_LENGTH, sizeof(char));

	int p_count = 0;
	int f_count = 0;

	printf("Running test suite - %s\n", filename);

	freopen("/dev/null", "a", stdout);
	setbuf(stdout, buffer);

	for (int i = 0; i < count; i++) {
		memset(buffer, 0, MAX_TEST_STRING_LENGTH * sizeof(char));
		if (tests[i]()) {
			strcat(passed, buffer);
			p_count++;
		} else {
			strcat(failed, buffer);
			f_count++;
		}
	}	

	freopen ("/dev/tty", "a", stdout);

	printf("%d / %d tests passed\n", p_count, count);
	printf("\n");
	printf("Passing tests: (%d)\n%s", p_count, passed);
	printf("\n");
	printf("Failing tests: (%d)\n%s", f_count, failed);

	free(buffer);
	free(passed);
	free(failed);
}
