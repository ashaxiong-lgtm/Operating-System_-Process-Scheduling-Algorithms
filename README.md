
# 🖥️ CPU Process Scheduling Algorithms with Aging

### Operating Systems | CPU Scheduling | Process Management | Starvation Prevention

A comprehensive implementation of **CPU Process Scheduling Algorithms** in Operating Systems, featuring both preemptive and non-preemptive scheduling techniques, along with an **Aging Mechanism** to address process starvation in Priority Scheduling.

This project demonstrates how different scheduling algorithms manage CPU resources, determine process execution order, and improve scheduling fairness and efficiency.

---

## 📌 Project Overview

CPU scheduling is a fundamental concept in Operating Systems that determines which process should execute next when multiple processes are ready for execution.

This project explores different CPU scheduling strategies, their execution behavior, and their performance based on various scheduling metrics.

A key highlight of this project is the implementation of **Priority Scheduling with Aging**, which dynamically adjusts process priorities to reduce the risk of indefinite waiting, also known as **Starvation**.

---

## 🚀 Implemented Scheduling Algorithms

The project includes the following seven scheduling approaches:

### 1. First Come, First Served (FCFS)
- Non-preemptive scheduling algorithm.
- Processes execute according to their arrival time.
- Simple and easy to implement.
- May suffer from the convoy effect.

### 2. Shortest Job First (SJF)
- Non-preemptive scheduling algorithm.
- Selects the process with the shortest CPU burst time.
- Minimizes average waiting time under suitable assumptions.
- Longer processes may experience starvation.

### 3. Shortest Remaining Time First (SRTF)
- Preemptive version of SJF.
- Selects the process with the shortest remaining execution time.
- A newly arrived process can preempt the currently running process.
- Improves average waiting time in many workloads.

### 4. Round Robin (RR)
- Preemptive scheduling algorithm.
- Each process receives a fixed time quantum.
- Processes are executed cyclically using a ready queue.
- Suitable for time-sharing systems.

### 5. Preemptive Priority Scheduling
- Processes are scheduled according to their assigned priorities.
- A higher-priority process can interrupt a running lower-priority process.
- Supports priority-based CPU allocation.
- Lower-priority processes may suffer from starvation.

### 6. Non-Preemptive Priority Scheduling
- Selects the highest-priority ready process.
- Once a process starts execution, it runs until completion or blocking.
- Does not interrupt the running process for a newly arrived higher-priority process.
- Starvation may occur for low-priority processes.

### 7. Priority Scheduling with Aging ⭐
- Introduces an aging mechanism into Priority Scheduling.
- Gradually increases the effective priority of waiting processes.
- Reduces the risk of indefinite postponement.
- Improves fairness among competing processes.
- Demonstrates a practical solution to process starvation.

---

## ⭐ Key Features

- Implementation of seven CPU scheduling approaches.
- Support for preemptive and non-preemptive scheduling.
- Priority-based process execution.
- Aging mechanism for starvation prevention.
- Process scheduling based on arrival and burst times.
- Waiting Time and Turnaround Time calculations.
- Comparison of different CPU scheduling strategies.
- Practical demonstration of Operating Systems concepts.

---

## 🧠 Understanding the Aging Mechanism

### What is Starvation?

Starvation occurs when a process waits indefinitely because other processes continuously receive CPU resources ahead of it.

In Priority Scheduling, low-priority processes may experience starvation if higher-priority processes continue to enter the ready queue.

### How Does Aging Solve Starvation?

**Aging** is a scheduling technique that gradually improves the priority of processes while they wait in the ready queue.

As a process waits longer, its effective priority increases, improving its chance of receiving CPU time.

### Example

Assume smaller priority numbers represent higher priority.

| Process | Initial Priority | Waiting Time | Updated Priority |
|---------|------------------|--------------|------------------|
| P1 | 2 | 0 | 2 |
| P2 | 5 | 10 | 3 |
| P3 | 8 | 20 | 4 |

*Note: Updated priorities are illustrative. Actual values depend on the aging interval and priority adjustment rules used in the implementation.*

