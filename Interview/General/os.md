# TCS Digital Role - Operating Systems Interview Guide

## Core OS Concepts

### 1. What is an Operating System?
**Answer:** An Operating System (OS) is system software that manages computer hardware and software resources and provides common services for computer programs. It acts as an intermediary between users and computer hardware.

**Key Functions:**
- Process Management
- Memory Management
- File System Management
- Device Management
- Security and Protection
- User Interface

**Examples:** Windows, Linux, macOS, Android, iOS

### 2. Types of Operating Systems

#### Based on User Interface:
**Command Line Interface (CLI):**
- Text-based interaction
- Examples: DOS, Linux Terminal
- Advantages: Less resource usage, faster for experts
- Disadvantages: Steep learning curve

**Graphical User Interface (GUI):**
- Visual interaction with icons and windows
- Examples: Windows, macOS
- Advantages: User-friendly, intuitive
- Disadvantages: More resource intensive

#### Based on Processing:
**Batch Operating System:**
- Jobs are processed in batches without user interaction
- Example: Early mainframe systems
- Advantages: High throughput
- Disadvantages: No user interaction during execution

**Time-Sharing Operating System:**
- Multiple users share system resources simultaneously
- Example: UNIX, Linux
- Advantages: Better resource utilization
- Disadvantages: Complex scheduling

**Real-Time Operating System (RTOS):**
- Guarantees response within specified time constraints
- Types: Hard real-time, Soft real-time
- Examples: VxWorks, QNX
- Applications: Embedded systems, medical devices

## Process Management

### 3. What is a Process?
**Answer:** A process is a program in execution. It includes the program code, current activity (program counter), stack, data section, and heap.

**Process States:**
1. **New:** Process is being created
2. **Ready:** Process is waiting to be assigned to processor
3. **Running:** Instructions are being executed
4. **Waiting/Blocked:** Process is waiting for some event
5. **Terminated:** Process has finished execution

**Process Control Block (PCB):**
- Process ID (PID)
- Process State
- Program Counter
- CPU Registers
- Memory Management Information
- I/O Status Information

### 4. Process vs Thread
**Process:**
- Independent execution unit
- Has its own memory space
- Heavyweight
- Inter-process communication is expensive
- Creation time is more

**Thread:**
- Lightweight execution unit within a process
- Shares memory space with other threads
- Lightweight
- Inter-thread communication is faster
- Creation time is less

**Example:**
```
Process: Web Browser
├── Thread 1: User Interface
├── Thread 2: Network Operations
├── Thread 3: JavaScript Engine
└── Thread 4: Rendering Engine
```

### 5. CPU Scheduling Algorithms

#### First Come First Serve (FCFS)
**Working:** Processes are executed in the order they arrive
**Advantages:** Simple to implement
**Disadvantages:** High average waiting time (convoy effect)

**Example:**
```
Process  Arrival Time  Burst Time
P1       0            24
P2       1            3
P3       2            3

Execution Order: P1 → P2 → P3
Average Waiting Time = (0 + 23 + 24)/3 = 15.67
```

#### Shortest Job First (SJF)
**Working:** Process with shortest burst time is executed first
**Types:** Preemptive (SRTF) and Non-preemptive
**Advantages:** Minimum average waiting time
**Disadvantages:** Starvation of longer processes

**Example:**
```
Process  Arrival Time  Burst Time
P1       0            6
P2       1            8
P3       2            7
P4       3            3

Non-preemptive SJF Order: P1 → P4 → P3 → P2
```

#### Round Robin (RR)
**Working:** Each process gets equal time slice (quantum)
**Advantages:** Fair allocation, no starvation
**Disadvantages:** Higher context switching overhead

**Example:**
```
Process  Burst Time
P1       24
P2       3
P3       3
Time Quantum = 4

Execution: P1(4) → P2(3) → P3(3) → P1(4) → P1(4) → P1(4) → P1(4) → P1(4)
```

#### Priority Scheduling
**Working:** Process with highest priority is executed first
**Types:** Preemptive and Non-preemptive
**Problem:** Priority inversion, starvation
**Solution:** Aging technique

### 6. Deadlock

#### What is Deadlock?
**Answer:** A situation where two or more processes are blocked forever, waiting for each other to release resources.

