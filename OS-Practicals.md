
## Viva prep
### What is os and its uses?
An operating system (OS) is a software program that manages computer hardware and software resources, provides a user interface, and facilitates communication between software applications and hardware devices. Its main uses include resource management, process management, memory management, file management, user interface, and security.
### Difference between multi processor and multicore
A multi-processor system has multiple physical processors, each with its own set of resources, while a multicore system has a single physical processor with multiple cores, which are independent processing units within the same chip. In other words, a multi-processor system has multiple CPUs, while a multicore system has a single CPU with multiple cores.
### How to solve simple synchronization problems
Use semaphores and mutex
### Difference between multiprocessor and multi threading
Multiprocessing involves using multiple processors or cores to execute multiple tasks simultaneously, while multithreading involves dividing a single task into smaller subtasks that can be executed concurrently within a single processor or core. In other words, multiprocessing is about parallelism at the hardware level, while multithreading is about parallelism at the software level.
Each process require a separate core while all threads can be ran on a single core.
### Belady's anomaly
Belady’s anomaly is the phenomenon where increasing the number of page frames in a page replacement algorithm can lead to an increase in the number of page faults. It occurs when the algorithm does not follow the optimal page replacement strategy, which is to replace the page that will not be used for the longest time in the future. 
It is an anomaly because you expect faults to go down when you increase number of page frames but the opposite happens.
### Deadlock detection methods
1.  Resource allocation graph: The resource allocation graph is a graphical representation of the resources used by each process and their dependencies. It is used to detect deadlocks by looking for cycles in the graph, which indicate situations where resources are blocked by other resources.
2.  Wait-for graph: The wait-for graph is similar to the resource allocation graph, but it focuses on the relationships between processes instead of resources. It is used to detect deadlocks by looking for cycles in the graph, which indicate situations where processes are waiting for each other to release resources.
3.  Banker's algorithm: The Banker's algorithm is a resource allocation and deadlock avoidance algorithm that is used to manage resource allocation in a way that prevents deadlocks from occurring. It works by checking if a resource request from a process can be granted without leading to a deadlock.
4.  Timeout-based detection: Timeout-based detection involves setting a timer for each resource request and releasing the resource if the timer expires. This method is useful for detecting deadlocks in distributed systems, where communication delays can lead to deadlocks.
5.  Process termination: In some cases, the only way to resolve a deadlock is to terminate one or more processes. Deadlock detection can be used to identify which processes need to be terminated to resolve the deadlock.
### Thrashing
A state where due to lack of virtual memory, the same pages needs to be loaded repeatedly, causing a lot of time and throughput wastage.
**_Thrashing_** is when the page fault and swapping happens very frequently at a higher rate, and then the operating system has to spend more time swapping these pages. This state in the operating system is known as thrashing. Because of thrashing, the CPU utilization is going to be reduced or negligible.
### What is paging and why
Paging is a memory management technique used in computer operating systems to efficiently manage the memory resources of a system. It allows the operating system to divide the physical memory (RAM) into fixed-sized blocks called "pages" and the logical memory (address space) of a process into corresponding fixed-sized blocks called "page frames." The size of a page is typically a power of 2, such as 4 KB.

