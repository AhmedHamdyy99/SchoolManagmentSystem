#include "header.h"
#include "header2.h"


//function to show main menu
void Main_Menu(Queue *pq){

//Local Variables
int32_t choice;

//show Home Screen
printf("\t\t\t\t\t********************************\n");
printf("\t\t\t\t\tWelcome to School Managment System \n");
printf("\t\t\t\t\t********************************\n");
printf("0-Add New Student \n1-Delete Existing Student\n2-Edit Student Data \n3-Sort Students Alphabetically \n4-Rank Students According to score \n5-Update Score \n \n");
printf("please enter your choice \n");
scanf("%d",&choice);

 if (choice>5)
    printf("invalid choice please enter a no. from 0 to 5 \n");
 else
    //(*fun_ptr_arr[choice])(pq);
    wrapper(pq,choice);

   }


//function to add new student
 void New_Student(Queue *pq){

QueueNode *pn=(QueueNode*)malloc(sizeof(QueueNode));
pn->next=NULL;

printf("******************\n");
printf("Please enter the name of the student\n");
fflush(stdin);
gets(pn->entry.name);
printf("Please enter the ID of the student\n");
scanf("%hu",&pn->entry.ID);
printf("Please enter the address of the student\n");
fflush(stdin);
gets(pn->entry.address);
printf("Please enter the birthday of the student\n");
scanf("%s",pn->entry.birthday);
printf("Please enter the phone number of the student\n");
scanf("%lu",&pn->entry.phone_num);
printf("Please enter the Embedded Score of the student (form 0 to 100)\n");
scanf("%d",&pn->entry.EmbeddedScore);
//printf("pn pointe = %p \n",pn);
if (!pq->rear) //check if queue is empty
    pq->front=pn;
else
   pq->rear->next=pn;

pq->rear=pn;
pq->size++;

//printing data of student
printf("********************\n");
printf("the name of student is: %s \n",pn->entry.name);
printf("the ID of student is: %hu \n",pn->entry.ID);
printf("the address of student is: %s \n",pn->entry.address);
printf("the birthday of student is: %s \n",pn->entry.birthday);
printf("the Phone Number of student is: %lu \n",pn->entry.phone_num);
printf("the EmbeddedScore of student is: %d \n",pn->entry.EmbeddedScore);

}


//function to delete student
 void Delete_Student(Queue *pq){

printf("***************\n");
int8_t str[SIZE];
int32_t i,x,y;
QueueNode *pn=pq->front;
QueueNode *pn2;


if (pq->size==0){
printf("The list is Empty please enter the student data \n");
}

else{
printf("Enter the name of the student you want to delete \n");
fflush(stdin);
gets(str);
if (!pq->front->next){   //if the list have one node
 if (strcmp(str,pn->entry.name)==0){
     printf("*******************\n");
    printf("the name of student that will be deleted is %s \n",pn->entry.name);
    printf("the ID of student that will be deleted is %hu \n",pn->entry.ID);
    printf("the address of student that will be deleted is %s \n",pn->entry.address);
    printf("the birthday of student that will be deleted is %s \n",pn->entry.birthday);
    printf("the phone Number of student that will be deleted is %lu \n",pn->entry.phone_num);
    printf("the EmbeddedScore of student that will be deleted is %d \n",pn->entry.EmbeddedScore);
       pq->rear=NULL;
       free(pn);
       pq->size--;
}
else {
    printf("not found name\n");
}
}

for (i=0;i<(pq->size-1);i++){   //if the list have more than one node
   pn2=pn->next;
   x= strcmp(str,pn->entry.name);
   y= strcmp(str,pn2->entry.name);
   if (x==0){  //if the name was found in the first node
    pq->front=pn->next;
      printf("***************\n");
     printf("the name of student that will be deleted is %s \n",pn->entry.name);
    printf("the ID of student that will be deleted is %hu \n",pn->entry.ID);
    printf("the address of student that will be deleted is %s \n",pn->entry.address);
    printf("the birthday of student that will be deleted is %s \n",pn->entry.birthday);
    printf("the phone Number of student that will be deleted is %lu \n",pn->entry.phone_num);
    printf("the EmbeddedScore of student that will be deleted is %d \n",pn->entry.EmbeddedScore);
    free(pn);
    pq->size--;
   }

else if (y==0){   // if the name was found in any node
    pn->next=pn2->next;
    printf("***************\n");
     printf("the name of student that will be deleted is %s \n",pn2->entry.name);
    printf("the ID of student that will be deleted is %hu \n",pn2->entry.ID);
    printf("the address of student that will be deleted is %s \n",pn2->entry.address);
    printf("the birthday of student that will be deleted is %s \n",pn2->entry.birthday);
    printf("the phone Number of student that will be deleted is %lu \n",pn2->entry.phone_num);
    printf("the EmbeddedScore of student that will be deleted is %d \n",pn2->entry.EmbeddedScore);
    free(pn2);
    pq->size--;
}
/*pn=pn->next;  //assign pointers to next two nodes
pn2=pn2->next;
}*/

else if  ((y==0)&&(pn2==pq->rear)){ //if name was found in last node
     pq->rear=pn;
     pn->next=pn2->next;
       printf("***************\n");
       printf("the name of student that will be deleted is %s \n",pn2->entry.name);
    printf("the ID of student that will be deleted is %d \n",pn2->entry.ID);
    printf("the address of student that will be deleted is %s \n",pn2->entry.address);
    printf("the birthday of student that will be deleted is %s \n",pn2->entry.birthday);
    printf("the phone Number of student that will be deleted is %ld \n",pn2->entry.phone_num);
    printf("the EmbeddedScore of student that will be deleted is %c \n",pn2->entry.EmbeddedScore);
    free(pn2);
    pq->size--;
}
else {
    printf("Not found Name\n");
}
pn=pn->next;  //assign pointers to next two nodes
pn2=pn2->next;
}
}
}


