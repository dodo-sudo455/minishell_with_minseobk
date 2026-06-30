#include <readline/readline.h>
#include <stdbool.h>
#include "main.h"

int main(void)
{
    char    *input;
    t_lst	cmdlst;
    t_lst   exelst;

    while (true)
    {
        input = prom();
        cmdlst = parse(input);
		exelst = prep(cmdlst);
        exec(exelst);
    }
}
