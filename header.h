#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 32
#define SUBJECT 7

typedef struct student
{
	char Name[SIZE];
	char Surname[SIZE];
	int iDay;
	int iMonth;
	int iYear;
	int iMarks[SUBJECT];
}SStudent;

typedef struct node
{
	SStudent Student;
	struct  node* pNext;
}Node;

int GetStudentInfo(Node** pStudent, FILE* ptr, Node* pHead);

//Add Students to the sorted list by Surname
void AddToList(Node* pStudent, Node** pHead);

void PrintAllStudents(const Node* pHead);
void PrintStudentsBornedInAutumn(const Node* pHead);

int CompareMarks(const int aMarks[]);

//Delete Students whith such marks: 2,3,4,5
void DeleteStudents(Node** pHead);
void DeleteList(Node* pHead);