#### Necessary Conditions for Deadlock:
1. **Mutual Exclusion:** At least one resource must be held in non-shareable mode
2. **Hold and Wait:** A process must hold at least one resource and wait for additional resources
3. **No Preemption:** Resources cannot be forcibly removed from processes
4. **Circular Wait:** There must be a circular chain of processes waiting for resources

#### Deadlock Prevention:
- **Eliminate Mutual Exclusion:** Make resources shareable (not always possible)
- **Eliminate Hold and Wait:** Require processes to request all resources at once
- **Allow Preemption:** Forcibly remove resources from processes
- **Eliminate Circular Wait:** Impose ordering on resource types

#### Deadlock Avoidance:
**Banker's Algorithm:**
- System maintains information about allocated and maximum required resources
- Before allocating, check if system remains in safe state
- Grant request only if safe state is maintained

**Example:**
```
Processes: P0, P1, P2
Resources: A=10, B=5, C=7

Current Allocation:
     A  B  C
P0   0  1  0
P1   2  0  0
P2   3  0  2

Maximum Need:
     A  B  C
P0   7  5  3
P1   3  2  2
P2   9  0  2

Safe Sequence: P1 → P0 → P2
```

## Memory Management

### 7. Memory Management Techniques

#### Contiguous Memory Allocation:
**Fixed Partitioning:**
- Memory divided into fixed-size partitions
- Internal fragmentation problem
- Simple to implement

**Variable Partitioning:**
- Memory allocated based on process requirements
- External fragmentation problem
- Better memory utilization

#### Non-Contiguous Memory Allocation:

**Paging:**
- Physical memory divided into fixed-size blocks (frames)
- Logical memory divided into same-size blocks (pages)
- Page table maps logical to physical addresses
- Eliminates external fragmentation
- May have internal fragmentation

**Segmentation:**
- Program divided into segments (code, data, stack)
- Each segment can have different size
- Segment table maintains base and limit
- May have external fragmentation

**Segmented Paging:**
- Combination of segmentation and paging
- Each segment is paged
- Eliminates external fragmentation

### 8. Virtual Memory

#### What is Virtual Memory?
**Answer:** Virtual memory is a memory management technique that provides an illusion of having more physical memory than actually available by using secondary storage as an extension of main memory.

#### Benefits:
- Allows execution of processes larger than physical memory
- Enables multiprogramming with higher degree
- Provides memory protection
- Efficient memory utilization

#### Page Replacement Algorithms:

**FIFO (First In First Out):**
- Replace the oldest page in memory
- Simple to implement
- May suffer from Belady's anomaly

**LRU (Least Recently Used):**
- Replace the page that hasn't been used for longest time
- Better performance than FIFO
- Implementation complexity higher

**Optimal Algorithm:**
- Replace page that will not be used for longest time in future
- Theoretical algorithm (requires future knowledge)
- Used as benchmark for other algorithms

**Example - Page Replacement:**
```
Reference String: 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
Number of Frames: 3

FIFO:
Frame 1: 7  7  7  2  2  2  2  4  4  4  0  0  0
Frame 2: -  0  0  0  0  3  3  3  2  2  2  3  3
Frame 3: -  -  1  1  1  1  0  0  0  3  3  3  2
Page Faults: 9

LRU:
Frame 1: 7  7  7  2  2  2  2  4  4  4  0  0  0
Frame 2: -  0  0  0  0  3  3  3  2  2  2  3  3
Frame 3: -  -  1  1  1  1  0  0  0  3  3  3  2
Page Faults: 8
```

## File Systems

### 9. File System Concepts

#### What is a File System?
**Answer:** A file system is a method and data structure that an operating system uses to control how data is stored and retrieved on storage devices.

#### File Organization Methods:

**Sequential Organization:**
- Records stored in sequence
- Access: Sequential only
- Good for: Batch processing
- Example: Tape storage

**Direct/Random Organization:**
- Records can be accessed directly
- Uses hashing or indexing
- Good for: Online transactions
- Example: Database files

**Indexed Organization:**
- Separate index file maintains record locations
- Faster search operations
- Good for: Large files with frequent searches

#### Directory Structure:

**Single-Level Directory:**
- All files in one directory
- Simple but causes naming conflicts
- Used in early systems

**Two-Level Directory:**
- Separate directory for each user
- Eliminates naming conflicts between users
- Still limited within user space

**Tree-Structured Directory:**
- Hierarchical structure
- Absolute and relative paths
- Most common in modern systems

