#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *head = NULL;

void add(char * name, int priority, int burst) {
	
   	struct task *newTask = malloc(sizeof(struct task));
    newTask->name = name;
    newTask->burst = burst;
    newTask->priority = priority;
    
    insert(&head, newTask);
 
}

// invoke the scheduler
void schedule() {

	while(head){

		// intialize current node to head and shortest task
		struct node *curr = head;
		struct task *shortestTask = head->task;

		// loops through linked list
		while(curr){

			// checks for shortest burst
			if (curr->task->burst <= shortestTask->burst){

				shortestTask = curr->task;
			} 
			curr = curr->next;
		}

		run(shortestTask, shortestTask->burst);
		delete(&head, shortestTask);

	}

}