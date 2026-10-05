# Operating Systems + Networking Math Interview Preparation

> **For:** Software Engineer, Backend, Full-Stack, SQA, DevOps and CS job interviews  
> **Contents:** 150 Operating System questions + 50 OS/Networking numerical questions  
> **Style:** Question → Answer → Real-life analogy → Visual/example → Interview key point  
> **Goal:** Understand first, memorize the key point second.

---

# Table of Contents

## Operating Systems — 150 Questions
1. [OS Fundamentals — 1–30](#1-os-fundamentals--130)
2. [Processes & Threads — 31–60](#2-processes--threads--3160)
3. [CPU Scheduling — 61–80](#3-cpu-scheduling--6180)
4. [Synchronization & Deadlocks — 81–105](#4-synchronization--deadlocks--81105)
5. [Memory Management — 106–130](#5-memory-management--106130)
6. [File Systems, I/O & Advanced OS — 131–150](#6-file-systems-io--advanced-os--131150)

## Math / Numerical Questions — 50
7. [Operating System Math — 1–25](#operating-system-math--125)
8. [Networking Math — 26–50](#networking-math--2650)

9. [Final Interview Cheat Sheet](#final-interview-cheat-sheet)

---

# Operating Systems — 150 Questions

# 1. OS Fundamentals — 1–30

## 1. What is an Operating System?

An Operating System (OS) is system software that manages computer hardware and provides services to applications.

Examples:

```text
Windows
Linux
macOS
Android
iOS
```

### Visual

```text
+-------------------------+
|       Applications      |
| Browser | VS Code | DB  |
+-------------------------+
|     Operating System    |
+-------------------------+
| CPU | RAM | Disk | I/O |
+-------------------------+
|        Hardware         |
+-------------------------+
```

### Real-life analogy

An OS is like a **hotel manager**.

- CPU = workers
- RAM = working tables
- Disk = storage room
- Applications = guests
- OS = manager deciding who gets which resource

### Key point

> OS manages hardware and provides an execution environment for applications.

---

## 2. What are the main functions of an OS?

Major responsibilities:

1. Process management
2. Memory management
3. File-system management
4. Device/I/O management
5. Security and protection
6. Networking
7. Resource allocation

```text
             Operating System
                    |
      +-------------+-------------+
      |       |       |      |     |
    CPU     Memory   Disk   I/O  Security
```

---

## 3. What is the kernel?

The **kernel** is the core component of an operating system.

It manages privileged operations such as:

- CPU scheduling
- Memory management
- Device access
- System calls
- Process management

```text
Applications
     ↓
System Calls
     ↓
  Kernel
     ↓
Hardware
```

### Real-life analogy

The kernel is like the **building manager** who controls access to elevators, electricity, rooms, and restricted areas.

---

## 4. What is user mode?

User mode is a restricted CPU execution mode used by ordinary applications.

Example:

```text
Browser → User Mode
Text Editor → User Mode
Game → User Mode
```

Applications cannot freely perform privileged hardware operations.

---

## 5. What is kernel mode?

Kernel mode is a privileged execution mode in which the OS can perform protected operations.

```text
User Mode
    ↓ system call
Kernel Mode
    ↓
Hardware
```

### Key point

> User mode protects the system from faulty or malicious applications.

---

## 6. User mode vs kernel mode

| User Mode | Kernel Mode |
|---|---|
| Restricted | Privileged |
| Applications | OS kernel |
| Limited hardware access | Direct/privileged hardware access |
| Safer | More powerful |

---

## 7. What is a system call?

A system call is an interface through which a user-space program requests a service from the OS kernel.

Examples include operations related to:

```text
open
read
write
fork
exec
mmap
```

### Example

```text
Application
    |
    | read()
    ↓
Kernel
    |
    ↓
Disk / File System
```

### Real-life analogy

A customer does not enter the restaurant kitchen directly. They ask the waiter, who communicates with the kitchen.

The waiter is similar to the system-call interface.

---

## 8. What is a process?

A process is a program in execution.

A program is passive:

```text
program = stored instructions
```

A process is active:

```text
program + execution state + resources
```

### Example

Opening Chrome creates processes.

```text
Chrome executable
      ↓
Running Chrome process
```

---

## 9. Program vs Process

| Program | Process |
|---|---|
| Passive | Active |
| Stored code | Running instance |
| Exists on disk | Exists in memory/execution |
| No execution state | Has execution state |

### Real-life analogy

Recipe = program.

Person actually cooking = process.

---

## 10. What is a Process Control Block (PCB)?

PCB is a kernel data structure containing information about a process.

Typical information:

```text
PID
Process state
Program counter
CPU registers
Scheduling information
Memory-management information
Open files
Accounting/security information
```

---

## 11. What is PID?

PID = **Process ID**.

It uniquely identifies a process within an operating-system process namespace.

Linux example:

```bash
ps aux
```

You may see:

```text
PID
1234
5678
```

---

## 12. What is a process state?

Common process states include:

```text
New
Ready
Running
Waiting/Blocked
Terminated
```

### Visual

```text
          admitted
New ----------------> Ready
                       |
                       | scheduler
                       ↓
                    Running
                    /     \
            I/O wait      exit
              ↓             ↓
           Waiting       Terminated
              |
          I/O done
              ↓
            Ready
```

---

## 13. What is the ready state?

A process is ready when it can run but is waiting for CPU time.

```text
Ready Queue:
[P1] [P2] [P3]
        |
        ↓
       CPU
```

---

## 14. What is the running state?

A process is running when its instructions are currently executing on a CPU core.

---

## 15. What is the blocked/waiting state?

A process is blocked when it cannot continue until some event occurs.

Example:

```text
Process
  ↓
read(file)
  ↓
Waiting for disk I/O
  ↓
I/O complete
  ↓
Ready
```

---

## 16. What is context switching?

A context switch occurs when the CPU changes from one process/thread to another and the OS saves/restores execution state.

```text
CPU
 |
 +--> Process A
 |
 | context switch
 ↓
Process B
```

### Real-life analogy

A worker stops task A, writes down exactly where they stopped, then starts task B.

---

## 17. Why is context switching expensive?

Because the CPU spends time saving/restoring state and the switch can disturb CPU caches and other hardware state.

```text
Useful work
   ↓
Context switch
   ↓
Save/restore
   ↓
Useful work
```

### Key point

> Context switching is necessary, but it is overhead.

---

## 18. What is a thread?

A thread is a unit of execution within a process.

A process can contain multiple threads.

```text
Process
+----------------------+
| Code / Data / Files  |
|                      |
| Thread 1             |
| Thread 2             |
| Thread 3             |
+----------------------+
```

---

## 19. Process vs Thread

| Process | Thread |
|---|---|
| Independent execution environment | Execution unit inside process |
| Separate virtual address space | Threads share process address space |
| More expensive to create/switch | Usually cheaper |
| Stronger isolation | Less isolation |

---

## 20. What resources do threads share?

Threads in the same process typically share:

- Code
- Heap
- Global variables
- Open file descriptions/resources depending on OS semantics

Each thread has its own:

- Stack
- Registers
- Program counter
- Thread-local storage where used

---

## 21. What is concurrency?

Concurrency means multiple tasks make progress during overlapping periods.

```text
Time →
Task A: ███   ███
Task B:   ███   ███
```

On a single CPU core, concurrency can happen through interleaving.

---

## 22. What is parallelism?

Parallelism means tasks execute literally at the same time on multiple processing units.

```text
Core 1 → Task A
Core 2 → Task B
```

### Key distinction

> Concurrency = dealing with multiple tasks at once.  
> Parallelism = executing multiple tasks simultaneously.

---

## 23. Concurrency vs parallelism

### Single core

```text
A → B → A → B
```

Concurrent, but not physically parallel.

### Multiple cores

```text
Core 1 → A
Core 2 → B
```

Concurrent and parallel.

---

## 24. What is multitasking?

Multitasking allows multiple processes/tasks to make progress apparently at the same time.

The OS scheduler switches CPU time between runnable tasks.

---

## 25. What is multiprocessing?

Multiprocessing uses multiple processes and can execute them simultaneously on multiple CPU cores.

```text
Core 1 → Process A
Core 2 → Process B
Core 3 → Process C
```

---

## 26. What is multithreading?

Multithreading means a process has multiple threads of execution.

Example:

```text
Web Server Process
 |
 +-- Thread 1 → Request A
 +-- Thread 2 → Request B
 +-- Thread 3 → Request C
```

---

## 27. What is a daemon process?

A daemon is a background process that provides a service, often without direct user interaction.

Linux examples include system services.

Examples conceptually:

```text
SSH service
Logging service
Web server
```

---

## 28. What is a parent process?

A parent process is a process that creates another process.

```text
Parent
  |
  +---- Child
```

On Unix-like systems, process creation often uses `fork()` followed by `exec()`.

---

## 29. What is a child process?

A child process is a process created by another process.

Example:

```text
Shell
 |
 +-- Node process
```

---

## 30. What is an orphan process?

An orphan process is a child whose original parent terminates before the child.

On Unix-like systems, the orphan is adopted/re-parented by an appropriate system process/subreaper depending on the environment.

### Real-life analogy

A child loses their original guardian and is assigned another responsible guardian.

---

# 2. Processes & Threads — 31–60

## 31. What is a zombie process?

A zombie is a terminated child process whose exit status has not yet been collected by its parent.

```text
Child exits
   ↓
Exit status remains
   ↓
Parent has not wait()ed
   ↓
Zombie
```

A zombie is not actively executing.

---

## 32. Zombie vs orphan

| Zombie | Orphan |
|---|---|
| Child has terminated | Child is still running |
| Parent has not collected exit status | Original parent has terminated |
| Uses process-table entry | Gets re-parented |

---

## 33. What is `fork()`?

On Unix-like systems, `fork()` creates a new process by duplicating the calling process's process state according to OS semantics.

Conceptually:

```text
Parent
  |
 fork()
  |
  +---- Parent
  |
  +---- Child
```

---

## 34. What is `exec()`?

`exec`-family calls replace the current process image with a new program.

Typical pattern:

```text
fork()
  ↓
child
  ↓
exec()
  ↓
new program
```

---

## 35. fork vs exec

`fork()`:

> Creates a new process.

`exec()`:

> Replaces the current process image with another program.

---

## 36. What is `wait()`?

A parent can use `wait()`/related calls to collect a child's termination status.

This prevents the child from remaining as an unreaped zombie.

---

## 37. What is IPC?

IPC = **Inter-Process Communication**.

It allows processes to exchange information.

Examples:

- Pipes
- Message queues
- Shared memory
- Signals
- Sockets
- Unix domain sockets

---

## 38. What is a pipe?

A pipe is a communication mechanism often used between related processes.

Example:

```bash
cat file.txt | grep "error"
```

Visual:

```text
cat
 |
 | pipe
 ↓
grep
```

Output of `cat` becomes input to `grep`.

---

## 39. What is shared memory?

Shared memory allows multiple processes to access a common memory region.

```text
Process A ----+
              |
              ↓
       Shared Memory
              ↑
              |
Process B ----+
```

It can be very fast, but synchronization is required.

---

## 40. What is a message queue?

A message queue allows processes to exchange discrete messages.

```text
Producer
   |
   ↓
[ Message Queue ]
   |
   ↓
Consumer
```

---

## 41. What is a semaphore?

A semaphore is a synchronization primitive based on a counter used to control access or coordinate execution.

Types commonly discussed:

```text
Binary semaphore
Counting semaphore
```

---

## 42. What is a mutex?

A mutex provides mutual exclusion so that only one thread can own a protected critical section at a time.

```text
Thread A → LOCK → Critical Section → UNLOCK
Thread B → waits
```

---

## 43. Mutex vs semaphore

| Mutex | Semaphore |
|---|---|
| Usually ownership-based lock | Counter-based synchronization primitive |
| One owner at a time | Can represent multiple permits |
| Protects critical section | Can coordinate access/events |

### Easy analogy

Mutex = one bathroom key.

Semaphore with 3 permits = parking lot with three spaces.

---

## 44. What is a critical section?

A critical section is code that accesses shared state and must be protected from unsafe concurrent access.

```text
lock()
  ↓
shared_counter++
  ↓
unlock()
```

---

## 45. What is a race condition?

A race condition occurs when the program's result depends on the timing/order of concurrent operations.

Example:

```text
counter = 0

Thread A: read 0
Thread B: read 0
Thread A: write 1
Thread B: write 1
```

Expected:

```text
2
```

Actual:

```text
1
```

---

## 46. What is thread safety?

Code is thread-safe if it behaves correctly when accessed concurrently according to its intended contract.

Common tools:

- Mutexes
- Atomics
- Immutable data
- Thread-safe data structures

---

## 47. What is atomic operation?

An atomic operation appears indivisible to other threads.

Example:

```text
atomic_increment(counter)
```

No other thread can observe a partially completed update.

---

## 48. What is a monitor?

A monitor is a high-level synchronization abstraction combining shared data, mutual exclusion, and condition synchronization.

Conceptually:

```text
Monitor
+----------------+
| Shared data    |
| Methods        |
| Lock           |
| Conditions     |
+----------------+
```

---

## 49. What is a condition variable?

A condition variable allows a thread to sleep until a condition associated with shared state becomes true.

Typical pattern:

```text
lock()
while condition is false:
    wait()
use shared state
unlock()
```

Another thread changes the state and signals.

---

## 50. What is a thread pool?

A thread pool maintains reusable worker threads.

```text
Tasks
[T1][T2][T3][T4]
       |
       ↓
+----------------+
| Thread Pool    |
| T1 T2 T3 T4    |
+----------------+
```

Benefits:

- Avoid repeated thread creation
- Control concurrency
- Reduce overhead

---

## 51. What is a process pool?

A process pool maintains reusable worker processes.

Useful when:

- Process isolation matters
- CPU-heavy work needs separate processes
- Language runtime has limitations around threads

---

## 52. What is a scheduler?

The scheduler decides which runnable process/thread should receive CPU time.

```text
Ready Queue
[P1][P2][P3]
     |
     ↓
 Scheduler
     |
     ↓
    CPU
```

---

## 53. What is a dispatcher?

The dispatcher transfers CPU control to the process/thread selected by the scheduler.

It may perform tasks such as:

- Context switching
- Switching to user mode
- Jumping to the correct instruction

---

## 54. What is a context switch?

When CPU execution changes from one process/thread to another, the OS preserves the current execution context and restores the next context.

```text
P1 running
   ↓
save P1 context
   ↓
restore P2 context
   ↓
P2 running
```

---

## 55. What is preemption?

Preemption occurs when the OS interrupts a running task and gives CPU time to another runnable task.

Example:

```text
P1 → CPU
     |
     | timer interrupt
     ↓
P2 → CPU
```

---

## 56. What is a non-preemptive system?

In non-preemptive scheduling, a running process generally keeps the CPU until it blocks, exits, or voluntarily yields.

---

## 57. What is a preemptive system?

In preemptive scheduling, the OS can interrupt a running process/thread and schedule another.

Modern general-purpose OSes use preemptive scheduling.

---

## 58. What is a timer interrupt?

A timer interrupt periodically interrupts CPU execution so the OS can regain control.

This helps implement preemptive scheduling.

---

## 59. What is a kernel thread?

A kernel thread is a thread managed/scheduled by the operating system kernel.

---

## 60. What is a user-level thread?

A user-level thread is managed primarily by a user-space runtime/library rather than directly as a kernel schedulable entity.

### Key point

User-level threading can reduce some kernel overhead but may have different blocking and parallelism characteristics depending on implementation.

---

# 3. CPU Scheduling — 61–80

## 61. What is CPU scheduling?

CPU scheduling chooses which runnable process/thread should execute next.

```text
Ready Queue
[P1][P2][P3][P4]
       |
       ↓
   Scheduler
       |
       ↓
      CPU
```

---

## 62. What is FCFS scheduling?

FCFS = **First Come, First Served**.

Processes run in arrival order.

```text
P1 → P2 → P3
```

### Real-life analogy

A normal queue at a bank.

First customer to arrive is served first.

---

## 63. What is SJF?

SJF = **Shortest Job First**.

The process with the smallest estimated CPU burst is selected first.

```text
P1 = 8 ms
P2 = 2 ms
P3 = 4 ms

Order:
P2 → P3 → P1
```

---

## 64. What is SRTF?

SRTF = **Shortest Remaining Time First**.

It is the preemptive form of SJF.

If a new process arrives with a shorter remaining time, the running process may be preempted.

---

## 65. What is Round Robin?

Round Robin assigns each process a time quantum.

Example:

```text
Quantum = 4 ms

P1 → 4 ms
P2 → 4 ms
P3 → 4 ms
P1 → 4 ms
...
```

### Real-life analogy

A teacher gives each student four minutes to speak, then moves to the next student.

---

## 66. What is priority scheduling?

Each process has a priority.

The scheduler selects a higher-priority task before lower-priority tasks according to the scheduling policy.

---

## 67. What is starvation?

Starvation occurs when a process waits indefinitely because other processes continually receive service.

Example:

```text
High priority tasks
████████████████████

Low priority task
....................
```

---

## 68. What is aging?

Aging gradually increases the effective priority of waiting processes to reduce starvation.

```text
Wait longer
    ↓
Priority increases
    ↓
Eventually scheduled
```

---

## 69. What is turnaround time?

Turnaround time:

```text
Completion Time - Arrival Time
```

Example:

```text
Arrival = 2
Completion = 10

Turnaround = 10 - 2 = 8
```

---

## 70. What is waiting time?

Waiting time is the amount of time a process spends waiting in the ready queue.

For a simple non-I/O scheduling model:

```text
Waiting Time = Turnaround Time - CPU Burst Time
```

---

## 71. What is response time?

Response time is the time from arrival until the process first receives CPU service.

```text
First CPU Start - Arrival Time
```

Important for interactive systems.

---

## 72. Turnaround vs waiting vs response

```text
Arrival
  |
  | waiting
  ↓
First CPU
  |
  | execution + possible waiting
  ↓
Completion
```

- Response = arrival → first CPU
- Turnaround = arrival → completion
- Waiting = time waiting in ready queue

---

## 73. What is throughput?

Throughput is the number of completed processes/jobs per unit time.

Example:

```text
100 jobs / 10 seconds = 10 jobs/sec
```

---

## 74. What is CPU utilization?

CPU utilization is the fraction/percentage of time the CPU is busy doing useful work.

```text
CPU busy = 90%
CPU idle = 10%
```

---

## 75. What is dispatcher latency?

Dispatcher latency is the time needed to stop one process/thread and start another selected one.

Lower is generally better for responsive scheduling.

---

## 76. What is time quantum?

Time quantum is the maximum CPU time a process receives in one Round Robin turn before being preempted, assuming it remains runnable.

Example:

```text
Quantum = 10 ms
```

---

## 77. What happens if Round Robin quantum is too small?

Too small a quantum can cause many context switches.

```text
P1
↓
P2
↓
P3
↓
P1
↓
P2
```

More switching = more overhead.

---

## 78. What happens if Round Robin quantum is too large?

If very large, Round Robin approaches FCFS behavior.

Interactive responsiveness can suffer because a task may keep the CPU for a long time.

---

## 79. What is scheduling overhead?

Scheduling overhead is CPU time spent managing scheduling rather than executing application work.

Includes:

- Context switching
- Scheduler execution
- Cache disruption

---

## 80. Which scheduling algorithm is best?

There is no universally best algorithm.

Depends on the goal:

```text
Interactive → responsiveness
Batch       → throughput
Fairness    → avoid starvation
Real-time   → deadline guarantees
```

### Interview key point

> Scheduling is a trade-off between throughput, latency, fairness, response time, and overhead.

---

# 4. Synchronization & Deadlocks — 81–105

## 81. What is synchronization?

Synchronization coordinates concurrent execution so shared data remains correct.

```text
Thread A ----+
             |
             ↓
       Shared Resource
             ↑
             |
Thread B ----+
```

---

## 82. Why is synchronization necessary?

Without synchronization:

```text
Thread A reads X
Thread B reads X
Thread A writes X+1
Thread B writes X+1
```

One update can be lost.

---

## 83. What is a critical section?

A critical section accesses shared state that requires mutual exclusion.

Example:

```text
lock()
balance = balance - 100
unlock()
```

---

## 84. What is a race condition?

A race condition occurs when the result depends on timing between concurrent operations.

Classic example:

```text
counter++

Actually:
read
add
write
```

Two threads can interleave these operations incorrectly.

---

## 85. What is a data race?

A data race is a specific form of concurrency error where multiple threads access the same memory concurrently, at least one access is a write, and the accesses are not properly synchronized according to the language/runtime memory model.

---

## 86. What is a mutex?

A mutex allows only one thread at a time to enter a protected critical section.

```text
Thread A → LOCK
           |
           ↓
       Critical
        Section
           |
           ↓
         UNLOCK

Thread B → WAIT
```

---

## 87. What is a semaphore?

A semaphore maintains a count representing available permits/resources.

Example:

```text
Semaphore = 3
```

Up to three threads may acquire a permit simultaneously.

---

## 88. What is a binary semaphore?

A binary semaphore has two logical states, often 0 and 1.

It can be used for signaling or mutual exclusion, though a mutex is usually preferable when ownership semantics are required.

---

## 89. What is a counting semaphore?

A counting semaphore can represent multiple available resources.

Example:

```text
Database connection pool = 5
Semaphore = 5
```

At most five workers can acquire a connection permit at once.

---

## 90. What is deadlock?

Deadlock occurs when processes/threads are permanently waiting for resources/events held by one another.

```text
Thread A holds Lock 1
Thread B holds Lock 2

A waits for Lock 2
B waits for Lock 1

      DEADLOCK
```

---

## 91. What are the four necessary conditions for deadlock?

The Coffman conditions:

1. Mutual exclusion
2. Hold and wait
3. No preemption
4. Circular wait

All four must hold for classic deadlock to occur.

---

## 92. What is mutual exclusion?

At least one resource is non-shareable.

```text
One printer
   |
Only one process can use it at a time
```

---

## 93. What is hold and wait?

A process holds one resource while waiting for another.

```text
Process A:
holds Lock 1
waits for Lock 2
```

---

## 94. What is no preemption?

A resource cannot simply be forcibly taken from a process; it must be released voluntarily or by a defined recovery mechanism.

---

## 95. What is circular wait?

A cycle exists in resource waiting.

```text
P1 → waits for P2
P2 → waits for P3
P3 → waits for P1
```

---

## 96. How can deadlock be prevented?

Break at least one Coffman condition.

Example: prevent circular wait by enforcing a global lock order.

```text
Always acquire:
Lock 1 → Lock 2 → Lock 3
```

Never:

```text
Thread A: Lock 1 → Lock 2
Thread B: Lock 2 → Lock 1
```

---

## 97. What is deadlock avoidance?

Deadlock avoidance dynamically makes resource-allocation decisions to keep the system in a safe state.

Classic algorithm:

```text
Banker's Algorithm
```

---

## 98. What is deadlock detection?

The OS/application can allow deadlocks to occur and periodically detect them.

Then it can recover.

---

## 99. What is deadlock recovery?

Possible approaches:

- Terminate selected processes
- Roll back work
- Preempt resources where possible
- Restart affected services

---

## 100. What is livelock?

In livelock, processes are active and repeatedly changing state but make no useful progress.

```text
A moves
B moves
A moves
B moves
...
```

Unlike deadlock, they are not simply blocked.

---

## 101. Deadlock vs livelock

| Deadlock | Livelock |
|---|---|
| Waiting | Active |
| No progress | No useful progress |
| Resources held/waited | Repeated responses/actions |

---

## 102. What is starvation?

Starvation occurs when a process waits indefinitely because scheduling/resource allocation continually favors others.

---

## 103. Starvation vs deadlock

**Starvation:**

```text
One process waits
Others continue
```

**Deadlock:**

```text
A waits for B
B waits for A
```

---

## 104. What is priority inversion?

A high-priority task waits for a resource held by a low-priority task, while medium-priority work prevents the low-priority task from running.

```text
High priority → waiting
      ↑
   Lock held by
      ↓
Low priority

Medium priority keeps running
```

A common mitigation is **priority inheritance**.

---

## 105. What is the producer-consumer problem?

A producer generates data and places it into a bounded buffer; consumers remove data.

```text
Producer
   |
   ↓
[ Bounded Buffer ]
   |
   ↓
Consumer
```

Problems to solve:

- Producer must not overfill buffer.
- Consumer must not consume from empty buffer.
- Shared buffer access must be synchronized.

---

# 5. Memory Management — 106–130

## 106. What is memory management?

Memory management controls how RAM is allocated, protected, shared, and reclaimed.

```text
RAM
+----------------+
| OS             |
| Process A      |
| Process B      |
| Free           |
+----------------+
```

---

## 107. What is virtual memory?

Virtual memory gives each process a virtual address space that is mapped to physical memory.

```text
Process
Virtual Address
      ↓
Page Tables
      ↓
Physical RAM
```

It allows processes to have an address space larger/different from currently resident physical RAM.

---

## 108. Why is virtual memory useful?

Benefits:

- Process isolation
- Memory protection
- Easier programming model
- Shared memory support
- Demand paging
- Efficient memory use

---

## 109. What is a virtual address?

A virtual address is the address generated/used by a process.

Example:

```text
Process sees:
0x00007FFF...
```

The MMU/page tables translate it to a physical location.

---

## 110. What is a physical address?

A physical address refers to a location in physical memory hardware.

```text
Virtual address
      ↓
MMU
      ↓
Physical address
```

---

## 111. What is paging?

Paging divides virtual memory into fixed-size **pages** and physical memory into fixed-size **frames**.

```text
Virtual Memory          Physical RAM

Page 0  ─────────────→ Frame 5
Page 1  ─────────────→ Frame 2
Page 2  ─────────────→ Frame 8
```

---

## 112. What is a page?

A page is a fixed-size block of virtual memory.

Common example:

```text
4 KiB
```

But actual page sizes vary by architecture/OS.

---

## 113. What is a frame?

A frame is a fixed-size block of physical memory.

Page size and frame size are equal for a given paging configuration.

---

## 114. Page vs frame

```text
Virtual Memory → Page
Physical Memory → Frame
```

Both have the same size within a paging system.

---

## 115. What is a page table?

A page table maps virtual pages to physical frames.

```text
Virtual Page     Physical Frame
     0      →          5
     1      →          2
     2      →          8
```

---

## 116. What is MMU?

MMU = **Memory Management Unit**.

It performs/assists with virtual-to-physical address translation and memory protection.

```text
CPU
 |
 | Virtual Address
 ↓
 MMU
 |
 ↓
Physical Address
```

---

## 117. What is a TLB?

TLB = **Translation Lookaside Buffer**.

It caches recent virtual-to-physical translation information.

```text
CPU
 ↓
TLB hit?
 ↓ yes
Physical mapping quickly available
```

A TLB miss requires additional page-table lookup.

---

## 118. What is a page fault?

A page fault occurs when a process accesses a virtual page that is not currently mapped as required in physical memory.

The OS may need to:

```text
Locate page
  ↓
Load it
  ↓
Update page table
  ↓
Resume process
```

A page fault is not necessarily an error; demand paging intentionally uses page faults.

---

## 119. What is demand paging?

Pages are loaded into RAM when needed rather than loading the entire process at once.

```text
Program starts
   ↓
Only required pages loaded
   ↓
Other pages loaded when accessed
```

---

## 120. What is thrashing?

Thrashing occurs when the system spends excessive time handling page faults and swapping/paging rather than doing useful application work.

```text
CPU useful work ↓
Page fault activity ↑↑↑
Disk I/O ↑↑↑
```

---

## 121. What is page replacement?

When RAM has no suitable free frame, the OS may need to evict a resident page.

Algorithms include:

- FIFO
- LRU
- Optimal (theoretical benchmark)

---

## 122. What is FIFO page replacement?

FIFO removes the page that has been in memory the longest.

```text
Oldest → evict
```

Simple but can perform poorly.

---

## 123. What is LRU?

LRU = **Least Recently Used**.

It replaces the page that has not been used for the longest recent period.

```text
Recent:
A B C

Least recent → A
```

---

## 124. What is the optimal page replacement algorithm?

The theoretical optimal algorithm replaces the page whose next use is farthest in the future.

It gives the minimum possible page faults for a known reference string but cannot generally be implemented exactly in a real OS because the future is unknown.

---

## 125. What is fragmentation?

Fragmentation is wasted memory caused by allocation patterns.

Two types:

```text
Internal fragmentation
External fragmentation
```

---

## 126. What is internal fragmentation?

Internal fragmentation occurs when allocated memory contains unused space inside an allocated block.

Example:

```text
Requested = 6 KB
Allocated = 8 KB

Waste = 2 KB
```

---

## 127. What is external fragmentation?

External fragmentation occurs when free memory exists but is split into many small non-contiguous blocks.

```text
[Used][Free][Used][Free][Used][Free]
```

Total free memory may be enough, but a large contiguous allocation may fail.

---

## 128. What is swapping?

Swapping refers to moving memory contents between RAM and secondary storage.

Modern systems use more nuanced paging mechanisms rather than necessarily swapping entire processes.

---

## 129. What is memory protection?

Memory protection prevents one process from improperly accessing another process's memory or protected kernel memory.

```text
Process A
[Own memory]

Process B
[Own memory]

Kernel
[Protected]
```

---

## 130. What is copy-on-write?

Copy-on-write allows multiple processes to initially share physical pages until one attempts to modify a shared page.

```text
Parent ──┐
         ├── Shared page
Child  ──┘

Child writes
     ↓
Copy created
     ↓
Child gets private page
```

This is especially useful around `fork()`.

---

# 6. File Systems, I/O & Advanced OS — 131–150

## 131. What is a file system?

A file system organizes data on storage devices.

Examples:

```text
ext4
XFS
NTFS
APFS
```

---

## 132. What is a file?

A file is a named collection of data maintained by the file system.

Examples:

```text
app.js
photo.jpg
database.db
report.pdf
```

---

## 133. What is a directory?

A directory organizes names/references to files and possibly other directories.

```text
/home/imtius/
       |
       +-- Documents/
       +-- Projects/
       +-- Downloads/
```

---

## 134. What is an inode?

On Unix-like file systems such as ext4, an inode stores metadata about a file and references to its data, while the filename is stored in a directory entry.

Typical metadata:

- File type
- Permissions
- Owner
- Size
- Timestamps
- Data block references

---

## 135. What is a file descriptor?

A file descriptor is a small integer used by a process to refer to an open file or other I/O resource on Unix-like systems.

Common standard descriptors:

```text
0 → stdin
1 → stdout
2 → stderr
```

---

## 136. What is buffering?

Buffering temporarily stores data in memory to improve efficiency or smooth differences in producer/consumer speed.

```text
Producer
   ↓
[ Buffer ]
   ↓
Consumer
```

---

## 137. What is caching?

Caching stores frequently/recently used data so future access is faster.

```text
First:
App → Slow storage → Data

Later:
App → Cache → Data
```

---

## 138. Buffering vs caching

**Buffer:**

> Smooths data transfer and rate differences.

**Cache:**

> Keeps copies of data to speed up future access.

---

## 139. What is an interrupt?

An interrupt is a signal/event that causes the CPU to temporarily stop normal execution and run an appropriate handler.

Example:

```text
Keyboard input
     ↓
Interrupt
     ↓
OS handler
```

---

## 140. What is DMA?

DMA = **Direct Memory Access**.

It allows compatible devices to transfer data to/from memory with limited CPU involvement.

```text
Device
  |
  | DMA
  ↓
RAM

CPU does not copy every byte itself.
```

---

## 141. What is a device driver?

A driver is software that allows the OS to communicate with a specific hardware device.

```text
Application
    ↓
OS
    ↓
Driver
    ↓
Hardware
```

---

## 142. What is I/O scheduling?

I/O scheduling determines the order in which storage/device requests are processed.

For storage, algorithms historically include:

- FCFS
- SSTF
- SCAN
- C-SCAN

The best choice depends on hardware and workload.

---

## 143. What is booting?

Booting is the process of starting a computer and loading the operating system.

Simplified:

```text
Power On
   ↓
Firmware (UEFI/BIOS)
   ↓
Bootloader
   ↓
Kernel
   ↓
Init/system manager
   ↓
Services
   ↓
Login/Desktop
```

---

## 144. What is BIOS/UEFI?

Firmware that initializes hardware and starts the boot process.

Modern systems commonly use UEFI.

---

## 145. What is a bootloader?

A bootloader loads or starts the operating system kernel.

Example on Linux systems:

```text
UEFI → GRUB → Linux Kernel
```

---

## 146. What is virtualization?

Virtualization allows one physical machine to run multiple virtual machines.

```text
Physical Hardware
       |
     Hypervisor
   /      |      \
 VM1     VM2     VM3
```

---

## 147. What is a hypervisor?

A hypervisor manages virtual machines and allocates physical resources to them.

Types:

### Type 1

Runs directly on hardware.

```text
Hardware
   ↓
Hypervisor
   ↓
VMs
```

### Type 2

Runs on a host operating system.

```text
Hardware
   ↓
Host OS
   ↓
Hypervisor
   ↓
VMs
```

---

## 148. What is a container?

A container is an isolated user-space environment that shares the host OS kernel.

```text
Host Kernel
   |
   +-- Container A
   +-- Container B
   +-- Container C
```

Unlike a traditional VM, containers do not normally contain a complete separate guest kernel.

---

## 149. VM vs Container

| VM | Container |
|---|---|
| Virtualizes hardware/system | Shares host kernel |
| Guest OS included | Usually no separate kernel |
| More overhead | Usually lighter |
| Strong isolation boundary | Process-level isolation mechanisms |

---

## 150. What is the difference between an OS process and a container?

A process is an execution entity managed by the OS.

A container is an isolation/package mechanism that can contain one or more processes using OS features such as:

- Namespaces
- cgroups
- Filesystem isolation
- Capability restrictions

### Real-life analogy

A process is a worker.

A container is a **controlled workspace** in which one or more workers operate with limited resources and visibility.

---

# Operating System Math / Numerical Questions — 1–25

> These are especially useful for written exams and technical interviews.

---

## OS Math 1. Calculate turnaround time

A process arrives at time 2 and finishes at time 15.

### Formula

```text
Turnaround Time = Completion Time - Arrival Time
```

### Answer

```text
= 15 - 2
= 13
```

### Real-life analogy

You enter a restaurant at 2 PM and leave at 3 PM.

Your total time in the restaurant is your turnaround time.

---

## OS Math 2. Calculate waiting time

A process has:

```text
Turnaround = 13 ms
CPU Burst = 5 ms
```

### Formula

```text
Waiting Time = Turnaround - CPU Burst
```

### Answer

```text
13 - 5 = 8 ms
```

---

## OS Math 3. Calculate response time

Process arrives at time 4 and first gets CPU at time 9.

```text
Response Time = First CPU Start - Arrival
              = 9 - 4
              = 5 ms
```

### Analogy

You join a queue at 4 PM and a cashier first starts serving you at 4:05 PM.

---

## OS Math 4. FCFS scheduling

Processes:

```text
P1: Arrival 0, Burst 5
P2: Arrival 1, Burst 3
P3: Arrival 2, Burst 2
```

FCFS order:

```text
P1 → P2 → P3
```

Gantt chart:

```text
0     5     8    10
| P1  | P2  | P3 |
```

Waiting times:

```text
P1 = 0
P2 = 5 - 1 = 4
P3 = 8 - 2 = 6
```

Average waiting:

```text
(0 + 4 + 6) / 3
= 3.33 ms
```

---

## OS Math 5. FCFS turnaround

Using the previous example:

```text
P1 completion = 5
P2 completion = 8
P3 completion = 10
```

Turnaround:

```text
P1 = 5 - 0 = 5
P2 = 8 - 1 = 7
P3 = 10 - 2 = 8
```

Average:

```text
(5 + 7 + 8) / 3
= 6.67 ms
```

---

## OS Math 6. SJF scheduling

Processes arrive together:

```text
P1 = 8 ms
P2 = 2 ms
P3 = 4 ms
```

SJF order:

```text
P2 → P3 → P1
```

Gantt:

```text
0   2      6          14
|P2 |  P3  |    P1    |
```

Waiting:

```text
P2 = 0
P3 = 2
P1 = 6
```

Average:

```text
(0 + 2 + 6)/3
= 2.67 ms
```

---

## OS Math 7. Round Robin

Processes:

```text
P1 = 5 ms
P2 = 3 ms
P3 = 2 ms
Quantum = 2 ms
```

Order:

```text
P1 → P2 → P3 → P1 → P2 → P1
```

Timeline:

```text
0  2  4  6  8  9  10
|P1|P2|P3|P1|P2|P1|
```

Completion:

```text
P3 = 6
P2 = 9
P1 = 10
```

---

## OS Math 8. CPU utilization

Suppose CPU is busy for 90 seconds during a 100-second interval.

```text
CPU Utilization
= Busy / Total × 100

= 90/100 × 100
= 90%
```

---

## OS Math 9. Throughput

100 jobs complete in 20 seconds.

```text
Throughput = Completed Jobs / Time
           = 100 / 20
           = 5 jobs/sec
```

---

## OS Math 10. Context-switch overhead

A system performs 1000 context switches.

Each costs 2 microseconds.

```text
Total overhead
= 1000 × 2 μs
= 2000 μs
= 2 ms
```

---

## OS Math 11. Round Robin context switches

Suppose:

```text
Number of processes = 4
Each runs once per round
```

If each process is preempted after its quantum and continues later, there can be many context switches.

### Interview idea

Smaller quantum:

```text
More switches
More overhead
Better responsiveness
```

Larger quantum:

```text
Fewer switches
Less overhead
Can reduce responsiveness
```

---

## OS Math 12. Page offset bits

Page size:

```text
4 KiB = 4096 bytes
```

Since:

```text
4096 = 2^12
```

Offset bits:

```text
12 bits
```

### Answer

> A 4 KiB page has 12 offset bits.

---

## OS Math 13. Number of pages

Virtual address space:

```text
32-bit
```

Page size:

```text
4 KiB = 2^12
```

Number of pages:

```text
2^32 / 2^12
= 2^20
= 1,048,576 pages
```

---

## OS Math 14. Number of frames

Physical memory:

```text
1 GiB = 2^30 bytes
```

Page/frame size:

```text
4 KiB = 2^12 bytes
```

Frames:

```text
2^30 / 2^12
= 2^18
= 262,144 frames
```

---

## OS Math 15. Physical address calculation

Suppose:

```text
Page number = 5
Frame number = 10
Page size = 4096 bytes
Offset = 100
```

Physical address:

```text
Frame × Page Size + Offset

= 10 × 4096 + 100
= 41,060
```

---

## OS Math 16. Internal fragmentation

Memory block:

```text
8 KB
```

Process requests:

```text
6 KB
```

Waste:

```text
8 - 6 = 2 KB
```

Internal fragmentation = **2 KB**.

---

## OS Math 17. Page faults

A program makes:

```text
10,000 memory accesses
```

and:

```text
100 page faults
```

Page fault rate:

```text
100 / 10,000 × 100
= 1%
```

---

## OS Math 18. Effective memory access with page fault

Suppose:

```text
Normal memory access = 100 ns
Page fault service = 5 ms
Page fault rate = 0.001
```

Approximate effective access time:

```text
EAT ≈
(1 - 0.001)(100 ns)
+ (0.001)(5 ms + 100 ns)
```

Since 5 ms is:

```text
5,000,000 ns
```

Approximately:

```text
≈ 0.999 × 100
 + 0.001 × 5,000,100
≈ 100
 + 5000
≈ 5100 ns
```

### Key lesson

Even a tiny page-fault rate can dramatically increase effective memory access time because disk/storage access is much slower than RAM.

---

## OS Math 19. TLB effective access

Suppose:

```text
TLB lookup = 10 ns
Memory access = 100 ns
TLB hit ratio = 95%
```

Assume a TLB hit requires:

```text
TLB lookup + one memory access
= 10 + 100
= 110 ns
```

A miss requires:

```text
TLB lookup + page-table memory access + actual memory access
= 10 + 100 + 100
= 210 ns
```

EAT:

```text
0.95 × 110 + 0.05 × 210
= 104.5 + 10.5
= 115 ns
```

---

## OS Math 20. Disk seek calculation

Suppose a disk request requires:

```text
Seek = 5 ms
Rotation = 3 ms
Transfer = 1 ms
```

Total approximate service time:

```text
5 + 3 + 1
= 9 ms
```

---

## OS Math 21. Amdahl's Law

Suppose 40% of a program can be parallelized.

You have 4 processors.

Amdahl's Law:

```text
Speedup = 1 / [(1-P) + P/N]
```

Where:

```text
P = 0.4
N = 4
```

Therefore:

```text
1 / [0.6 + 0.4/4]
= 1 / 0.7
≈ 1.43
```

### Key lesson

Not all work can be parallelized, so adding CPUs does not produce unlimited speedup.

---

## OS Math 22. Maximum theoretical speedup

If 80% of a program is parallelizable and you have infinitely many processors:

```text
Speedup = 1 / (1 - 0.8)
        = 1 / 0.2
        = 5
```

Even infinite processors cannot exceed 5× speedup because 20% remains serial.

---

## OS Math 23. Banker-style resource check

Suppose a process:

```text
Maximum need = 10
Currently allocated = 6
```

Remaining need:

```text
10 - 6 = 4
```

If 4 additional units can be safely granted and later returned, the process may complete.

### Analogy

You owe a shop 10 items total, already have 6, so you need 4 more.

---

## OS Math 24. Semaphore permits

A connection pool has:

```text
10 connections
```

Semaphore:

```text
10
```

If 7 threads acquire one each:

```text
Remaining = 10 - 7
          = 3
```

Only three more threads can acquire a permit until one is released.

---

## OS Math 25. Memory allocation

RAM:

```text
16 GiB
```

OS uses:

```text
2 GiB
```

Applications use:

```text
10 GiB
```

Remaining:

```text
16 - 2 - 10
= 4 GiB
```

This does not automatically mean 4 GiB is immediately available to a specific process because the OS also manages caches, reservations, memory pressure, and other state.

---

# Networking Math / Numerical Questions — 26–50

## Networking Math 26. How many IPv4 addresses are in /24?

Formula:

```text
2^(32 - prefix)
```

For `/24`:

```text
2^(32-24)
= 2^8
= 256
```

Traditional usable host count:

```text
256 - 2 = 254
```

---

## Networking Math 27. How many addresses are in /25?

```text
2^(32-25)
= 2^7
= 128
```

Traditional usable:

```text
126
```

---

## Networking Math 28. How many addresses are in /26?

```text
2^(32-26)
= 2^6
= 64
```

Traditional usable:

```text
62
```

---

## Networking Math 29. How many addresses are in /27?

```text
2^(32-27)
= 2^5
= 32
```

Traditional usable:

```text
30
```

---

## Networking Math 30. How many addresses are in /28?

```text
2^(32-28)
= 2^4
= 16
```

Traditional usable:

```text
14
```

---

## Networking Math 31. How many addresses are in /30?

```text
2^(32-30)
= 2^2
= 4
```

Traditional usable:

```text
2
```

Common historical example:

```text
Router A ←→ Router B
```

---

## Networking Math 32. Find network address

IP:

```text
192.168.1.75/24
```

For `/24`, the first 24 bits are the network.

Network:

```text
192.168.1.0
```

Broadcast:

```text
192.168.1.255
```

Traditional host range:

```text
192.168.1.1
      ↓
192.168.1.254
```

---

## Networking Math 33. Find network address — /26

IP:

```text
192.168.1.75/26
```

A /26 has blocks of:

```text
64 addresses
```

Ranges:

```text
0–63
64–127
128–191
192–255
```

75 falls into:

```text
64–127
```

Therefore:

```text
Network = 192.168.1.64
Broadcast = 192.168.1.127
```

Traditional usable:

```text
192.168.1.65 – 192.168.1.126
```

---

## Networking Math 34. Find network address — /27

IP:

```text
192.168.1.100/27
```

Block size:

```text
32
```

Ranges:

```text
0–31
32–63
64–95
96–127
128–159
...
```

100 is in:

```text
96–127
```

Therefore:

```text
Network = 192.168.1.96
Broadcast = 192.168.1.127
```

---

## Networking Math 35. Find host range — /28

Network:

```text
192.168.10.32/28
```

Block size:

```text
16
```

Broadcast:

```text
32 + 15 = 47
```

Traditional usable range:

```text
192.168.10.33
       to
192.168.10.46
```

---

## Networking Math 36. Calculate bandwidth transfer time

File:

```text
100 MB
```

Network:

```text
100 Mbps
```

Convert file to megabits:

```text
100 MB × 8
= 800 Mb
```

Time:

```text
800 Mb / 100 Mbps
= 8 seconds
```

This is an idealized calculation; real throughput is lower due to protocol overhead and network conditions.

---

## Networking Math 37. 1 GB at 100 Mbps

Assume decimal:

```text
1 GB = 1000 MB
```

Convert:

```text
1000 × 8 = 8000 Mb
```

Time:

```text
8000 / 100
= 80 seconds
```

---

## Networking Math 38. Calculate RTT from ping

Suppose:

```text
Echo request sent at 10.000 s
Reply received at 10.040 s
```

RTT:

```text
10.040 - 10.000
= 0.040 sec
= 40 ms
```

---

## Networking Math 39. One-way delay

If a symmetric path has RTT:

```text
80 ms
```

A rough one-way propagation estimate is:

```text
80 / 2
= 40 ms
```

### Important

This assumes roughly symmetric delay. Real networks may have asymmetric paths and queueing.

---

## Networking Math 40. Bandwidth-delay product

Bandwidth:

```text
100 Mbps
```

RTT:

```text
50 ms
```

Formula:

```text
BDP = Bandwidth × RTT
```

Convert:

```text
100 Mbps × 0.05 sec
= 5 Mb
```

In bytes:

```text
5 Mb / 8
= 0.625 MB
```

### Meaning

Approximately 625 KB of data can be "in flight" during one RTT at full 100 Mbps utilization.

---

## Networking Math 41. Transmission time

Packet size:

```text
1500 bytes
```

Link:

```text
100 Mbps
```

Bits:

```text
1500 × 8
= 12,000 bits
```

Transmission time:

```text
12,000 / 100,000,000
= 0.00012 sec
= 0.12 ms
```

---

## Networking Math 42. Calculate packets per second

Data rate:

```text
100 Mbps
```

Packet size:

```text
1000 bytes
```

Bits per packet:

```text
1000 × 8
= 8000 bits
```

Packets/sec:

```text
100,000,000 / 8000
= 12,500 packets/sec
```

Idealized, ignoring protocol overhead.

---

## Networking Math 43. TCP throughput approximation

A simplified bandwidth-delay concept:

```text
Throughput ≈ Window Size / RTT
```

Suppose:

```text
Window = 1 MB
RTT = 100 ms
```

Then:

```text
1 MB / 0.1 sec
= 10 MB/s
```

Approximately:

```text
80 Mbps
```

Real TCP throughput depends on congestion control, loss, receiver window, implementation, and other factors.

---

## Networking Math 44. TCP window and BDP

Bandwidth:

```text
1 Gbps
```

RTT:

```text
20 ms
```

BDP:

```text
1,000 Mbps × 0.02
= 20 Mb
```

Bytes:

```text
20 / 8
= 2.5 MB
```

To fully utilize the link, the sender needs enough in-flight data to cover approximately this amount, subject to TCP/QUIC and network constraints.

---

## Networking Math 45. Subnetting a /24 into /26

Original:

```text
192.168.1.0/24
```

New:

```text
/26
```

Borrowed bits:

```text
26 - 24 = 2
```

Number of subnets:

```text
2^2 = 4
```

Each subnet:

```text
64 addresses
```

Subnets:

```text
192.168.1.0/26
192.168.1.64/26
192.168.1.128/26
192.168.1.192/26
```

---

## Networking Math 46. Subnetting a /24 into /28

Borrowed bits:

```text
28 - 24 = 4
```

Number of subnets:

```text
2^4 = 16
```

Each subnet:

```text
2^(32-28)
= 16 addresses
```

Traditional usable:

```text
14 hosts/subnet
```

---

## Networking Math 47. How many hosts are required?

Suppose an office needs:

```text
50 hosts
```

Find the smallest traditional IPv4 subnet.

Need:

```text
2^h - 2 >= 50
```

Try h = 5:

```text
32 - 2 = 30
```

Not enough.

Try h = 6:

```text
64 - 2 = 62
```

Enough.

Therefore:

```text
/26
```

because:

```text
32 - 6 = 26
```

---

## Networking Math 48. Transmission time for 10 MB

File:

```text
10 MB
```

Link:

```text
20 Mbps
```

Convert:

```text
10 × 8
= 80 Mb
```

Time:

```text
80 / 20
= 4 seconds
```

Ideal theoretical minimum:

```text
≈ 4 seconds
```

---

## Networking Math 49. Calculate latency from distance

Suppose a signal travels approximately:

```text
200,000 km/s
```

Distance:

```text
1000 km
```

Propagation time:

```text
1000 / 200,000
= 0.005 sec
= 5 ms
```

This is one-way propagation time under the simplified assumption.

Real network latency includes:

```text
Propagation
+ Transmission
+ Processing
+ Queueing
```

---

## Networking Math 50. Packet loss percentage

Suppose:

```text
Sent = 10,000 packets
Lost = 50 packets
```

Loss percentage:

```text
50 / 10,000 × 100
= 0.5%
```

### Real-life interpretation

Out of every 1000 packets, approximately 5 are lost.

---

# 🔥 Mixed OS + Networking Interview Numericals

These are excellent written-test style problems.

---

## Mixed Problem 1 — CPU + Network

A server receives:

```text
1000 requests/sec
```

Each request requires:

```text
2 ms CPU time
```

Total CPU demand:

```text
1000 × 2 ms
= 2000 ms/sec
= 2 CPU-seconds/sec
```

Therefore approximately:

```text
2 CPU cores
```

are needed for 100% CPU utilization under idealized assumptions.

For practical production capacity, additional headroom is normally required.

---

## Mixed Problem 2 — Database connection pool

A backend has:

```text
20 database connections
```

There are:

```text
100 concurrent requests
```

If every request needs a database connection simultaneously:

```text
20 served concurrently
80 wait
```

### Interview point

A connection pool limits database concurrency and prevents an application from opening unlimited connections.

---

## Mixed Problem 3 — Request latency

Suppose a request spends:

```text
DNS       = 10 ms
TCP/TLS   = 40 ms
Backend   = 30 ms
Database  = 20 ms
```

Approximate total:

```text
10 + 40 + 30 + 20
= 100 ms
```

If connection reuse eliminates 30 ms of setup:

```text
100 - 30
= 70 ms
```

---

## Mixed Problem 4 — CPU utilization

A server spends:

```text
70% CPU
20% I/O wait
10% idle
```

CPU utilization:

```text
70%
```

It does not mean the server is only "using 70% of its total capability" in every sense; workload bottlenecks can be elsewhere.

---

## Mixed Problem 5 — Concurrent requests

A service has:

```text
Average response time = 100 ms
Throughput = 1000 requests/sec
```

Using Little's Law:

```text
L = λW
```

Where:

```text
λ = 1000 requests/sec
W = 0.1 sec
```

Therefore:

```text
L = 1000 × 0.1
  = 100 concurrent requests
```

### Real-life analogy

If a restaurant serves 100 customers/minute and each customer stays 2 minutes:

```text
100 × 2 = 200
```

Approximately 200 customers are inside at a time under steady-state assumptions.

---

# Final Interview Cheat Sheet

## OS Core

```text
OS
 |
 +-- Process Management
 |     +-- Process
 |     +-- Thread
 |     +-- Scheduling
 |     +-- Context Switch
 |
 +-- Memory
 |     +-- Virtual Memory
 |     +-- Paging
 |     +-- Page Table
 |     +-- TLB
 |     +-- Page Fault
 |
 +-- Synchronization
 |     +-- Mutex
 |     +-- Semaphore
 |     +-- Critical Section
 |     +-- Race Condition
 |     +-- Deadlock
 |
 +-- Storage
 |     +-- File System
 |     +-- Inode
 |     +-- File Descriptor
 |
 +-- I/O
       +-- Interrupt
       +-- DMA
       +-- Driver
```

---

# Process vs Thread — Memorize

```text
PROCESS
+--------------------------+
| Separate address space   |
| Code                     |
| Heap                     |
| Files/resources          |
|                          |
| Thread 1                 |
| Thread 2                 |
| Thread 3                 |
+--------------------------+
```

> Process = resource/execution environment  
> Thread = execution unit inside a process

---

# Scheduling — Memorize

```text
FCFS
First come → First served

SJF
Shortest job → First

SRTF
Shortest remaining → First

RR
Everyone gets → Time quantum

Priority
Higher priority → First
```

---

# Synchronization — Memorize

```text
Race Condition
      ↓
Shared data accessed unsafely
      ↓
Incorrect result

Solution:
Mutex / Semaphore / Atomic / Proper synchronization
```

---

# Deadlock — Memorize

```text
1. Mutual Exclusion
2. Hold and Wait
3. No Preemption
4. Circular Wait
```

All four are required for classic deadlock.

---

# Memory — Memorize

```text
Virtual Address
      ↓
      MMU
      ↓
     TLB
      ↓
 Page Table
      ↓
Physical Frame
```

---

# Networking — Key Math Formulas

## IPv4 addresses

```text
Addresses = 2^(32 - prefix)
```

## Traditional usable hosts

```text
Usable = 2^host_bits - 2
```

## Host bits

```text
Host bits = 32 - prefix
```

## Subnets

If borrowing `n` bits:

```text
Subnets = 2^n
```

## Bandwidth transfer time

```text
Time = Data(bits) / Bandwidth(bits/sec)
```

## RTT

```text
RTT = Request→Destination + Destination→Source
```

## Bandwidth-delay product

```text
BDP = Bandwidth × RTT
```

## Packet loss

```text
Loss % = Lost / Sent × 100
```

---

# OS Key Math Formulas

## Turnaround

```text
Turnaround = Completion - Arrival
```

## Waiting

For the simple CPU-burst model:

```text
Waiting = Turnaround - CPU Burst
```

## Response

```text
Response = First CPU Start - Arrival
```

## Throughput

```text
Throughput = Completed Jobs / Time
```

## CPU utilization

```text
Utilization = Busy Time / Total Time × 100
```

## Amdahl's Law

```text
Speedup = 1 / [(1-P) + P/N]
```

## Page count

```text
Pages = Virtual Address Space / Page Size
```

## Frame count

```text
Frames = Physical Memory / Frame Size
```

## Physical address

```text
Physical Address = Frame × Page Size + Offset
```

---

# 🎯 10 OS Questions You Should Be Able to Answer Without Notes

1. What is an OS?
2. Kernel vs user mode?
3. Process vs thread?
4. What is context switching?
5. What is a system call?
6. What is virtual memory?
7. What is paging?
8. What is a race condition?
9. What is deadlock?
10. Mutex vs semaphore?

---

# 🎯 10 OS Hard Questions

1. Explain context switching and why it has overhead.
2. Explain `fork()` + `exec()`.
3. Explain zombie vs orphan process.
4. Explain virtual memory and page tables.
5. Explain TLB and TLB miss.
6. Explain page fault and thrashing.
7. Explain all four Coffman deadlock conditions.
8. Explain priority inversion.
9. Explain copy-on-write.
10. Explain process/thread synchronization.

---

# 🎯 10 Networking Math Questions to Practice

1. `/24` address count
2. `/26` address count
3. `/27` network calculation
4. `/28` subnet calculation
5. Required subnet for 50 hosts
6. File transfer time at 100 Mbps
7. RTT calculation
8. BDP calculation
9. Packet-loss percentage
10. Packets per second

---

# 🎯 10 OS Math Questions to Practice

1. Turnaround time
2. Waiting time
3. Response time
4. FCFS average waiting
5. SJF average waiting
6. Round Robin timeline
7. CPU utilization
8. Throughput
9. Page/frame calculation
10. Amdahl's Law

---

# 🏆 How to Answer in a Job Interview

Use this five-step structure:

```text
1. Definition
       ↓
2. How it works
       ↓
3. Visual/flow
       ↓
4. Real-life example
       ↓
5. Key interview point
```

### Example

**Question:** What is a deadlock?

**Strong answer:**

> Deadlock is a situation where two or more processes/threads are permanently waiting for resources held by one another. It requires four conditions: mutual exclusion, hold and wait, no preemption, and circular wait. For example, Thread A holds Lock 1 and waits for Lock 2, while Thread B holds Lock 2 and waits for Lock 1. Neither can continue.

This is better than simply saying:

> "Deadlock means processes are stuck."

---

# Final Study Strategy

## First Pass

Understand:

```text
Process
Thread
Scheduling
Memory
Synchronization
Deadlock
File System
I/O
```

## Second Pass

Practice:

```text
FCFS
SJF
RR
Paging
Page faults
Deadlock
Subnetting
Bandwidth
RTT
BDP
```

## Third Pass

Practice explaining real systems:

```text
Browser
   ↓
DNS
   ↓
Network
   ↓
Server
   ↓
Process/Thread
   ↓
Memory
   ↓
File/Database
```

## Final Goal

You should be able to answer:

> **"What happens from the moment a user clicks a button in a browser until the server returns the response?"**

A strong combined answer connects:

```text
Browser
  ↓
DNS
  ↓
TCP/QUIC
  ↓
TLS
  ↓
HTTP
  ↓
Network routing
  ↓
Load Balancer
  ↓
Backend process
  ↓
Threads/Event Loop
  ↓
System Calls
  ↓
Memory
  ↓
Database/File I/O
  ↓
Response
```

That single explanation demonstrates knowledge of **Networking + Operating Systems + Backend Engineering** together.
