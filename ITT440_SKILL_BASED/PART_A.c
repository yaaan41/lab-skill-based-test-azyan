#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void sigint_Handler(int signal){
  printf("Received SIGINT signal.\n");
}

int main() {
  int parent_ID, s;
  struct timespec sleep_time;
  for (s = 0; s < 3; s++) {
    parent_ID = fork();
    if (parent_ID == 0) {
      // Child process
      signal(SIGINT, sigint_Handler);
      sleep_time.tv_sec = 1;
      sleep_time.tv_nsec = 0;
      nanosleep(&sleep_time, NULL);
      printf("Child %d: The process is interrupted\n", s);
      while (1);
    }
  }

  // This is the parent process
  printf("Parent: I have created 3 child processes.\n");
  while (1);
  return 0;
}


