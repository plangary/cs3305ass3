/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* scheduler.c 
*
******************************************************************************/

#include "scheduler.h"


job_t *get_next_job(int mode, d_linked_list_t *jobs) {
    job_t *j;
    //pthread_mutex_t count_mutex= PTHREAD_MUTEX_INITIALIZER;
    //int smallest = 9999;






    if (mode == 0) { // FCFS
        j = dequeue(jobs);

    } else if (mode == 1) {//LIFO

        j = pop(jobs);


    } else if (mode == 2) {//SJF
        // pthread_mutex_lock(&count_mutex);

            struct d_node *smallest = jobs->head;
            struct d_node *current = smallest;

            int i;

        printf("HERE\n-----------");
            while (current->next != NULL) {

                i = ((job_t *) (current->value))->required_time;
                if (i < ((job_t *) (smallest->value))->required_time) {
                    smallest = current;
                }
                current = current->next;

            }
        //printf("SMALLEST IS: ------------%d\n", ((job_t*)smallest->value)->required_time);
            j = ((job_t *) smallest->value);
            erase(jobs, smallest);


    } else {//RR
        j = dequeue(jobs);


    }


    return j;
}

