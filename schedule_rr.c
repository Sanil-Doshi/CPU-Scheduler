
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *head = NULL;

void add(char *name, int priority, int burst) {

	struct task *newTask = malloc(sizeof(struct task));
    newTask->name = name;
    newTask->burst = burst;
    newTask->priority = priority;

    insert(&head, newTask);
}

void schedule() {

	struct node *curr = head;
	int difference;

	while(head){

		// finding remaining burst
		if (QUANTUM < curr->task->burst){
			difference = QUANTUM;
		} else {
			difference = curr->task->burst;
		}
		
		run(curr->task, difference);
		curr->task->burst -= difference;

		// only deleting task with no burst
		if(!curr->task->burst) {
			delete(&head, curr->task);
		}
		
		if (curr->next){
			curr = curr->next;
		} else {
			curr = head;
		}
	}
}



