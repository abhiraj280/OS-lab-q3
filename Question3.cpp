#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int32_t main()
{
    int fd[2];
	char *buff;

	pipe(fd);

    pid_t p;
    p = fork();
    switch(p){

        case 0:
		    close(fd[1]);

		    read(fd[0], &buff, 19);
		    printf("Child  Process ID = %d\n", getpid());
            printf("Message received = %s\n\n", buff);
		    close(fd[0]);
            break;

        default:
		    close(fd[0]);
		    buff = "end term practical";
		    write(fd[1], &buff, 19);
		    printf("Parent Process ID = %d\n", getpid(), buff);
            printf("Message sent \n\n");
            close(fd[1]);
    }

    return 0;
}
