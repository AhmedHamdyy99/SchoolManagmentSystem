
#include "header2.h"

//call back function
void wrapper(Queue *pq,int32_t choice){

//array of pointers to functions
void (*fun_ptr_arr[6])(Queue *pq) = { New_Student,Delete_Student,Student_Edit,Student_List,Rank_Student,Student_Score };

(*fun_ptr_arr[choice])(pq);

}


//function to create the queue
void CreateQueue(Queue *pq){
   pq->front=NULL;
   pq->rear=NULL;
   pq->size=0;
   }


//bubble sorting alphabetically
void bubble_sorting(Queue *pq){

student s_temp;
int32_t i,j;

QueueNode* pn=pq->front;  //pointer to first node
QueueNode* pn2=pn->next;  //pointer to second node

for (i=0;i<(pq->size);i++){  //Sorting names by bubble sort
 for (j=0;j<(pq->size-1);j++){
  if (strcmp(pn2->entry.name,pn->entry.name)<0){// compare two names and swap if 2nd name has higher order
       s_temp=pn->entry;
        pn->entry=pn2->entry;
        pn2->entry=s_temp;
      }
   pn=pn->next;      //set pointers to next two compare next two nodes
   pn2=pn2->next;
 }
pn=pq->front;
pn2=pn->next;      //set pointers to beginning of list
  }
}



