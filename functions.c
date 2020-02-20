#include "header.h"
#include <string.h>

int GetStudentInfo(Node** pStudent, FILE* ptr, Node* pHead)
{
	*pStudent = (Node*)malloc(sizeof(Node));
	if (!(*pStudent))
	{
		DeleteList(pHead);
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if ((fscanf(ptr, "%s %s %d.%d.%d", (*pStudent)->Student.Surname, (*pStudent)->Student.Name, &((*pStudent)->Student.iDay), &((*pStudent)->Student.iMonth), &((*pStudent)->Student.iYear))) != 5) {
		free(*pStudent);
		return 0;
	}
	for (size_t i = 0; i < SUBJECT; ++i)

		if (fscanf(ptr, "%i", &((*pStudent)->Student.iMarks[i])) != 1)
		{

			return 0;
		}

	(*pStudent)->pNext = NULL;

	return 1;
}

void AddToList(Node* pStudent, Node** pHead)
{
	Node* pPrevious, * pCurrent;
	pCurrent = pPrevious = *pHead;
	while (pCurrent && (strcmp(pStudent->Student.Surname, pCurrent->Student.Surname) > 0))
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;

	}

	if (pCurrent == *pHead) // the beggining of list
	{
		pStudent->pNext = *pHead;
		*pHead = pStudent;
	}
	else if (pCurrent)
	{
		pStudent->pNext = pCurrent;
		pPrevious->pNext = pStudent;
	}
	else //end of list
	{
		pPrevious->pNext = pStudent;
		pStudent->pNext = NULL;
	}
}

void PrintAllStudents(const Node* pStudent)
{
	if (!pStudent)
	{
		printf("The list is empty!!!");
		return;
	}
	do
	{
		printf("%-12s %-12s %02i %02i %02i", pStudent->Student.Surname, pStudent->Student.Name,
			pStudent->Student.iDay, pStudent->Student.iMonth, pStudent->Student.iYear);
		for (size_t i = 0; i < SUBJECT; ++i)
			printf("%2i", pStudent->Student.iMarks[i]);
		printf("\n");
		pStudent = pStudent->pNext;
	} while (pStudent);
}

void PrintStudentsBornedInAutumn(const Node* pHead)
{
	Node* pStudent = pHead;
	printf("\n\t\t\tThe list of students borned in Autumn:\n");
	while (pStudent)
	{
		int iResult = pStudent->Student.iMonth;
		if (iResult < 12 && iResult > 8)
		{
			printf("%-12s %-12s %02i %02i %02i", pStudent->Student.Surname, pStudent->Student.Name,
				pStudent->Student.iDay, pStudent->Student.iMonth, pStudent->Student.iYear);
			for (int i = 0; i < SUBJECT; ++i)
				printf("%2i", pStudent->Student.iMarks[i]);
			printf("\n");
		}
		pStudent = pStudent->pNext;
	}
}

int CompareMarks(const int aMarks[])
{
	const int aAllMark[] = { 2, 3, 4, 5 };
    size_t iSize = sizeof(aAllMark) / sizeof(int);

	for (size_t i = 0; i < iSize; ++i)
	{
		int Exist = 0;
		for (size_t j = 0; j < SUBJECT; ++j)
		{
			if (aAllMark[i] == aMarks[j])
			{
				Exist=1;
				break;
			}
		}
		if (!Exist)
			return 0;
	}
	return 1;
}

void DeleteList(Node* pHead)
{
	if (!pHead)
	{
		return;
	}
	Node* pTemp = NULL;
	while (pHead)
	{
		pTemp = pHead;
		pHead = pHead->pNext;
		free(pTemp);
	}
}

void DeleteStudents(Node** pHead)
{
	if (!(*pHead))
	{
		printf("The list is empty!!!\n");
		return;
	}
	Node* pPrivious, * pCurrent,*pTemp=NULL;
	pPrivious = pCurrent = *pHead;
	while (1)
	{
		while (pCurrent && !(CompareMarks(pCurrent->Student.iMarks)))
		{
			pPrivious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
		if (pCurrent == *pHead)
		{
			if (!(*pHead))
				return;
			*pHead = pCurrent->pNext;
			free(pCurrent);
			pCurrent = (*pHead);
		}
		else if (!pCurrent) return;
		else
		{
			pPrivious->pNext = pCurrent->pNext;
			pTemp = pCurrent;
			free(pTemp);
			pCurrent = pPrivious->pNext;
		}
	}
}
