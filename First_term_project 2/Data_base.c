/*
 ============================================================================
 Name        : Data_base.c
 Author      : Mohannad Abd El Hakim
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data_base.h"

struct student students[max_students];
int student_count=0;

#define DPRINTF(...)   {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout); \
		fflush(stdin);}

void add_Student_Manually()
{
	if(student_count>=max_students)
	{
		DPRINTF("maximum number is reached\n");
		return;
	}
		struct student new_student;

		DPRINTF("enter student first name: \n");
		scanf("%s",new_student.first_name);
		DPRINTF("enter student last name: \n");
		scanf("%s",new_student.last_name);
		DPRINTF("enter student Roll number: \n");
		scanf("%d",&new_student.Roll_number);
		DPRINTF("enter student GBA: \n");
		scanf("%f",&new_student.GBA);
		DPRINTF("enter student courses \n");

		int course_num;
		DPRINTF("enter the number of courses for this student \n");
		scanf("%d",&course_num);
		DPRINTF("enter the courses enrolled (math history etc...\n");
		for(int i=0;i<course_num;i++)
		{
			scanf("%s",new_student.courses[i]);
		}
		new_student.course_count=course_num;

		students[student_count++]=new_student;
		DPRINTF("Student details added successfully.\n");
}

void add_Student_FromFile(const char* fileName){
	FILE* file=fopen(fileName, "r");
	if(file ==NULL){
		DPRINTF("failed to open the file\n");
		return;
	}
		while(!feof(file) && student_count < max_students){
			struct student new_student;
			//read new student data from file
			fscanf(file,"%s %s %d %f",new_student.first_name,new_student.last_name,&new_student.Roll_number,&new_student.GBA);
			//read new student number of courses and courses details
			int courses_num;
			fscanf(file, "%d" ,&courses_num);
			for(int i=0;i<courses_num;i++){
				fscanf(file,"%s",new_student.courses[i]);
			}
			//assign courses number to the new_student's courses count
			new_student.course_count=courses_num;
			//add the new_student form the function to the new_student array		students[studentCount++] = newStudent;
			students[student_count++] = new_student;
		}
		fclose(file);
		DPRINTF("record added from file successfully.\n");
	}

void find_Student_By_RollNumber(int Roll_number){
	for(int i =0;i<student_count;i++)
	{
		if (students[i].Roll_number==Roll_number)
		{
			DPRINTF("Student Found:\n");
			DPRINTF("First Name: %s\n",students[i].first_name);
			DPRINTF("last Name: %s\n",students[i].last_name);
			DPRINTF("Roll number: %d\n",students[i].Roll_number);
			DPRINTF("GBA: %0.2f\n",students[i].GBA);
			DPRINTF("Courses Registered: ");
			for(int j=0;j<students[i].course_count;j++)
			{
				DPRINTF("%s ",students[i].courses[j]);
			}
			DPRINTF("----------\n");
        return;
		}
	}
	DPRINTF("ERROR:student with Roll number %d was not found\n",Roll_number);
}
void find_Student_By_FirstName(const char* first_name){
	for(int i =0;i<student_count;i++)
	{
		if (strcmp(students[i].first_name,first_name)==0)
		{
            DPRINTF("Student Found:\n");
			DPRINTF("First Name: %s\n",students[i].first_name);
			DPRINTF("last Name: %s\n",students[i].last_name);
			DPRINTF("Roll number: %d\n",students[i].Roll_number);
			DPRINTF("GBA: %0.2f\n",students[i].GBA);
			DPRINTF("Courses Registered: ");
			for(int j=0;j<students[i].course_count;j++)
			{
				DPRINTF("%s",students[i].courses[j]);
			}
			DPRINTF("----------\n");
        return;
		}
	}
	DPRINTF("ERROR:student with first name %s was not found\n",first_name);
}
void find_Students_By_Course(const char* course){
	DPRINTF("students enrolled in course %s:\n",course);
	for(int i =0;i<student_count;i++)
	{
		for(int j=0;j<students[i].course_count;j++)
		{
			{if (strcmp(students[i].courses[j],course)==0)
                {
				DPRINTF("First Name: %s\n",students[i].first_name);
				DPRINTF("last Name: %s\n",students[i].last_name);
				DPRINTF("Roll number: %d\n",students[i].Roll_number);
				DPRINTF("GBA: %0.2f\n",students[i].GBA);
				DPRINTF("----------\n");
				break;
                }
			}
		}
	}
}
void find_Students_By_CourseID(int course_ID){
	DPRINTF("students enrolled in this course ID number %d \n",course_ID);
	for(int i =0;i<student_count;i++)
	{
		for(int j=0;j<students[i].course_count;j++)
		{
			//extract the last digit for the course name
			int course_ID_from_name=students[i].courses[j][strlen(students[i].courses[j])-1]-'0';
			if (course_ID_from_name==course_ID)
			{
				DPRINTF("First Name: %s\n",students[i].first_name);
				DPRINTF("last Name: %s\n",students[i].last_name);
				DPRINTF("Roll number: %d\n",students[i].Roll_number);
				DPRINTF("GBA: %0.2f\n",students[i].GBA);
				DPRINTF("----------\n");
				break;
			}
		}
	}
}
void count_Students()
{
	DPRINTF("number of stored students is:%d\n",student_count);
}
void delete_Student_By_RollNumber(int Roll_number)
{
	for(int i =0;i<student_count;i++)
	{
		if(students[i].Roll_number==Roll_number)
		{for(int j=i;j<student_count-1;j++)
			{
			students[j]=students[j+1];
			}
			student_count--;
		DPRINTF("Student with roll number %d deleted successfully.\n",Roll_number);
		return;
		}
	}
	DPRINTF("Student with roll number %d not found.\n", Roll_number);
}
void update_Student_By_RollNumber(int Roll_number)
{
	for(int i =0;i<student_count;i++)
	{
		if (students[i].Roll_number==Roll_number)
		{DPRINTF("enter new student first name\n");
		scanf("%s",students[i].first_name);
		DPRINTF("enter new student last name\n");
		scanf("%s",students[i].last_name);
		DPRINTF("enter new student GBA\n");
		scanf("%0.2f",&students[i].GBA);

		int courses_num;
		DPRINTF("enter the number of courses for this student \n");
		scanf("%d",&courses_num);
		DPRINTF("enter the courses enrolled (math history etc...\n");
		for(int j=0;j<courses_num;j++)
		{
			scanf("%s",students[i].courses[j]);
		}
		students[i].course_count = courses_num;
		DPRINTF("Student details updated successfully.\n");
		return;
		}
	}
	DPRINTF("Student with roll number %d not found.\n",Roll_number);
}
void show_All_Information()
{DPRINTF("All Student Information:\n");
for (int i = 0; i < student_count; i++) {
	DPRINTF("First Name: %s\n", students[i].first_name);
	DPRINTF("Last Name: %s\n", students[i].last_name);
	DPRINTF("Roll Number: %d\n", students[i].Roll_number);
	DPRINTF("GPA: %.2f\n", students[i].GBA);
	DPRINTF("Courses Registered: ");
	for (int j = 0; j < students[i].course_count; j++) {
		DPRINTF("%s ", students[i].courses[j]);
		}
	DPRINTF("\n");
	}
}