### Benefits of Aging
- Reduces starvation.
- Improves process fairness.
- Provides opportunities for low-priority processes to execute.
- Balances priority-based scheduling with waiting time.

---

## 📊 Algorithm Comparison

| Algorithm | Scheduling Type | Selection Criteria | Starvation Risk |
|-----------|-----------------|--------------------|-----------------|
| FCFS | Non-Preemptive | Arrival Time | No typical priority starvation |
| SJF | Non-Preemptive | Shortest Burst Time | Yes |
| SRTF | Preemptive | Shortest Remaining Time | Yes |
| Round Robin | Preemptive | Time Quantum | Generally No |
| Preemptive Priority | Preemptive | Process Priority | Yes |
| Non-Preemptive Priority | Non-Preemptive | Process Priority | Yes |
| Priority with Aging | Depends on Implementation | Dynamic Priority | Reduced |

---

## 📐 Scheduling Performance Metrics

The following metrics are commonly used to evaluate CPU scheduling algorithms.

### Completion Time (CT)

The time at which a process finishes execution.

### Turnaround Time (TAT)

Total time elapsed between process arrival and completion.

**Formula:**

TAT = Completion Time - Arrival Time

### Waiting Time (WT)

Total time a process spends waiting in the ready queue.

For a process with a single CPU burst and no I/O blocking:

**Formula:**

WT = Turnaround Time - Burst Time

### Response Time (RT)

The time between process arrival and its first CPU allocation.

**Formula:**

RT = First Start Time - Arrival Time

### Average Waiting Time

Average WT = Sum of Waiting Times / Number of Processes

### Average Turnaround Time

Average TAT = Sum of Turnaround Times / Number of Processes

---

## 📝 Sample Process Data

The following is an illustrative input dataset for testing scheduling algorithms.

| Process | Arrival Time | Burst Time | Priority |
|---------|--------------|------------|----------|
| P1 | 0 | 8 | 3 |
| P2 | 1 | 4 | 1 |
| P3 | 2 | 9 | 4 |
| P4 | 3 | 5 | 2 |

The execution order and scheduling metrics vary depending on the selected algorithm.

---

## 🔄 General Scheduling Workflow

1. Initialize processes with their scheduling attributes.
2. Select the desired CPU scheduling algorithm.
3. Identify the ready processes based on arrival time.
4. Select the next process according to the algorithm.
5. Execute the process based on scheduling rules.
6. Apply preemption or time quantum when required.
7. Update waiting priorities when Aging is enabled.
8. Calculate the scheduling performance metrics.
9. Analyze the resulting process execution order.

---

## 🎯 Project Objectives

- Understand the fundamental principles of CPU scheduling.
- Implement different scheduling algorithms.
- Explore preemptive and non-preemptive process execution.
- Analyze waiting time and turnaround time.
- Understand the limitations of Priority Scheduling.
- Demonstrate how Aging helps prevent process starvation.
- Strengthen algorithmic thinking and problem-solving skills.

---

## 🧪 Testing and Evaluation

The algorithms can be evaluated using process datasets with different:

- Arrival times.
- CPU burst times.
- Priority levels.
- Time quantum values.
- Aging intervals.

Comparing the results helps demonstrate the advantages and limitations of each scheduling approach.

---

## 🔮 Future Improvements

Potential enhancements include:

- Interactive Gantt chart visualization.
- Graphical interface for process input.
- Real-time process execution visualization.
- Automated performance comparison.
- Exporting scheduling results.
- Interactive adjustment of aging intervals.
- Additional CPU scheduling algorithms.

---

## 📚 Concepts Covered

- Operating Systems
- CPU Scheduling
- Process Management
- Preemptive Scheduling
- Non-Preemptive Scheduling
- Ready Queue Management
- Process Starvation
- Aging Mechanism
- Scheduling Performance Metrics

---

## 👨‍💻 Author
SUMYA AKTER ASHA
Developed as an academic project to explore CPU Scheduling Algorithms and demonstrate practical problem-solving techniques in Operating Systems.


