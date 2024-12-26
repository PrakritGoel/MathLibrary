#include "functions.h"
#include "mathlib.h"

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS "abcdefghijp:q:n:H"

/*
As can be clearly seen, this function follows along the same tracks as those of the given
implementation for the 3/8 rule. The necessary changes have been made to alter the process
to calculate the integral according to the 1/3 rule.
*/
double integrate(double (*f)(double), double a, double b, uint32_t n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (uint32_t i = 1; i < n; ++i) {
        if (i % 2 != 0) {
            sum += 4 * f(a + i * h);
        } else {
            sum += 2 * f(a + i * h);
        }
    }

    sum *= h * 1 / 3;
    // DECIMAL_DIG was learned via Stack Overflow.
    printf("%.*f\n", DECIMAL_DIG, sum);
    return sum;
}

/*
The usage prompt provides details on every possible command. The parameter here is a pointer
to a character in order to allow for passing the first argument of argv in the main function.
*/
void usage(char *exec_name) {
    printf("USAGE: %s -[abcdefghij] -p <low> -q <high> -n <num_partitions> -[H]\n", exec_name);
    printf("Calculate the definite integral of a function between the limits ");
    printf("low and high, using Simpson's 1/3 rule and num_partitions");
    printf(" number of partitions\n");
    printf("-a: Integrate sqrt(1 - x^4)\n");
    printf("-b: Integrate 1/log(x)\n");
    printf("-c: Integrate e^(-x^2)\n");
    printf("-d: Integrate sin(x^2)\n");
    printf("-e: Integrate cos(x^2)\n");
    printf("-f: Integrate log(log(x))\n");
    printf("-g: Integrate sin(x)/x\n");
    printf("-h: Integrate e^(-x)/x\n");
    printf("-i: Integrate e^e^x\n");
    printf("-j: Integrate sqrt(sin^2(x)+cos^2(x))\n");
    printf("-H: Print this message\n");
    printf("-p <low>: Set the lower limit for the integration\n");
    printf("-q <high>: Set the upper limit for the integration\n");
    printf("-n <num_partitions>: Set the number of partitions to be used.");
    printf(" This should be a positive even integer\n");
    return;
}

int main(int argc, char **argv) {
    int opt = 0;
    double (*fn)(double) = NULL;
    double low, high;
    uint32_t num_parts;

    // This variable is an array of pointers to characters.
    // For our purposes, it may be more apt to think of it as an array of character arrays.
    char *func_names[] = { "sqrt(1 - x^4)", "1/log(x)", "e^(-x^2)", "sin(x^2)", "cos(x^2)",
        "(log(log(x))", "sin(x)/x", "e^(-x)/x", "e^e^x", "sqrt(sin^2(x) + cos^2(x))" };
    // This variable will be used to point to a specific character array in the array above.
    uint8_t func_name_index;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        /*
	In the following cases a-j, the function pointer fn is assigned the address of the
	function in functions.c whose name corresponds to the case selected. Additionally,
	func_name_index is assigned the position of that corresponding function in func_names.
	*/
        case 'a':
            fn = &a;
            func_name_index = 0;
            break;
        case 'b':
            fn = &b;
            func_name_index = 1;
            break;
        case 'c':
            fn = &c;
            func_name_index = 2;
            break;
        case 'd':
            fn = &d;
            func_name_index = 3;
            break;
        case 'e':
            fn = &e;
            func_name_index = 4;
            break;
        case 'f':
            fn = &f;
            func_name_index = 5;
            break;
        case 'g':
            fn = &g;
            func_name_index = 6;
            break;
        case 'h':
            fn = &h;
            func_name_index = 7;
            break;
        case 'i':
            fn = &i;
            func_name_index = 8;
            break;
        case 'j':
            fn = &j;
            func_name_index = 9;
            break;
        case 'p': low = strtod(optarg, NULL); break;
        case 'q': high = strtod(optarg, NULL); break;
        case 'n': num_parts = (uint32_t) strtoul(optarg, NULL, 10); break;
        // If the user calls -H, that gets thrown in with the default.
        default: usage(argv[0]); return EXIT_FAILURE;
        }
    }

    printf("%s,%f,%f,%d\n", func_names[func_name_index], low, high, num_parts);

    for (uint32_t i = 2; i < (num_parts + 1); i += 2) {
        printf("%d,", i);
        integrate(fn, low, high, i);
    }
    return 0;
}
