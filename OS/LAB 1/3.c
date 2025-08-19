#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void fcfs(Process processes[], int n);
void sjf(Process processes[], int n);
void priority(Process processes[], int n);
void round_robin(Process processes[], int n, int quantum);
void print_results(Process processes[], int n);
void reset_remaining_time(Process processes[], int n);

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        processes[i].pid = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    do {
        printf("\nScheduling Algorithms:\n");
        printf("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                reset_remaining_time(processes, n);
                fcfs(processes, n);
                print_results(processes, n);
                break;
            case 2:
                reset_remaining_time(processes, n);
                sjf(processes, n);
                print_results(processes, n);
                break;
            case 3:
                reset_remaining_time(processes, n);
                priority(processes, n);
                print_results(processes, n);
                break;
            case 4:
                printf("Enter time quantum: ");
                scanf("%d", &quantum);
                reset_remaining_time(processes, n);
                round_robin(processes, n, quantum);
                print_results(processes, n);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}

void reset_remaining_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void fcfs(Process processes[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    for(int i = 0; i < n; i++) {
        if(current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0;
    while(completed < n) {
        int shortest = -1, min_burst = 9999;

        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && processes[i].remaining_time < min_burst) {
                min_burst = processes[i].remaining_time;
                shortest = i;
            }
        }

        if(shortest == -1) {
            current_time++;
            continue;
        }

        processes[shortest].remaining_time = 0;
        current_time += processes[shortest].burst_time;
        processes[shortest].turnaround_time = current_time - processes[shortest].arrival_time;
        processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
        completed++;
    }
}

void priority(Process processes[], int n) {
    int completed = 0, current_time = 0;
    while(completed < n) {
        int highest_priority = -1, min_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && processes[i].priority < min_priority) {
                min_priority = processes[i].priority;
                highest_priority = i;
            }
        }

        if(highest_priority == -1) {
            current_time++;
            continue;
        }

        processes[highest_priority].remaining_time = 0;
        current_time += processes[highest_priority].burst_time;
        processes[highest_priority].turnaround_time = current_time - processes[highest_priority].arrival_time;
        processes[highest_priority].waiting_time = processes[highest_priority].turnaround_time - processes[highest_priority].burst_time;
        completed++;
    }
}

void round_robin(Process processes[], int n, int quantum) {
    int remaining = n, current_time = 0;

    while(remaining > 0) {
        int did_execute = 0;
        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                int exec_time = (processes[i].remaining_time > quantum) ? quantum : processes[i].remaining_time;
                processes[i].remaining_time -= exec_time;
                current_time += exec_time;
                did_execute = 1;

                if(processes[i].remaining_time == 0) {
                    remaining--;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }
            }
        }
        if (!did_execute) {
            current_time++;
        }
    }
}

void print_results(Process processes[], int n) {
    float avg_wait = 0, avg_turnaround = 0;
    printf("\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n",
            processes[i].pid,
            processes[i].arrival_time,
            processes[i].burst_time,
            processes[i].priority,
            processes[i].waiting_time,
            processes[i].turnaround_time);
        avg_wait += processes[i].waiting_time;
        avg_turnaround += processes[i].turnaround_time;
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wait / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround / n);
}