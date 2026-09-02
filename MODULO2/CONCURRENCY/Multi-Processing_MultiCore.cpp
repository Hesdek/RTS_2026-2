#include <iostream>
#include <unistd.h>     // For fork(), getpid()
#include <sys/wait.h>   // For wait()
#include <sched.h>      // Required for CPU affinity (sched_setaffinity)
#include <cmath>        // For a heavy math task

// A heavy function to keep a CPU core pinned at 100% load for a moment
void heavy_math_task(int child_id, int core_id) {
    std::cout << "[Child " << child_id << "] Target Core: " << core_id 
              << " | Actual PID: " << getpid() << " started execution." << std::endl;

    // Perform heavy mathematical operations to ensure the core is working in parallel
    double value = 1234.56;
    for (long i = 0; i < 500000000; ++i) {
        value = std::sin(value) * std::cos(value) + std::sqrt(value);
    }

    std::cout << "[Child " << child_id << "] Finished math task on Core " << core_id << "." << std::endl;
    _exit(0); // Exit safely to prevent child from looping
}

int main() {
    // 1. Find out how many physical/logical cores this machine actually has
    int total_cores = sysconf(_SC_NPROCESSORS_ONLN);
    std::cout << "\n[Parent] Detected " << total_cores << " available CPU cores.\n" << std::endl;

    // We will spawn up to the total number of cores available (max 4 for this example safety)
    int num_children = (total_cores > 4) ? 4 : total_cores;
    std::cout << "[Parent] Spawning " << num_children << " parallel processes...\n" << std::endl;

    for (int i = 0; i < num_children; ++i) {
        pid_t pid = fork();

        if (pid < 0) {
            std::cerr << "Fork failed!" << std::endl;
            return 1;
        } 
        else if (pid == 0) {
            // --- INSIDE CHILD PROCESS ---
            int target_core = i; // Map Child 0 to Core 0, Child 1 to Core 1, etc.

            // Define a CPU set structure
            cpu_set_t cpuset;
            CPU_ZERO(&cpuset);           // Clear the CPU set
            CPU_SET(target_core, &cpuset); // Add our specific target core to the set

            // Bind this specific child process to the target hardware core
            // 0 as the first argument applies the setting to the calling process (the child)
            if (sched_setaffinity(0, sizeof(cpu_set_t), &cpuset) < 0) {
                std::cerr << "Failed to set core affinity for Child " << i << std::endl;
            }

            // Run the heavy work on that specific core
            heavy_math_task(i, target_core);
        }
        else {
            // Inside Parent: Continue the loop to spawn the next child
            std::cout << "[Parent] Spawned Child " << i << " (PID: " << pid << ")" << std::endl;
        }
    }

    // --- PARENT CLEANUP ZONE ---
    std::cout << "\n[Parent] All children assigned to distinct cores. Waiting...\n" << std::endl;

    // Reap all children to prevent zombie processes
    for (int i = 0; i < num_children; ++i) {
        int status;
        pid_t finished_pid = wait(&status);
        std::cout << "[Parent] Process " << finished_pid << " safely reaped." << std::endl;
    }

    std::cout << "\n[Parent] Execution complete across multiple physical cores.\n" << std::endl;
    return 0;
}