//function to sort students alphabetically;
 void Student_List(Queue *pq){
int32_t i;
bubble_sorting(pq);
QueueNode *pn=pq->front;
for (i=1;i<=(pq->size);i++){  //print data after sorting
    printf("**************************\n");
    printf("the %d name in alphabetical order is %s \n",i,pn->entry.name);
    printf("the %d ID in alphabetical order is %hu \n",i,pn->entry.ID);
    printf("the %d address in alphabetical order is %s \n",i,pn->entry.address);
    printf("the %d birthday in alphabetical order is %s \n",i,pn->entry.birthday);
    printf("the %d phone Number in alphabetical order is %lu \n",i,pn->entry.phone_num);
    printf("the %d EmbeddedScore in alphabetical order is %d \n",i,pn->entry.EmbeddedScore);
    printf("**************************\n");
pn=pn->next;
}

}


//function to edit student data
void Student_Edit(Queue *pq){
int8_t temp[SIZE];
int32_t i;
QueueNode *pn=pq->front;

if(pq->size==0){

printf("The list is Empty please enter the student data \n");
}


else{
printf("***************\n");
printf("please enter the name of the student you want to edit\n");
scanf("%s",temp);
for (i=0;i<(pq->size);i++){
    if(strcmp(temp,pn->entry.name)==0){
        printf("the old name of the student is %s \n",pn->entry.name); //print old data of student before editing
        printf("the old ID of the student is %hu \n",pn->entry.ID);
        printf("the old address of the student is %s \n",pn->entry.address);
        printf("the old birthday of the student is %s \n",pn->entry.birthday);
        printf("the old phone num of the student is %lu \n",pn->entry.phone_num);
        printf("the old EmbeddedScore of the student is %d \n",pn->entry.EmbeddedScore);
        printf("****************************\n");
        printf("Please enter the new address of the student\n");
        fflush(stdin);
        gets(pn->entry.address);
        printf("Please enter the new phone number of the student\n");
        scanf("%lu",&pn->entry.phone_num);
        printf("Please enter the new Embedded Score of the student\n");
        scanf(" %d",&pn->entry.EmbeddedScore);
        printf("****************************\n");
        printf("the name of the student is %s \n",pn->entry.name); //print new data of student
        printf("the ID of the student is %hu \n",pn->entry.ID);
        printf("the new address of the student is %s \n",pn->entry.address);
        printf("the birthday of the student is %s \n",pn->entry.birthday);
        printf("the new phone num of the student is %lu \n",pn->entry.phone_num);
        printf("the new EmbeddedScore of the student is %d \n",pn->entry.EmbeddedScore);
    }
pn=pn->next;

}

}

}


//function to sort students according to Score
void Rank_Student(Queue *pq){

int32_t i,j;
student s_temp;
QueueNode *pn=pq->front;
QueueNode* pn2=pn->next;

for (i=0;i<(pq->size);i++){     //sorting score by bubble sort
    for (j=0;j<(pq->size-1);j++){
        if ((pn2->entry.EmbeddedScore)<(pn->entry.EmbeddedScore)){
            s_temp=pn->entry;
            pn->entry=pn2->entry;
            pn2->entry=s_temp;
        }
    pn=pn->next;      //set pointers to next two compare next two nodes
   pn2=pn2->next;
    }
pn=pq->front; //set pointers to first node to complete iterations
pn2=pn->next;
}

pn=pq->front;  //set pointers to beginning of list
pn2=pn->next;

  //if two students have the same score sort them alphabetically
for (i=0;i<(pq->size);i++){  //Sorting names by bubble sort
 for (j=0;j<(pq->size-1);j++){
  if ((pn2->entry.EmbeddedScore)==(pn->entry.EmbeddedScore)){
  if (strcmp(pn2->entry.name,pn->entry.name)<0){// compare two names and swap if 2nd name has higher order
      s_temp=pn->entry;
        pn->entry=pn2->entry;
        pn2->entry=s_temp;
      }
 }
   pn=pn->next;      //set pointers to next two compare next two nodes
   pn2=pn2->next;
 }
pn=pq->front;
pn2=pn->next;      //set pointers to beginning of list
}

pn=pq->front;
for (i=1;i<=(pq->size);i++){  //print data after sorting names and scores
    printf("**************************\n");
    printf("the %d name in alphabetical order is %s \n",i,pn->entry.name);
    printf("the %d EmbeddedScore in alphabetical order is %d \n",i,pn->entry.EmbeddedScore);
    printf("**************************\n");
pn=pn->next; //set pointer to next node to get data
}



}


//function to update score of all students
void Student_Score(Queue *pq){
int32_t i;
QueueNode *pn=pq->front;

for (i=1;i<=(pq->size);i++){
    printf("the name of %d student is %s \n",i,pn->entry.name);
    printf("the Embedded Score of %d student is %d \n",i,pn->entry.EmbeddedScore);
    printf("**********************\n");
   pn=pn->next;
    }
pn=pq->front;
for (i=1;i<=pq->size;i++){
    printf("Enter the new score of %d student\n",i);
    scanf("%d",&pn->entry.EmbeddedScore);
    printf("the new score of %d student is %d \n",i,pn->entry.EmbeddedScore);
pn=pn->next;
}

}
















