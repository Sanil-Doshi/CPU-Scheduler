#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *head = NULL;

void add(char *name, int priority, int burst) {
    
    // making a new task
    struct task *newTask = malloc(sizeof(struct task));
    
    newTask->name = name;
    newTask->burst = burst;
    newTask->priority = priority;
    
    insert(&head, newTask);

}

void schedule() {

    while(head){

		// intialize current node to head and shortest task
		struct node *curr = head;
		struct task *highestPriority = head->task;

		// loops through linked list
		while(curr){

			// checks for shortest burst
			if (curr->task->priority <= highestPriority->priority){

			highestPriority = curr->task;
			} 
			curr = curr->next;
		}

		run(highestPriority,highestPriority->priority);
		delete(&head,highestPriority);

	}

}