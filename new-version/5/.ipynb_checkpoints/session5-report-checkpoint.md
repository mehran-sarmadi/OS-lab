Team Name: `[FILL HERE]`

Student Name of member 1: amin mansouri
Student No. of member 1: 966127035

- [x] Read Session Contents.

### Section 5.3.1

- [x] Write the Hello World! program
    - [x]
        c
        #include <stdio.h>
        #include <unistd.h>
        #include <sys/wait.h>
        
        int main() {
        
            int fd[2];
        
            int pipe_res = pipe(fd);
            if (pipe_res == -1) {
                printf("Error: Pipe");
                return 1;
            }
        
            int fork_res = fork();
            if (fork_res > 0) { // Parent process
                close(fd[0]); // No need to read
                char message[] = "Hello World!";
                int write_res = write(fd[1], message, sizeof(message));
                if (write_res == -1) {
                    printf("Error: Write");
                    return 1;
                } else {
                    printf("Parent process sent message: %s\n", message);
                }
                close(fd[1]); // After successful write
                wait(NULL); // Waiting for child process to terminate (optional)
            } else if (fork_res == 0) { // Child process
                close(fd[1]); // No need to write
                char buffer[20];
                int read_res = read(fd[0], buffer, sizeof(buffer));
                if (read_res == -1) {
                    printf("Error: Read");
                    return 1;
                } else {
                    printf("Child process received message: %s\n", buffer);
                }
                close(fd[0]); // After successful read
            } else {
                printf("Error: Fork");
                return 1;
            }
            return 0;
        }
        
        ![](photo_1_2023-09-05_14-39-08.jpg)

    
- [x] Write the ls to wc program
    - [x]
        c
        #include <stdio.h>
        #include <unistd.h>
        #include <sys/wait.h>
        
        int main() {
        
            int fd[2];
        
            int pipe_res = pipe(fd);
            if (pipe_res == -1) {
                printf("Error: Pipe");
                return 1;
            }
        
            int fork_res = fork();
            if (fork_res > 0) { // Parent process
                close(fd[0]); // No need to read
                dup2(fd[1], 1);
                close(fd[1]); // After successful write
                execlp("ls", "ls", NULL);
                wait(NULL); // Waiting for child process to terminate (optional)
            } else if (fork_res == 0) { // Child process
                close(fd[1]); // No need to write
                dup2(fd[0], 0);
                close(fd[0]); // After successful read
                execlp("wc", "wc", NULL);
            } else {
                printf("Error: Fork");
                return 1;
            }
            return 0;
        }
        
        ![](photo_2_2023-09-05_14-39-08.jpg)


- [x] Investigate how to have a bi-direction pipe
    - [x] A naive method would be declaring two one-way pipes and simulate a two-way pipe using them. Each of the parent and the child processes uses one of these two pipes to write data to and uses the other one to read data from.
    However, a more advanced way to achieve bi-directional pipe is to use FIFO. FIFO is a full duplex inter process communication. It means that both processes can communicate with each other simultaneously. In order to create a FIFO in Linux, we can use the mkfifo command. It is also good to note that two processes from two different operating systems can also be connected to each other across the network by using FIFO.
    

### Section 5.3.2
- [x] Describe the usecase of different signals:
    1. [x] The SIGINT signal is used to interrupt a running process and request it to terminate itself in a reliable way, causing no faults for system. This signal is usually triggered by using the kill command or pressing Ctrl+C.
    1. [x] The SIGHUP signal, or Signal Hang Up is sent to a process to inform it that the user has disconnected the communication channel, by logging out or closing the terminal window. To clarify, when a parent process terminates, all its child processes become orphaned. So, the SIGHUP signal is sent to these orphaned processes to ask them to terminate too, considering some specific actions like saving the unsaved data or reloading the configuration files.
    1. [x] The SIGSTOP signal is sent to a process to temporarily pause it. The process cannot ignore or handle this signal and it is suspended, until it receives the SIGCONT signal.
    1. [x] The SIGCONT signal is used to resume a previously paused process in order to continue its execution from where it was paused by a SIGSTOP or SIGTSTP signal.
    1. [x] The SIGKILL signal is sent to a running process to immediately terminate it. This signal is not ignorable and it will force the process termination regardless of its current operational state.

- [x] Describe SIGALRM
    1. [x] The SIGALRM signal is used to inform a process that a previously set timer has expired. It is primarily used to implement timeouts in time-sensitive operations like in network applications. When a process receives this signal, It could reset timer, handle errors, perform some cleanups, etc. It is also good to note that process termination is the default behavior to this signal. But, this behavior can be overridden to handle the signal for other purposes.

- [x] Investigate the given code
    1. [x] The command alarm(5); sets a 5-second alarm. After printing Looping forever . . ., the program gets stuck in an infinite loop. After the 5 seconds passed, the process gets a SIGALRM signal to terminate itself immediately. This prevents the second printf command being executed.
    1. [x] ![image](photo_3_2023-09-05_14-39-08.jpg)

- [x] Modify the given program by handling SIGALRM
    1. [x]
        c
        #include <stdio.h>
        #include <unistd.h>
        #include <signal.h>
        
        void handler(int signum) {
            if (signum == SIGALRM) {
                printf("SIGALRM signal received\n");
            }
        }
        
        int main() {
            signal(SIGALRM, handler); 
            alarm(5);
            printf("Looping forever . . . \n");
            pause();
            printf("This line should never be executed\n");
            return 0;
        }
        
        ![](photo_4_2023-09-05_14-39-08.jpg)


- [x] Write a program that handles Ctrl + C
    1. [x]
        c
        #include <stdio.h>
        #include <stdlib.h>
        #include <unistd.h>
        #include <signal.h>
        
        int n_interruptions = 0;
        
        void handler(int signum) {
            if (signum == SIGINT) {
                n_interruptions += 1;
                printf("\nSIGINT signal received (%d)\n", n_interruptions);
                if (n_interruptions == 2) {
                    printf("Exiting...\n");
                    exit(0);
                }
            }
        }
        
        int main() {
            signal(SIGINT, handler); 
            printf("Looping forever . . . \n");
            while(1);
            return 0;
        }
        
        ![](photo_5_2023-09-05_14-39-08.jpg)