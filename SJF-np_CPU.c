#include <stdio.h>
#include <limits.h>

struct Process {
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
  int completed;
};

int find_shortest_job(struct Process processes[], int n, int current_time) {
  int shortest_job = -1;
  int shortest_job_burst_time = INT_MAX;

  for(int i=0; i<n; i++) {
    if(processes[i].completed == 0 && processes[i].arrival_time <= current_time && processes[i].burst_time < shortest_job_burst_time) {
      shortest_job = i;
      shortest_job_burst_time = processes[i].burst_time;
    }
  }

  return shortest_job;
}

int main() {
  int n, i, j;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process processes[n];
  float avg_waiting_time = 0, avg_turnaround_time = 0;

  // Take input from user for Arrival Time and Burst Time for each process
  for(i=0; i<n; i++) {
    printf("Enter Arrival Time and Burst Time for process P%d: ", i+1);
    scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    processes[i].completed = 0;
  }

  int current_time = 0;
  int completed_processes = 0;

  // Process the jobs in SJF order until all jobs are completed
  while(completed_processes < n) {
    int shortest_job = find_shortest_job(processes, n, current_time);

    if(shortest_job == -1) {
      current_time++;
      continue;
    }

    // Process the shortest job
    current_time += processes[shortest_job].burst_time;
    processes[shortest_job].turnaround_time = current_time - processes[shortest_job].arrival_time;
    processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
    processes[shortest_job].completed = 1;
    avg_waiting_time += processes[shortest_job].waiting_time;
    avg_turnaround_time += processes[shortest_job].turnaround_time;

    completed_processes++;
  }

  // Calculate average waiting time and average turnaround time
  avg_waiting_time /= n;
  avg_turnaround_time /= n;

  // Display Gantt Chart
  printf("\nGantt Chart:\n");
  for(i=0; i<n; i++) {
    printf("  P%d  ", i+1);
  }
  printf("\n");
  for(i=0; i<n; i++) {
    printf("|-----");
  }
  printf("|\n");
  current_time = 0;
  while(completed_processes < n) {
    int shortest_job = find_shortest_job(processes, n, current_time);

    if(shortest_job == -1) {
      current_time++;
      continue;
    }

    // Process the shortest job
    printf("|  P%d  ", shortest_job+1);
    current_time += processes[shortest_job].burst_time;
    completed_processes++;
  }
  printf("|\n");
  for(i=0; i<n; i++) {
    printf("|-----");
  }
  printf("|\n");

  // Display Turnaround Time, Waiting Time and average Turnaround Time & Waiting Time for each process
  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0; i<n; i++) {
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
}
printf("Average Waiting Time: %.2f\n", avg_waiting_time);
printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

return 0;
}