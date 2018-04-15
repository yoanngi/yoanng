#include "minishell.h"

int     ft_process(char *rep, char **cmd)
{
    pid_t   father;
    int     exec;

    father = fork();
    exec = -1;
    if (father < 0)
    {
        basic_error("Fork");
        exit(0);
    }
    else if (father == 0)
    {
        exec = execve(rep, cmd, NULL);
        exit(1);
    }
    else
        waitpid(father, &exec, 0);
    return (father);
}