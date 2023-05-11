#include <stdio.h>

#define MAX_PROCESSES 10

int arrival_time[MAX_PROCESSES];
int burst_time[MAX_PROCESSES];
int remaining_time[MAX_PROCESSES];
int wait_time[MAX_PROCESSES];
int turn_around_time[MAX_PROCESSES];

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    int time = 0;
    int quantum = 2;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    wait_time[i] = time - arrival_time[i] - burst_time[i];
                    turn_around_time[i] = time - arrival_time[i];
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }
    }

    int total_wait_time = 0;
    int total_turn_around_time = 0;

    for (int i = 0; i < n; i++) {
        total_wait_time += wait_time[i];
        total_turn_around_time += turn_around_time[i];
    }

    float avg_wait_time = (float) total_wait_time / n;
    float avg_turn_around_time = (float) total_turn_around_time / n;

    printf("Average wait time = %.2f\n", avg_wait_time);
    printf("Average turn around time = %.2f\n", avg_turn_around_time);

    return 0;
}
