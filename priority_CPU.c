#include<stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
};

int main() {
    int i, j, num_processes, current_time, completed_processes, shortest_job;
    float total_waiting_time = 0, total_turnaround_time = 0;
    struct process processes[50];
    int completed[50] = {0}, waiting_time[50] = {0}, turnaround_time[50] = {0}, remaining_burst_time[50] = {0};
    int highest_priority_job, prev_highest_priority_job = -1;

    // Read input
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    for (i = 0; i < num_processes; i++) {
        printf("Enter arrival time, burst time and priority for process %d: ", i+1);
        scanf("%d%d%d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i+1;
        remaining_burst_time[i] = processes[i].burst_time;
    }

    // Sort processes by arrival time
    for (i = 0; i < num_processes-1; i++) {
        for (j = 0; j < num_processes-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                struct process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Schedule processes
    current_time = 0;
    completed_processes = 0;
    while (completed_processes < num_processes) {
        // Find the process with the highest priority
        highest_priority_job = -1;
        for (i = 0; i < num_processes; i++) {
            if (completed[i] == 0 && processes[i].arrival_time <= current_time) {
                if (highest_priority_job == -1 || processes[i].priority < processes[highest_priority_job].priority ||
                    (processes[i].priority == processes[highest_priority_job].priority && remaining_burst_time[i] < remaining_burst_time[highest_priority_job])) {
                    highest_priority_job = i;
                }
            }
        }

        // If a process is found
        if (highest_priority_job != -1) {
            // Update waiting time of waiting processes
            if (prev_highest_priority_job != highest_priority_job && prev_highest_priority_job != -1) {
                for (i = 0; i < num_processes; i++) {
                    if (completed[i] == 0 && processes[i].arrival_time <= current_time && i != highest_priority_job) {
                        waiting_time[i]++;
                    }
                }
            }

            // Execute the process for one unit of time
            remaining_burst_time[highest_priority_job]--;
            current_time++;

            // If the process is completed
            if (remaining_burst_time[highest_priority_job] == 0) {
                completed[highest_priority_job] = 1;
                completed_processes++;
                turnaround_time[highest_priority_job] = current_time - processes[highest_priority_job].arrival_time;
                waiting_time[highest_priority_job] = turnaround_time[highest_priority_job] - processes[highest_priority_job].burst_time;
                total_waiting_time += waiting_time[highest_priority_job];
                total_turnaround_time += turnaround_time[highest_priority_job];
            }
            prev_highest_priority_job = highest_priority_job;
        }
        // If no process is found, move to next second
        else {
        current_time++;
        }
    }
    // Print the schedule and average waiting time and turnaround time
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", total_waiting_time/num_processes);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time/num_processes);

    return 0;
}    
