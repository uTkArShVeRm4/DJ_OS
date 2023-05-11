#include <stdio.h>

struct Process {
  int pid;  
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
};

int compare_arrival_time(const void *a, const void *b) {
  const struct Process *p1 = (struct Process *)a;
  const struct Process *p2 = (struct Process *)b;
  return p1->arrival_time - p2->arrival_time;
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
    processes[i].pid = i+1;
  }

  // Sort processes based on arrival time
  qsort(processes, n, sizeof(struct Process), compare_arrival_time);

  // Calculate waiting time and turnaround time for each process
  processes[0].waiting_time = 0;
  for(i=1; i<n; i++) {
    processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
  }

  for(i=0; i<n; i++) {
    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    avg_waiting_time += processes[i].waiting_time;
    avg_turnaround_time += processes[i].turnaround_time;
  }

  // Calculate average waiting time and average turnaround time
  avg_waiting_time /= n;
  avg_turnaround_time /= n;

  // Display Gantt Chart
  printf("\nGantt Chart:\n");
  for(i=0; i<n; i++) {
    printf("  P%d  ", processes[i].pid);
  }
  printf("\n");
  for(i=0; i<n; i++) {
    printf("|-----");
  }
  printf("|\n");
  int start_time = 0;
  for(i=0; i<n; i++) {
    printf("|  %d  ", start_time);
    start_time += processes[i].burst_time;
  }
  printf("|\n");
  for(i=0; i<n; i++) {
    printf("|-----");
  }
  printf("|\n");

  // Display Turnaround Time, Waiting Time and average Turnaround Time & Waiting Time for each process
  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0; i<n; i++) {
    printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
  }

  printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
  printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);

  return 0;
}
