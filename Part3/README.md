# Reasons for concurrency and parallelism


To complete this exercise you will have to use git. Create one or several commits that adds answers to the following questions and push it to your groups repository to complete the task.

When answering the questions, remember to use all the resources at your disposal. Asking the internet isn't a form of "cheating", it's a way of learning.

 ### What is concurrency? What is parallelism? What's the difference?
 Concurrency: Out of order/partial order execution of different parts of an instance where the final outcome is the same.
  Dealing with lots of things at once.
  Handling and executing multiple task with shared resources. 
  
 Parallelism: Multiple instances of the same task runs independently at the same time with different data. 
  Doing lots of things at once.
  
 ### Why have machines become increasingly multicore in the past decade?
 Limitation in single core processors design such as:
  Number of transistors per unit area (Problem designing transistors with size < 10 nm)
  Limit in clock speed (Problem with heat dissipation and reduced power efficiency) 
 
 - Dealing with these limitations and providing increasing performance through multi-core design.  

 ### What kinds of problems motivates the need for concurrent execution?
 (Or phrased differently: What problems do concurrency help in solving?)
 When several tasks need to be performed on some shared resource. 
 Transactions problems.
 
 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 
 Concurrency in programs can increase the performance as opposed to serial execution. 
 - Enabling the program to deal with lots of thing at once. 
 - By combining concurrency with parallelism good performance can be achieved.     
 
 Can make the programmer’s life harder in the sense of:
 - Introduction of heisenbugs (subtle and hard to detect bugs)
 - Harder to design and making the program robust.
 - Race condition (abnormal behaviour observed in part 4)

 ### What are the differences between processes, threads, green threads, and coroutines?
 Process: providing resources needed for execution a program or a task.
  - Its own memory space, data, stack.

 Thread: entity within a process. 
  - Threads in a process share the same resources. 
  - Executing some part of the process code.
 
 ### Which one of these do `pthread_create()` (C/POSIX), `threading.Thread()` (Python), `go` (Go) create?
 > *Your answer here*
 
 ### How does pythons Global Interpreter Lock (GIL) influence the way a python Thread behaves?
 > *Your answer here*
 
 ### With this in mind: What is the workaround for the GIL (Hint: it's another module)?
 > *Your answer here*
 
 ### What does `func GOMAXPROCS(n int) int` change? 
 > *Your answer here*
