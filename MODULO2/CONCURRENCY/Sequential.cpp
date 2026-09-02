#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "\nMain: starting\n\n";

    for (int i = 1; i <= 10; ++i)
    {
        std::cout << "Main: " << i << "\n";
        usleep(100000);
    }

    std::cout << "\nMain: finished\n\n";

    return 0;
}