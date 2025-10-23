#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


struct Process {
    int pid;
    int priority;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    struct Process *next;
};

struct Process *head = NULL;

void traverse(struct Process *head); 
void append(struct Process *head, struct Process *newProcess) ;
void sortByArrivalTime(struct Process *head);
void addProcess(int pid, int arrival, int burst);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int arrival, burst;
        printf("Enter arrival time for P%d: ", i);
        scanf("%d", &arrival);
        printf("Enter burst time for P%d: ", i);
        scanf("%d", &burst);

        addProcess(i, arrival, burst);
    }

    traverse(head); //printing the linked list before sorting

    sortByArrivalTime(head);
    printf("After sorting by arrival time:\n");
    traverse(head); //print after sorting
    return 0;
}



void traverse(struct Process *head){
    struct Process *current = head;
    printf("-----Printing the linked list of processes-----\n");

while (current != NULL) {
    printf("PID: %d\n", current->pid); //or (*current).pid syntax
    current = current->next;
}
printf("-----------------------------\n");

}

void addProcess(int pid, int arrival, int burst) {
    // the new process will be added at the end of linekd list

    struct Process *newP = malloc(sizeof(struct Process)); 
    //used malloc, because if we create a new pricess like this "struct Process newP;"" it will be stored as local variable on the stack, and will be destroyed after the function returns(after stack frame is cleaned up)
    newP.pid = pid;
    newP->pid = pid;
    newP->arrival_time = arrival;
    newP->burst_time = burst;
    newP->next = NULL;

    if (head == NULL) {
        head = newP;
    } else {
        struct Process *temp = head; 
        while (temp->next != NULL)
            temp = temp->next; // running to the end of the linkked list and adding the new process there
        temp->next = newP;
    }
}

// void append(struct Process *head, struct Process *newProcess) {
//     struct Process *current = head;

//     while (current->next != NULL) {
//         current = current->next;
//     }
//     current->next = newProcess;
//     newProcess->next = NULL;
// }



void sortByArrivalTime(struct Process *head) { //bubble sort approach: it can be slow for a large number of processes.
    //time complexity: O(n^2)
    struct Process *i, *j;
    int temp_int;
    char temp_state[10];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->arrival_time > j->arrival_time) {

                //swapping each process's struct variables

                // swap pid
                temp_int = i->pid;
                i->pid = j->pid;
                j->pid = temp_int;

                // swap priority
                temp_int = i->priority;
                i->priority = j->priority;
                j->priority = temp_int;

                // swap arrival_time
                temp_int = i->arrival_time;
                i->arrival_time = j->arrival_time;
                j->arrival_time = temp_int;

                // swap burst_time
                temp_int = i->burst_time;
                i->burst_time = j->burst_time;
                j->burst_time = temp_int;

                // swap waiting_time
                temp_int = i->waiting_time;
                i->waiting_time = j->waiting_time;
                j->waiting_time = temp_int;

                // swap turnaround_time
                temp_int = i->turnaround_time;
                i->turnaround_time = j->turnaround_time;
                j->turnaround_time = temp_int;

                // swap response_time
                temp_int = i->response_time;
                i->response_time = j->response_time;
                j->response_time = temp_int;

            }
        }
    }
}


double avgWaitingTime(struct Process *head) {
    double totalWaiting = 0.0;
    double accumulatedBurst = 0.0;
    int processCount = 0;
    struct Process *current = head;

    while (current != NULL) {
        current->waiting_time = accumulatedBurst;  // assign waiting time
        totalWaiting += current->waiting_time;     // sum
        accumulatedBurst += current->burst_time;   // update for next process
        processCount++;
        current = current->next;
    }

    return totalWaiting / processCount;
}
double avgTurnaroundTime(struct Process *head) {
    double totalTurnaround = 0.0;
    int processCount = 0;
    struct Process *current = head;

    while (current != NULL) {
        current->turnaround_time = current->waiting_time + current->burst_time; // assign turnaround time
        totalTurnaround += current->turnaround_time;                            // sum
        processCount++;
        current = current->next;
    }

    return totalTurnaround / processCount;
}

void freeList(struct Process *head){
    struct Process *current = head;
    
        while(current != NULL){
            next = current->next; //saving the current Process's next pointer because after free() it will be purged.
            free(current);
            current = next;
        }
    
}