**Acyclic Graph Directory:**
- Allows sharing of files/directories
- Uses links or aliases
- More complex but flexible

### 10. Disk Scheduling Algorithms

#### FCFS (First Come First Serve):
- Requests served in arrival order
- Simple but may not be optimal
- High seek time

#### SSTF (Shortest Seek Time First):
- Serve request with minimum seek time
- May cause starvation
- Better than FCFS

#### SCAN (Elevator Algorithm):
- Head moves in one direction serving requests
- Reverses direction at end
- No starvation
- Uniform wait times

#### C-SCAN (Circular SCAN):
- Head moves in one direction only
- Returns to beginning after reaching end
- More uniform wait times than SCAN

**Example - Disk Scheduling:**
```
Current head position: 53
Request queue: 98, 183, 37, 122, 14, 124, 65, 67

FCFS: 53 → 98 → 183 → 37 → 122 → 14 → 124 → 65 → 67
Total head movement: 640 cylinders

SSTF: 53 → 65 → 67 → 37 → 14 → 98 → 122 → 124 → 183
Total head movement: 236 cylinders

SCAN: 53 → 37 → 14 → 65 → 67 → 98 → 122 → 124 → 183
Total head movement: 208 cylinders
```

## Synchronization

### 11. Process Synchronization

#### Race Condition:
**Definition:** A situation where multiple processes access shared data concurrently, and the outcome depends on the timing of their execution.

**Example:**
```
Shared variable: counter = 5

Process P1:                Process P2:
temp1 = counter           temp2 = counter
temp1 = temp1 + 1         temp2 = temp2 - 1
counter = temp1           counter = temp2

Expected: counter = 5 (if P1 then P2) or counter = 5 (if P2 then P1)
Actual: May be 4, 5, or 6 depending on execution order
```

#### Critical Section Problem:
**Definition:** A segment of code that accesses shared resources and must not be executed by more than one process at the same time.

**Requirements for Solution:**
1. **Mutual Exclusion:** Only one process in critical section at a time
2. **Progress:** Decision to enter critical section cannot be postponed indefinitely
3. **Bounded Waiting:** Limit on number of times other processes enter critical section

#### Solutions:

**Semaphores:**
- Integer variable accessed through atomic operations
- wait(S) and signal(S) operations
- Types: Binary semaphore (mutex), Counting semaphore

**Example - Producer-Consumer Problem:**
```
Semaphores:
mutex = 1 (for mutual exclusion)
empty = n (number of empty slots)
full = 0 (number of full slots)

Producer:
while(true) {
    produce_item();
    wait(empty);
    wait(mutex);
    add_to_buffer();
    signal(mutex);
    signal(full);
}

Consumer:
while(true) {
    wait(full);
    wait(mutex);
    remove_from_buffer();
    signal(mutex);
    signal(empty);
    consume_item();
}
```

**Monitors:**
- High-level synchronization construct
- Encapsulates shared data and operations
- Only one process can be active inside monitor
- Condition variables for synchronization

### 12. Common Synchronization Problems

#### Producer-Consumer Problem:
- Producer generates data, consumer uses data
- Shared buffer between producer and consumer
- Synchronization needed to prevent buffer overflow/underflow

#### Readers-Writers Problem:
- Multiple readers can access data simultaneously
- Only one writer can access data at a time
- No reader should access while writer is writing

#### Dining Philosophers Problem:
- Five philosophers sitting around circular table
- Five chopsticks between philosophers
- Need two chopsticks to eat
- Illustrates deadlock and resource allocation

**Solution using Semaphores:**
```
Semaphore chopstick[5] = {1, 1, 1, 1, 1};

Philosopher i:
while(true) {
    think();
    wait(chopstick[i]);
    wait(chopstick[(i+1)%5]);
    eat();
    signal(chopstick[i]);
    signal(chopstick[(i+1)%5]);
}
```

## I/O Systems

### 13. I/O Hardware and Software

#### I/O Hardware Components:
**I/O Devices:**
- Block devices (disks, tapes)
- Character devices (keyboards, mice, printers)

**Device Controllers:**
- Hardware that controls I/O devices
- Contains local buffer and special-purpose registers

**I/O Ports:**
- Registers in device controllers
- Status, control, data-in, data-out registers

#### I/O Methods:

