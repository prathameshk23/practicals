#include <stdio.h>
#include <unistd.h> // for fork(), getpid(), getppid()

int main() {
  pid_t pid; // datatype variable; used to store process id’s

  // Create a new process // system calls
  pid = fork();

  if (pid < 0) {
    // If fork() returns a negative value, creation failed
    printf("Fork failed!\n");
    return 1;
  } else if (pid == 0) {
    // This block runs in the CHILD process
    printf("Child Process:\n");
    printf("  Child PID: %d\n", getpid());   // ID of child process
    printf("  Parent PID: %d\n", getppid()); // Parent's process ID
  } else {
    // This block runs in the PARENT process
    printf("Parent Process:\n");
    printf("  Parent PID: %d\n", getpid()); // ID of parent process
    printf("  Child PID: %d\n", pid); // ID of the child returned by fork()
  }
  return 0;
}