The primary goal of paging is to provide a mechanism for virtual memory, which allows processes to utilize more memory than physically available. It enables the illusion of a larger address space by utilizing secondary storage devices like hard disks as an extension of the main memory. The concept of virtual memory allows the operating system to swap pages between RAM and the disk, transparently to the executing processes.
### What is TLB, where is it stored
TLB is a hardware cache that stores frequently accessed virtual-to-physical address translations, reducing the time required for memory access. It is typically located in the memory management unit (MMU) and plays a crucial role in accelerating virtual memory translations in modern computer systems.
### Disk Scheduling algos
1.  First-Come-First-Serve (FCFS): This is a simple disk scheduling algorithm where requests are serviced in the order in which they arrive. Requests are added to the end of the queue and processed in a First-Come-First-Serve manner. While this algorithm is easy to implement, it may lead to long wait times for requests that are located far away from the disk's current position.
2.  SCAN: In the SCAN algorithm, the disk arm moves in a particular direction and services all the requests in that direction until it reaches the end of the disk. Then, it reverses direction and services all the requests in the other direction until it reaches the other end of the disk. This algorithm minimizes the average wait time for requests, but may lead to some requests waiting for a long time if they are located at the end of the disk.
3.  C-SCAN: The C-SCAN algorithm is similar to SCAN, but the disk arm only moves in one direction and wraps around to the other end of the disk once it reaches the end. This ensures that all requests are serviced in a round-robin fashion, with no requests waiting for a long time.
4.  LOOK: The LOOK algorithm is similar to SCAN, but the disk arm only moves until it reaches the last request in the current direction. It then reverses direction and services all the requests in the other direction until it reaches the last request in that direction. This algorithm reduces the average wait time for requests compared to SCAN, but may still lead to some requests waiting for a long time if they are located at the end of the disk.
5.  C-LOOK: The C-LOOK algorithm is similar to C-SCAN, but the disk arm only moves until it reaches the last request in the current direction. It then wraps around to the other end of the disk and services all the requests in that direction until it reaches the last request in that direction. This algorithm ensures that all requests are serviced in a round-robin fashion, with no requests waiting for a long time.
### Segmentation
Segmentation is a memory management technique that divides the logical address space of a process into multiple segments, where each segment represents a logical unit of the program such as a function or a data structure. Each segment is assigned a unique identifier and can be of variable size. Segmentation allows for flexibility in memory allocation, as each segment can be allocated and deallocated independently, and it enables protection of segments from unauthorized access.
### Frames
Frames, on the other hand, are fixed-size blocks of physical memory. When a process is loaded into memory, the logical address space is divided into fixed-size chunks called pages, which are then mapped to frames in physical memory. The mapping is typically maintained in a page table, which is used by the memory management unit (MMU) to translate logical addresses to physical addresses. Frames are used to divide physical memory into manageable chunks and to enable efficient use of physical memory resources.

### Segments vs Pages
- Segmentation divides the logical address space of a process into logical units called segments, whereas paging divides the logical address space into fixed-size chunks called pages.
- Segments can be of variable size, whereas pages are of fixed size.

### Dining philosopher problem
The Dining Philosophers Problem is a classic computer science problem used to illustrate issues that can arise in concurrent programming and resource allocation. The problem is based on a scenario in which several philosophers are seated at a circular table, with a bowl of rice and chopsticks in front of each philosopher. The philosophers alternate between thinking and eating, but they must use the chopsticks to eat, and each philosopher can only use the chopsticks on their left and right. The goal is to design a protocol that allows each philosopher to successfully eat without causing a deadlock or starvation.

