#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QueueEntry student
#define SIZE 10

//typedef for variables
typedef char int8_t;
typedef  int int32_t;
typedef unsigned short uint16_t;
typedef unsigned long uint64_t;

//typedef holds data of student
typedef struct Student{
  int8_t name[15];
  int8_t birthday[11];
  int8_t address[20];
  uint16_t ID;
  int32_t  EmbeddedScore;
  uint64_t phone_num;
}student;

//Linked Queue
typedef struct queuenode{
   QueueEntry entry;
   struct queuenode *next;
}QueueNode;

//Creating queue
typedef struct queue {
    QueueNode *front;
	QueueNode *rear;
    int32_t size;
}Queue;

//function prototypes
void Main_Menu(Queue *pq);
  void New_Student(Queue *pq);
 void Delete_Student(Queue *pq);
 void Student_List(Queue *pq);
 void Student_Edit(Queue *pq);
 void Rank_Student(Queue *pq);
 void Student_Score(Queue *pq);


#endif //
