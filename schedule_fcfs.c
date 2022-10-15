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

    // iterates through the linked list
    while (head){
        
        struct node *curr = head;

        while(curr->next != NULL){
            curr = curr->next;
        }

        run(curr->task, curr->task->burst);
        
        delete(&head, curr->task);
    }

}