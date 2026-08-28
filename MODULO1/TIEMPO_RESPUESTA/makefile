CC = gcc
CFLAGS = -pg -O0 -Wall -Wextra

TARGETS = application task1 task2 task3

all: $(TARGETS)

# Main application
application: main.c task1.c task2.c task3.c \
             task1.h task2.h task3.h
	$(CC) $(CFLAGS) main.c task1.c task2.c task3.c -o application

# Task 1
task1: task1.c task1_main.c task1.h
	$(CC) $(CFLAGS) task1.c task1_main.c -o task1

# Task 2
task2: task2.c task2_main.c task2.h
	$(CC) $(CFLAGS) task2.c task2_main.c -o task2

# Task 3
task3: task3.c task3_main.c task3.h
	$(CC) $(CFLAGS) task3.c task3_main.c -o task3

# Remove executables and profiling data
clean:
	rm -f $(TARGETS) gmon.out