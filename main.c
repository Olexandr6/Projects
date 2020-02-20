#include "header.h"

int main(void)
{
	Node* pHead, * pStudent;
	pHead = NULL;

	FILE* ptr = fopen("InputData.txt", "r");
	if (!ptr)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	while (GetStudentInfo(&pStudent, ptr, pHead))
	{
		if (!pHead)
			pHead = pStudent;
		else
			AddToList(pStudent, &pHead);
	}
	FILE* pFout = freopen("J:\OutputData.txt", "w", stdout);
	if (!pFout)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	printf("\n\t\t\tList of all students:\n");
	PrintAllStudents(pHead);
	PrintStudentsBornedInAutumn(pHead);
	DeleteStudents(&pHead);
	printf("\n\t\t\tList without students who received 2,3,4,5 after the session:\n");
	PrintAllStudents(pHead);
	fclose(ptr);
	fclose(pFout);
	DeleteList(pHead);

	return 0;
