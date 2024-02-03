/*
 * Data_base.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Mohannad Abd El Hakim
 */

#ifndef DATA_BASE_H_
#define DATA_BASE_H_

#define max_students 50
#define max_courses 10
#define max_name_length 50
#define max_course_length 20


struct student{
	char first_name[max_name_length];
	char last_name[max_name_length];
	float GBA;
	int Roll_number;
	char courses[max_courses][max_course_length];
	int course_count;
};

void add_Student_Manually();
void add_Student_FromFile(const char* fileName);
void find_Student_By_RollNumber(int Roll_number);
void find_Student_By_FirstName(const char* first_name);
void find_Students_By_Course(const char* course);
void find_Students_By_CourseID(int course_ID);
void count_Students();
void delete_Student_By_RollNumber(int Roll_number);
void update_Student_By_RollNumber(int Roll_number);
void show_All_Information();
#endif /* DATA_BASE_H_ */