The problem arises because the philosophers need two chopsticks to eat, and if all the philosophers pick up their left chopstick at the same time, they will deadlock and starve, as each philosopher is waiting for their right chopstick to be available. On the other hand, if a philosopher picks up one chopstick, eats, and then puts the chopstick down, they may monopolize the chopsticks, preventing the other philosophers from eating and causing starvation.
### Evolution of OS
1.  Serial Processing: In a serial processing system, only one task is processed at a time. Once that task is complete, the next task is processed. This type of system is simple and easy to understand, but it is not efficient since it can lead to idle time for the processor when there are no tasks to process.
2.  Simple Batch Systems: A simple batch system allows multiple jobs to be submitted for processing as a batch. The jobs are collected into a queue, and the system processes them one at a time, without any user interaction. Once a job completes, the output is printed and the next job is processed. This type of system is more efficient than serial processing since it can use the idle time of the processor, but it does not provide any interactivity.
3.  Multiprogrammed Batch Systems: A multiprogrammed batch system is similar to a simple batch system, but it allows multiple jobs to be processed simultaneously. In this type of system, the processor switches between jobs to keep it busy and maximize throughput. However, there is still no user interaction, and jobs are processed in the order they are received.
4.  Time Sharing Systems: A time sharing system allows multiple users to interact with the system simultaneously, with each user receiving a portion of the processor's time. The processor switches rapidly between tasks to give the illusion of simultaneous processing. This type of system provides interactive response times and is used for tasks that require immediate user input, such as text editing or command-line interfaces.
### Preemptive vs Non preemptive
Stopping the currently running process to run another process is preemptive.
### What is chmod
The chmod command in Linux is a command-line utility that is used to change the permissions of files and directories. The name "chmod" stands for "change mode".
The chmod command uses a numeric or symbolic notation to specify the permissions that should be granted or revoked. The permissions are typically specified for the owner of the file or directory, members of the group that the file or directory belongs to, and all other users. The permissions that can be granted or revoked include read, write, and execute permissions.
The numeric notation used by chmod represents the permissions as a three-digit octal number. The first digit specifies the permissions for the owner, the second digit specifies the permissions for the group, and the third digit specifies the permissions for all other users. Each digit is a sum of three binary digits, where the values of the digits are 4 for read, 2 for write, and 1 for execute permissions.
The symbolic notation used by chmod represents the permissions as a combination of letters and symbols that specify the permissions for the owner, group, and others. The symbols include "+", "-", and "=" which are used to add, remove, or set permissions respectively. The letters used in symbolic notation include "r" for read, "w" for write, and "x" for execute permissions.
Examples of using the chmod command include:
-   chmod 644 myfile.txt (sets read and write permissions for the owner, and read-only permissions for group and others)
-   chmod +x myscript.sh (adds execute permissions to a script file)
-   chmod -w myfile.txt (removes write permissions from a file)
### What is principle of locality
The principle of locality is a fundamental concept in memory management, it states that programs tend to access a relatively small portion of memory at any given time. This principle is based on two observations:
1.  Spatial locality: When a program accesses a memory location, it is likely to access nearby memory locations in the near future.
2.  Temporal locality: When a program accesses a memory location, it is likely to access the same memory location again in the near future.
These observations suggest that memory access patterns exhibit both spatial and temporal locality, and programs tend to access a relatively small portion of memory at any given time. Therefore, caching frequently used memory blocks can significantly improve performance by reducing the number of memory accesses to main memory.
### How is TLB faster (what is associative mapping)
Associative mapping is a type of cache memory mapping technique that allows a memory address to be stored at any location in the cache. In an associative mapping scheme, the cache stores the memory address along with the contents of the corresponding memory location. When a memory access is requested, the cache checks all entries in parallel for a match with the requested address. If a match is found, the corresponding cache entry is returned as the result.
TLB is faster than accessing the page table due to the use of associative mapping. Associative mapping allows the TLB to store and retrieve virtual-to-physical address translations quickly and efficiently, reducing the average memory access time and improving overall system performance.
### Different file organization techniques
### Adding new record to indexed sequential file
### Overflow file vs log file
### Are all things same for child and parent process                                                                           
### What are semaphore
Semaphores are a synchronization mechanism used in concurrent programming to control access to shared resources among multiple processes or threads. A semaphore is a variable that contains a non-negative integer value, and two fundamental operations can be performed on it: P() (wait) and V() (signal).
Semaphores can be used to implement various synchronization mechanisms, such as mutual exclusion, deadlock prevention, and producer-consumer synchronization. They provide a flexible and efficient way to coordinate the actions of multiple processes or threads and to avoid race conditions and other synchronization issues.
### P() and V() what do these do to it?
P() and V() are two operations commonly used in semaphore-based synchronization mechanisms to control access to shared resources among concurrent processes.

The P() operation, also known as "wait" or "down", is used to request access to a shared resource. When a process calls the P() operation on a semaphore, it checks the value of the semaphore. If the semaphore value is greater than 0, the process is allowed to access the shared resource, and the semaphore value is decremented by 1. If the semaphore value is 0, the process is blocked and put on a wait queue until the semaphore value becomes greater than 0.

The V() operation, also known as "signal" or "up", is used to release access to a shared resource. When a process calls the V() operation on a semaphore, it increments the value of the semaphore by 1. If there are processes waiting on the semaphore, the scheduler wakes up the next process in the wait queue and grants it access to the shared resource.

