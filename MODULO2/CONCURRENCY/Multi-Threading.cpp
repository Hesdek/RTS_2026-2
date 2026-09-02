#include <iostream>
#include <thread>
#include <unistd.h>

void worker()
{
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << "Worker thread prints: " << i << "\n";
        usleep(100000);
    }
}

int main()
{
    std::cout << "\nMain: starting\n\n";

    std::thread t(worker);

    for (int i = 1; i <= 10; ++i)
    {
        std::cout << "Main: " << i << "\n";
        usleep(100000);
    }

    t.join();

    std::cout << "\nMain: finished\n\n";

    return 0;
}