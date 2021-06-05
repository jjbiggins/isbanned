#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <banned.h>

#define sorry_func_is_a_banned_function 1

void usage(int n) 
{
    fprintf(n < 2? stderr: stdout,
            "Usage: isbanned [-h --help] [-l --list] [<function>]\n");

    if (n < 2) exit(EXIT_FAILURE);
    fprintf(stdout,
            "\n"
            " ----------- Listing Options --------------\n"
            " --help            Help. Current Prints this Menu. So not much.\n"
            " --list            Lists all banned functions.\n"
            "\n"
            " -------------------------------------------\n"
            "\n");
    exit(0);
}

int check(char *func)
{

    if (BANNED(func)) {
        fprintf(stdout, "yes, function: %s is banned\n",func);
    } else {
        fprintf(stdout, "no, function: %s is NOT banned\n", func);
    }

    return 0;
}

int main(int argc, char *argv[]) 
{
    char *func;
    const char *help = "--help";
    const char *list = "--list";
    int helpi;
    int listi;
    int other;

    if (argc < 2) {
        usage(1);
    }

    func = argv[1];
    if (!strcmp(help, func)) {
        usage(2);
    } else if (!strcmp(list, func)) {
        printf("List option is undefined. We are working on that. Thank you.\n");
    } else {
        check(func);
    }
    
    exit(EXIT_SUCCESS);
}



