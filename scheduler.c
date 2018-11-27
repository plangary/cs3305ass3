/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* scheduler.c 
*
******************************************************************************/

#include "scheduler.h"


job_t *get_next_job(int mode, d_linked_list_t* jobs) {
	job_t *j;




        if (mode ==0){ // FCFS
            j = dequeue(jobs);

        }
    else if(mode==1){//LIFO

            j = pop(jobs);


        }

    else if(mode ==2){//SJF
            job_t * temp;
            job_t *temp2;
            d_linked_list_t * tempJobs;
            job_t *smallest = dequeue(jobs);
            enqueue(jobs,smallest);


            for (int i = 0; i <jobs->size ; i++) {
                temp = pop(jobs);
                if(smallest->required_time < temp->required_time){
                    smallest = temp;
                }

                enqueue(tempJobs, temp);


            }
            for (int k = 0; k <jobs->size ; k++) {
                temp2 = pop(jobs);
                while(temp2!=smallest) {
                    temp2 = dequeue(jobs);
                    //temp2 = pop(jobs);
                    enqueue(jobs,temp2);
                }


            }



            jobs = dequeue(jobs);



        }


    else if(mode ==3){//RR






        }






    return j;
}
