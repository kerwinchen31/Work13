#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

int stupid(){
  printf("hola mi pid es: %d\n", getpid());
}

static void sighandler(int signo){
  if (signo == SIGINT){
    int f = open("why.txt", O_WRONLY | O_CREAT, 0777);
    char a[] = "this program exited bc SIGINT\n";
    write(f, a, 31);
    close(f);
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("\nparent pid: %d\n",getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    stupid();
    sleep(1);
  }
  return 0;
}
