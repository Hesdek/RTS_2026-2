#include <iostream>
#include <unistd.h>    // Required for fork() and getpid()
#include <sys/wait.h>  // Required for wait()

int main() {
    std::cout << "\nStarting main process. PID: " << getpid() << "\n" << std::endl;

    // Duplicate the process
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    } 
    else if (pid == 0) {
        // Child Process execution path
        std::cout << "[Child] I am the child process. PID: " << getpid() 
                  << ", Parent PID: " << getppid() << std::endl;
        
        // Child performs its specific task here
        std::cout << "[Child] Exiting task..." << "\n" << std::endl;
        _exit(0); // Use _exit in child to avoid flushing parent I/O streams
    } 
    else {
        // Parent Process execution path
        std::cout << "[Parent] I am the parent process. PID: " << getpid() 
                  << ", Created Child PID: " << pid << "\n" << std::endl;
        
        // Wait for the child to finish to prevent a zombie process
        int status;
        waitpid(pid, &status, 0); 
        
        std::cout << "[Parent] Child process has finished. Parent exiting." << "\n" << std::endl;
    }

    return 0;
}
