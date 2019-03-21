/* Taken from http://www.jera.com/techinfo/jtns/jtn002.html */

/* Simple Macros for testing */
#define STR(x) (#x)
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do {printf("Ignore! %s\n", STR(test));  char *message = test(R); tests_run++; \
if (message) return message; } while (0)
extern int test_run;