Together, the P() and V() operations enable synchronization among concurrent processes by controlling access to shared resources. By using semaphores to protect shared resources, concurrent processes can coordinate their actions and avoid race conditions, deadlocks, and other synchronization issues.
### What is race condition?
A race condition is a situation that occurs in concurrent programming when the behavior of a program depends on the sequence or timing of events that are not under its control. In other words, it is a problem that arises when two or more threads or processes access a shared resource and attempt to modify it simultaneously, resulting in unexpected or incorrect behavior.
To avoid race conditions, concurrent programs must use proper synchronization mechanisms, such as locks, semaphores, or atomic operations, to ensure that shared resources are accessed and modified in a mutually exclusive and coordinated way. By using synchronization mechanisms, concurrent programs can avoid race conditions and ensure that their behavior is predictable and correct.
### What are holes in the memory called ?
Memory fragmentation
### Different page replacement algos
1.  FIFO (First-In-First-Out): In this algorithm, the page that was loaded first is evicted first when the memory is full. This algorithm is easy to implement, but may not perform well in situations where the oldest page is still being used heavily.
2.  LRU (Least Recently Used): In this algorithm, the page that has not been used for the longest time is evicted first when the memory is full. This algorithm tries to keep the most frequently used pages in the memory, but it may be computationally expensive to keep track of all the page access times.
3.  LFU (Least Frequently Used): In this algorithm, the page that has been used the least number of times is evicted first when the memory is full. This algorithm tries to keep the most frequently used pages in the memory, but it may not perform well in situations where a new page is needed to satisfy a sudden spike in demand.
4.  Optimal: In this algorithm, the page that will not be used for the longest time in the future is evicted first when the memory is full. This algorithm is ideal in theory, but it is practically impossible to implement as it requires knowledge of future page accesses.
### Critical section
A critical section refers to a section of code or a segment of a program that accesses shared resources, such as variables or data structures, that cannot be simultaneously accessed by multiple threads or processes. In other words, a critical section is a part of the code that must be executed exclusively, meaning that only one thread or process can access it at any given time.
### Methods to avoid race condition
### What are system calls?different types of system calls
In operating systems, a system call is a mechanism used by applications or processes to request a service or resource from the operating system kernel. When an application needs to access a resource or perform a privileged operation, such as accessing hardware or modifying system settings, it must make a system call to the operating system.
A system call typically involves a transition from user mode to kernel mode, where the application relinquishes control to the kernel and executes in a privileged mode. The kernel then performs the requested operation and returns control back to the application.
Examples of system calls include opening or closing files, reading or writing to files, creating or deleting processes, allocating or deallocating memory, and communicating with devices such as printers or network interfaces.
There are 5 different categories of system calls –
1.  Processcontrol
    Eg: end, abort, create, terminate, allocate and free memory.
2.  Filemanagement
    Eg: create, open, close, delete, read file etc.
3.  Device management
4.  Information maintenance
5.  Communication
### Hardware support for mutual exclusion and machine instructions
Hardware support for mutual exclusion typically involves providing hardware instructions that allow atomic access to shared resources. These instructions are typically implemented at the processor level and provide a way to ensure that only one processor can access the shared resource at any given time.
Machine instructions are a low-level set of instructions that a processor can execute directly. Machine instructions can be used to implement synchronization mechanisms, such as locks and semaphores, to ensure mutual exclusion and prevent race conditions. For example, a processor can use machine instructions to disable interrupts during critical sections of code, ensuring that other processors cannot access shared resources while the critical section is being executed.
### Difference between demand paging and swapping
The main difference between demand paging and swapping is that demand paging involves loading only the required pages into physical memory when they are needed, while swapping involves moving entire processes in and out of physical memory as needed. Demand paging is a more efficient use of memory because it only loads the pages that are needed, whereas swapping requires more overhead because it involves moving entire processes in and out of physical memory.
### Types of interprocess communication
### Synchronisation 
### Long term scheduler
### What is time sharing os
### Who maintains queue in serial processing?
### Deadlock recovery
### Dining philosopher
### Bankers (Data Structures and formula)
### Mutex
### Monitor
### Semaphore
### Ways to achieve Mutex
### Serial OS
### Hardware support for Mutual exclusion
### What is a pcb
### Producer consumer problem and solution
### How to calculate the efficiency of the cpu
