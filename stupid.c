#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

DIR *d;
d = opendir("why.txt");

int stupid(){
  printf("hola mi pid es: %d\n", getpid());
}

static int sighandler(int signo){
  if (signo == SIGINT){
    printf("\nthis programs gonna exit bc SIGINT\n");
    exit(0);
  }
}

int main(){
  signal(SIGINT, sighandler);
  while(1234){
    stupid();
    sleep(1);
  }
}
