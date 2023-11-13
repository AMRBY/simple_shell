#include "shell.h"

char *get_line(void)
{

    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t n_char = 0;

    if (isatty(STDIN_FILENO) != 0)
    write(STDOUT_FILENO, "$ ", 2);

    n_char = getline(&buffer, &buffer_size, stdin)
        if (n_char == -1) /* if I reached EOF*/
        {
            free(buffer);
            return (NULL);
        }


    return (buffer);

}
char **split(char *buffer)
{
    int i = 0;
    char *token = NULL;
    char **argv = NULL;
    
    if (!buffer)
    return (NULL);
    token = strtok(buffer, " \t\n");
    argv = malloc(sizeof(char *) * 1024);
    if (!argv)
    {
        free(buffer);
        
        return (NULL);
    }
    while(token)
    {
        argv[i] = token;
        token = strtok(NULL, " \t\n");
        i++;
    }
    free(buffer);
    argv[i] = NULL;
    return (argv);


}
int execute(char **argv, char **av)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0)
    {
        if (execve(argv[0], argv, environ) == -1)
            {
                perror(av[0]);
                free(argv);
                exit(0);
            }
    }
    else
        {
            waitpid(argv, &status, 0);
            free(argv);

        }
        return (WEXITSTATUS(status))
}
