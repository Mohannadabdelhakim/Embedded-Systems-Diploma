/*
 ============================================================================
 Name        : main.c
 Author      : Mohannad Abd El Hakim
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data_base.h"
#define DPRINTF(...)   {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout); \
		fflush(stdin);}

int main() {
	int choice;
	do{
		DPRINTF("\n--- Student Information Management System ---\n");
		DPRINTF("1. Add Student Details manually\n");
		DPRINTF("2. Add Student Details from a text file\n");
		DPRINTF("3. Find Student by Roll Number\n");
		DPRINTF("4. Find Student by First Name\n");
		DPRINTF("5. Find Students registered in a Course\n");
		DPRINTF("6. Find Students Details by Course ID\n");
		DPRINTF("7. Count of Students\n");
		DPRINTF("8. Delete Student Details by Roll Number\n");
		DPRINTF("9. Update Student Details by Roll Number\n");
		DPRINTF("10. Show All Information\n");
		DPRINTF("11. Exit\n");
		DPRINTF("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
		{
			add_Student_Manually();
			break;
		}
		case 2:
		{
			char file_name[50];
			DPRINTF("enter file name: \n");
			scanf("%s",file_name);
			add_Student_FromFile(file_name);
			break;
		}
		case 3:
		{
			int Roll_number;
			DPRINTF("enter Roll number\n");
			scanf("%d",&Roll_number);
			find_Student_By_RollNumber(Roll_number);
			break;
		}
		case 4:
		{
			char First_name[max_name_length];
			DPRINTF("enter First name \n");
			scanf("%s",First_name);
			find_Student_By_FirstName(First_name);
			break;
		}
		case 5:
		{
			char course[max_course_length];
			DPRINTF("enter Course name \n");
			scanf("%s",course);
			find_Students_By_Course(course);
			break;
		}
		case 6:
		{
			int course_ID;
			DPRINTF("enter Course ID \n");
			scanf("%s",course_ID);
			find_Students_By_CourseID(course_ID);
			break;
		}
		case 7:{
			count_Students();
			break;
		}
		case 8:{
			int Roll_number;
			DPRINTF("enter Roll number to be deleted\n");
			scanf("%d",&Roll_number);
			delete_Student_By_RollNumber(Roll_number);
			break;
		}
		case 9 :{
			int Roll_number;
			DPRINTF("enter Roll number to be Updated\n");
			scanf("%d",&Roll_number);
			update_Student_By_RollNumber( Roll_number);
			break;
		}
		case 10:
		{
			show_All_Information();
			break;
		}
		case 11:
			DPRINTF("Exiting the program. Goodbye!\n");
			exit(0);
		default:
			DPRINTF("Invalid choice. Please try again.\n");
		}
	}while(choice != 11);
	return 0;
}






