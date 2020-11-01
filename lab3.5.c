#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int c, p ,n;

void sigint_handler(int sig)

{
  printf("do not interrupt \n");
}

 int getPrime(int n) {

  for (c = 2; c <= n/2; c++)

  {

    if (n%c == 0)

    {

      return 0;

      break;

    }
  }


  if (c == n/2 + 1)

    return 1;
}


int main(int argc, char *argv[])

{

void sigint_handler(int sig);

signal (SIGINT, sigint_handler);
    int fd[2];
    int val = 0;

    pipe(fd);

    if (fork() == 0)

    {

        close(fd[0]);

		 printf("Enter a positive integer: ");

		scanf("%d", &n);

        val = getPrime(n);

        write(fd[1], &val, sizeof(val));

        printf("child(%d) send value: %d\n", getpid(), val);


        close(fd[1]);

    }

    else

    { 
	wait(NULL);
        close(fd[1]);

	 read(fd[0], &val, sizeof(val));

        printf("parent(%d) received value: %d\n", getpid(), val);

		printf("that integer is ");

		if (val==0)

			printf("not a prime number\n");

		else

			printf("prime number\n");

        close(fd[0]);

    }

    return 0;

}
