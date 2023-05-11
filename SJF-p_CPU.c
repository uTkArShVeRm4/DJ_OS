#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;            // Process ID
    int arrival_time;   // Arrival Time
    int burst_time;     // Burst Time
    int remaining_time; // Remaining Burst Time
};

int main() {
    int num_processes, i, j;
    float avg_wait_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];
    int waiting_time[num_processes];
    int turnaround_time[num_processes];
    int completed[num_processes];

    // Taking input for arrival time and burst time for each process
    for (i = 0; i < num_processes; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        waiting_time[i] = 0;
        completed[i] = 0;
    }

    int current_time = 0;
    int total_time = 0;
    int shortest_job = -1;
    int shortest_time = 999999;
    int prev_shortest_job = -1;

    while (1) {
        shortest_job = -1;
        shortest_time = 999999;

        // Finding the process with shortest remaining burst time
        for (i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time && completed[i] != 1) {
                shortest_job = i;
                shortest_time = processes[i].remaining_time;
            }
        }

        // If there is no process available at current time, increase current time
        if (shortest_job == -1) {
            current_time++;
            continue;
        }

        // If the shortest remaining burst time process is different from previous shortest process, update waiting time of all the waiting processes
        if (prev_shortest_job != shortest_job && prev_shortest_job != -1) {
            for (i = 0; i < num_processes; i++) {
                if (completed[i] == 0 && processes[i].arrival_time <= current_time && i != shortest_job) {
                    waiting_time[i]++;
                }
            }
        }

        // Decrease the remaining burst time of the current process
        processes[shortest_job].remaining_time--;

        // If remaining burst time of the current process becomes 0, calculate waiting time and turnaround time, mark process as completed
        if (processes[shortest_job].remaining_time == 0) {
            // Calculate waiting time
            waiting_time[shortest_job] = current_time - processes[shortest_job].arrival_time - processes[shortest_job].burst_time + 1;

            // Calculate turnaround time
            turnaround_time[shortest_job] = waiting_time[shortest_job] + processes[shortest_job].burst_time;

            // Update total time
            total_time += turnaround_time[shortest_job];

            // Mark process as completed
            completed[shortest_job] = 1;
        }

        // Update previous shortest job
        prev_shortest_job = shortest_job;

        // Update current time
        current_time++;

        // Check if all processes are completed
        int flag = 1;
        for (i = 0; i < num_processes; i++) {
            if (completed[i] == 0) {
                flag = 0;
                break;
            }
        }
            // If all processes are completed, break the loop
    if (flag == 1) {
        break;
    }
}

// Calculate average waiting time and average turnaround time
avg_wait_time = (float)total_time / num_processes;
avg_turnaround_time = (float)total_time / num_processes;

// Display the waiting time, turnaround time, average waiting time, and average turnaround time for each process
printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (i = 0; i < num_processes; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
}
printf("Average waiting time: %f\n", avg_wait_time);
printf("Average turnaround time: %f\n", avg_turnaround_time);

return 0;
}
