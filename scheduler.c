/******************************************************************************
* 
* Name: 	Pouya Langary - 250798366
* Email: 	plangary@uwo.ca
*
* scheduler.c 
*
******************************************************************************/

#include "scheduler.h"
#include "d_linked_list.h"


job_t *get_next_job(int mode, d_linked_list_t *jobs) {
    job_t *j;
    if (jobs->size == 0) // return NULL if job size is 0 to prevent running null job/segmentation fault
        return NULL;

    if (mode == 0) { // FCFS - Dequeue first element of the list
        j = dequeue(jobs);

    } else if (mode == 1) {//LIFO - pop off top of list

        j = pop(jobs);


    } else if (mode == 2) {//SJF

        struct d_node *smallest = jobs->head;    // set smallest, current, and toDelete nodes as head
        struct d_node *current = smallest;
        struct d_node *toDelete = smallest;
        int i;


        while (current != NULL) {  // iterate through list and find job with the smallest time and set smallest

            i = ((job_t *) (current->value))->required_time;
            if (i < ((job_t *) (smallest->value))->required_time) {
                smallest = current;

            }

            current = current->next;

        }


        toDelete = smallest; // set the value to be deleted as smallest
        j = ((job_t *) smallest->value); // cast smallest node to type job_t* and set to j


        erase(jobs, toDelete); // delete node from the list


    } else {//RR
        j = dequeue(jobs);


    }

    return j;

}

