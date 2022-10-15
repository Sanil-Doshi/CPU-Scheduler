
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *head[MAX_PRIORITY + 1];

void add(char *name, int priority, int burst) {

	struct task *newTask = malloc(sizeof(struct task));
    newTask->name = name;
    newTask->burst = burst;
    newTask->priority = priority;

    insert(&head[priority], newTask);

}

void schedule() {

	// finding the priority
	for(size_t p = MAX_PRIORITY; p >= MIN_PRIORITY; --p){

		struct node *curr = head[p];
		int difference;

		while(head[p]){

			// finding remaining burst
			if (QUANTUM < curr->task->burst){
				difference = QUANTUM;
			} else {
				difference = curr->task->burst;
			}

			run(curr->task, difference);

			curr->task->burst -= difference;

			// deleting task if no burst left
			if(!curr->task->burst) {
				delete(&head[p], curr->task);
			}

			if (curr->next){
				curr = curr->next;
			} else {
				curr = head[p];
			}
		}	
	}
}