**Programmed I/O:**
- CPU directly controls I/O operations
- CPU polls device status
- Inefficient CPU utilization

**Interrupt-Driven I/O:**
- Device interrupts CPU when ready
- Better CPU utilization than programmed I/O
- Still requires CPU for data transfer

**Direct Memory Access (DMA):**
- DMA controller transfers data directly between device and memory
- CPU involvement minimal
- Most efficient method

#### I/O Software Layers:
1. **Interrupt Handlers:** Handle device interrupts
2. **Device Drivers:** Device-specific code
3. **Device-Independent I/O Software:** Common I/O functions
4. **User-Level I/O Software:** Libraries and applications

## Interview Questions with Detailed Answers

### Process and Thread Questions:

**Q1: What happens when you type a command in terminal?**
**Answer:**
1. Shell reads the command line
2. Shell parses the command and arguments
3. Shell searches for executable in PATH
4. Shell creates new process using fork()
5. Child process executes the program using exec()
6. Parent process (shell) waits for child to complete
7. Shell displays prompt for next command

**Q2: How does context switching work?**
**Answer:**
1. Save current process state (registers, PC, stack pointer) in PCB
2. Update process state to waiting/ready
3. Select next process to run using scheduling algorithm
4. Load new process state from its PCB
5. Update process state to running
6. Transfer control to new process

**Q3: Explain multithreading benefits and challenges.**
**Answer:**
**Benefits:**
- Improved responsiveness
- Resource sharing
- Economy (less overhead than processes)
- Scalability on multiprocessor systems

**Challenges:**
- Synchronization issues
- Race conditions
- Deadlocks
- Debugging complexity

### Memory Management Questions:

**Q4: What is the difference between paging and segmentation?**
**Answer:**

| Aspect | Paging | Segmentation |
|--------|--------|--------------|
| Division | Fixed-size pages | Variable-size segments |
| Fragmentation | Internal only | External fragmentation |
| User View | Transparent | Visible to programmer |
| Protection | Page-level | Segment-level |
| Sharing | Difficult | Easy |

**Q5: Explain the working of virtual memory.**
**Answer:**
1. Program generates logical addresses
2. MMU translates logical to physical addresses
3. If page not in memory, page fault occurs
4. OS loads required page from secondary storage
5. If memory full, page replacement algorithm selects victim
6. Victim page written to disk if modified
7. New page loaded and process continues

### File System Questions:

**Q6: What are hard links and soft links?**
**Answer:**

**Hard Link:**
- Direct reference to file's inode
- Multiple names for same file
- Cannot span file systems
- Cannot link to directories
- File deleted only when all hard links removed

**Soft Link (Symbolic Link):**
- Contains path to target file
- Can span file systems
- Can link to directories
- If target deleted, link becomes dangling
- Separate inode for link itself

### Performance and Optimization:

**Q7: How would you optimize system performance?**
**Answer:**
1. **CPU Optimization:**
   - Use appropriate scheduling algorithms
   - Balance load across cores
   - Minimize context switching

2. **Memory Optimization:**
   - Implement efficient page replacement
   - Use memory pools
   - Optimize cache usage

3. **I/O Optimization:**
   - Use appropriate disk scheduling
   - Implement caching/buffering
   - Use asynchronous I/O

4. **System Monitoring:**
   - Monitor resource utilization
   - Identify bottlenecks
   - Tune system parameters

## Quick Reference for Interview

### Key Formulas:
- **CPU Utilization** = (Total time - Idle time) / Total time
- **Throughput** = Number of processes completed / Time
- **Turnaround Time** = Completion time - Arrival time
- **Waiting Time** = Turnaround time - Burst time
- **Response Time** = First CPU allocation - Arrival time

### Important Commands (Linux):
```bash
ps aux          # List all processes
top             # Real-time process monitor
kill -9 PID     # Forcefully terminate process
df -h           # Disk space usage
free -h         # Memory usage
iostat          # I/O statistics
vmstat          # Virtual memory statistics
```

### Common Interview Tips:
1. **Understand fundamentals** before diving into complex topics
2. **Draw diagrams** to explain concepts visually
3. **Give real-world examples** when possible
4. **Discuss trade-offs** between different approaches
5. **Know the evolution** of concepts (why they were developed)
6. **Practice coding** simple OS algorithms
7. **Stay updated** with modern OS features and trends