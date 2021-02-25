#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXARGS 100

int main(int argc, char *argv[])
{
	int num = argc - 1; // number of exc commands and child process being created
	int i;
	//char *args[MAXARGS] = {"/bin/date", "/bin/who", "/bin/ls", "/bin/ps", "/bin/uname", (char *)NULL}; // null terminated array of string
	int status;
	//printf("num = %d", num);
	//printf("How many n (1-5): ");
	//scanf("%d", &num);
	//printf("\n");

	pid_t pid_child[num]; // array to save child process to check whether child or parent

	for (i = 0; i < num; i++)
	{
		if ((pid_child[i] = fork()) == 0)
		{
			// ensure args not empty
			execlp(argv[i + 1], " ", (char *)NULL); // execute the command
			exit(0);
		}
		else if (pid_child[i] < 0) // failed
		{
			perror("fork");
			exit(1);
		}
	}

	// parent process

	for (i = 0; i < num; i++)
	{
		waitpid(pid_child[i], &status, 0);
		// wait one by one for the child to be done
		// once one is done print the following
		if (status == 0)
		{
			printf("\ncommand %s has completed successfully", argv[i + 1]);
		}
		else
		{
			printf("\ncommand %s has not completed successfully", argv[i + 1]);
		}
	}

	printf("\nAll have done, bye!\n");
}
