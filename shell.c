#include "shell.h"
/**
 *  * main _ main function
 *   * @ac : number of arguments
 *    * @av : array of strings
 *     * @env : environment
 *      * Return : 0
 *       */
int main (int ac, char *av[], char **env)
{
	    (void) ac;
	    char *buffer = NULL;
	    char **argv = NULL;
	    int status = 0;
	    while(1)
	    {
		    buffer = get_line();
		    if (buffer == NULL) /* CTR + D*/
		    {
			    if (isatty(STDIN_FILENO) != 0) /*for interactive mode */
				    write(STDOUT_FILENO, "\n", 1);
			    return (status);
		    }
		    argv =  split(buffer);
		    if (!argv)
			    continue;
		    status = execute(argv, av);
	    }
}
