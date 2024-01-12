/*
 ============================================================================
 Name        : c.c
 Author      : Mohannad Abd El hakim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Dprintf(...)		{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

struct Sdata{
	int ID;
	char name[40];
	float height;
};

struct SStudent{
	struct Sdata student;
	struct SStudent* PNext_student;
};

struct SStudent* gPfirst_student=NULL;

void ADDstudent()
{
	struct SStudent* Pnew_student;
	struct SStudent* Plast_student;
	char Temp_text[40];
	//check if the record is empty
	if(gPfirst_student==NULL){
		//create new record
		Pnew_student=(struct SStudent*)malloc(sizeof(struct SStudent));
		//assign it to gPfirst
		gPfirst_student=Pnew_student;
	}else
	{
		//contains record
		//navigate until reach the last record
		Plast_student=gPfirst_student;
		while(Plast_student->PNext_student)
			Plast_student=Plast_student->PNext_student;

		//create new record
		Pnew_student=(struct SStudent*)malloc(sizeof(struct SStudent));
		Plast_student->PNext_student=Pnew_student;
	}
	//fill new record
	Dprintf("\n please enter the ID: ");
	gets(Temp_text);
	Pnew_student->student.ID=atoi(Temp_text);

	Dprintf("\n please enter the name: ");
	gets(Pnew_student->student.name);

	Dprintf("\n please enter the height: ");
	gets(Temp_text);
	Pnew_student->student.height=atof(Temp_text);

	//assign the next of the last record to null
	Pnew_student->PNext_student=NULL;
}

int delete_student()
{
	unsigned int selected_ID;
	char Temp_data[40];

	//enter the ID to e deleted
	Dprintf("\nplease enter the selected ID to be deleted\n");
	gets(Temp_data);
	selected_ID=atoi(Temp_data);

	//list is not empty
	if(gPfirst_student)
	{
		struct SStudent* Pprevious_student=NULL;
		struct SStudent* Pselected_student=gPfirst_student;
		while(Pselected_student)
		{
			//compare each node with the selected ID
			if(Pselected_student->student.ID==selected_ID)
			{
				if(Pprevious_student)//the selected ID is not the first record
				{
					Pprevious_student->PNext_student=Pselected_student->PNext_student;

				}
				//the selected ID is the first record
				else{
					gPfirst_student=Pselected_student->PNext_student;
				}
				free(Pselected_student);
				return 1 ;
			}
			Pprevious_student=Pselected_student;
			Pselected_student=Pselected_student->PNext_student;
		}
	}
	Dprintf("cannot find the student ID \n");
	return 0;
}

void view_students()
{
	struct SStudent* Pcurrent_student=gPfirst_student;
	int count=0;
	//check if record is empty
	if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
	}else{
		while(Pcurrent_student)
		{
			Dprintf("\n record number: %d ",count+1);
			Dprintf("\n student ID : %d",Pcurrent_student->student.ID);
			Dprintf("\nstudent name : %s",Pcurrent_student->student.name);
			Dprintf("\nstudent height : %f",Pcurrent_student->student.height);
			Pcurrent_student=Pcurrent_student->PNext_student;
			count++;
		}
	}
}
void delete_all()
{
	struct SStudent* Pcurrent_student=gPfirst_student;
	//check if record is empty
	if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
	}else{
		while(Pcurrent_student)
		{
			struct SStudent* Ptemp_student=Pcurrent_student;
			Pcurrent_student=Pcurrent_student->PNext_student;
			free(Ptemp_student);
		}
		gPfirst_student=NULL;
	}
}

void find_node() {
    char selected_index[40];
    int count = 0;
    struct SStudent* Pcurrent_student = gPfirst_student;

    if (gPfirst_student == NULL) {
        Dprintf("the record is empty\n");
    } else {
        Dprintf("please enter the required index no: ");
        fgets(selected_index, sizeof(selected_index), stdin);  // Use fgets for safer input
        int target_index = atoi(selected_index);

        while (Pcurrent_student) {
            count++;

            if (target_index == count) {
                Dprintf("the node at index %d has ID %d", target_index, Pcurrent_student->student.ID);
                break;  // Break out of the loop after finding the node
            }

            Pcurrent_student = Pcurrent_student->PNext_student;
        }

        if (target_index > count) {
            Dprintf("Index %d exceeds the number of nodes in the list\n", target_index);
        }
    }
}

void find_length()
{
	struct SStudent* Pcurrent_student=gPfirst_student;
	int count=0;
	//check if record is empty
	if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
	}else{
		while(Pcurrent_student)
		{
			Pcurrent_student=Pcurrent_student->PNext_student;
			count++;
		}
		Dprintf("\nthe number of nodes is : %d",count);
	}
}

int find_length_rec(struct SStudent* Pcurrent_student)
{
	//check if record is empty
	if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
		return 0;
	}
	else
        // Recursive case: traverse the list
        return 1 + find_length_rec(Pcurrent_student->PNext_student);

}

struct SStudent*find_Nth_node(int n)
{
    struct SStudent* main_ptr=gPfirst_student;
    struct SStudent* ref_ptr=gPfirst_student;
    int i=0;

	//check if record is empty
	if(gPfirst_student==NULL||n<=0)
	{
		Dprintf("the record is empty\n");
		return NULL;
	}
	else
	{
	    //move reference pointer until it reaches the N node then move the main pointer
	    for(i=0;i<n;++i)
        {
            ref_ptr=ref_ptr->PNext_student;
        }
        //move both pointers till reference pointer reaches NULL then the main one will be at the N node
        while(ref_ptr)
        {
            main_ptr=main_ptr->PNext_student;
            ref_ptr=ref_ptr->PNext_student;
        }
        return main_ptr;
	}

}

struct SStudent*find_middle_node()
{
    struct SStudent* slow_ptr=gPfirst_student;
    struct SStudent* fast_ptr=gPfirst_student;
    int i=0;
    int count=0;

	//check if record is empty
	if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
		return NULL;
	}
	else
	{
	    //move reference pointer until it reaches the N node then move the main pointer
	    while(fast_ptr)
        {
            fast_ptr=fast_ptr->PNext_student;
            count++;
        }
        //move both pointers till reference pointer reaches NULL then the main one will be at the N node
        for(i=0;i<count/2;i++)
        {
            slow_ptr=slow_ptr->PNext_student;
        }
        return slow_ptr;
	}

}

int find_loop()
{
    struct SStudent* slow_ptr=gPfirst_student;
    struct SStudent* fast_ptr=gPfirst_student;
	//check if record is empty
	if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
		return NULL;
	}
	else
	{
	    while(fast_ptr && slow_ptr && fast_ptr->PNext_student)
        {
            fast_ptr=fast_ptr->PNext_student->PNext_student;
            slow_ptr=slow_ptr->PNext_student;
            if(fast_ptr==slow_ptr)
                {
                Dprintf("\nLoop found\n");
                return 1;
                }
        }
     return 0;
	}
}

void reverse_list()
{
    struct SStudent* prev_ptr=NULL;
    struct SStudent* next_ptr=NULL;
    struct SStudent* curr_ptr=gPfirst_student;
    if(gPfirst_student==NULL)
	{
		Dprintf("the record is empty\n");
		return NULL;
	}
	else
	{
	    while(curr_ptr!=NULL)
        {
            next_ptr=curr_ptr->PNext_student;
            //reverse the next part of current to point to the previous node
            curr_ptr->PNext_student=prev_ptr;

            prev_ptr=curr_ptr;
            curr_ptr=next_ptr;
        }
    gPfirst_student=prev_ptr;
	}
}

void main()
{
	char temp_text[40];
    struct SStudent* Pcurrent_student;
    int length ;
    int n;
    struct SStudent* Nth_node;
    struct SStudent* middle_node;

	while(1)
	{
		Dprintf("\n=======================");
		Dprintf("\n choose one of the following options");
		Dprintf("\n 1:Add Student");
		Dprintf("\n 2:delete Student");
		Dprintf("\n 3:view students");
		Dprintf("\n 4:delete all");
        Dprintf("\n 5:find_index");
        Dprintf("\n 6:find_length");
        Dprintf("\n 7:find_length_rec");
        Dprintf("\n 8:find_Nth_node");
        Dprintf("\n 9:find_middle_node");
        Dprintf("\n 10:find_loop");
        Dprintf("\n 11:reverse list");


		Dprintf("\n Enter option number : ");

		gets(temp_text);
		Dprintf("\n=======================");
		switch(atoi(temp_text))
		{
		case 1:
			ADDstudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			delete_all();
			break;
        case 5:
            find_node();
            break;
        case 6:
            find_length();
            break;
        case 7:
            length = find_length_rec(gPfirst_student);
            Dprintf("Length of the linked list: %d\n", length);
            break;
        case 8:
            n=2;
            Nth_node=find_Nth_node(n);
            if(Nth_node!=NULL)
            {
                Dprintf("the %d th node has an ID of : %d",n,Nth_node->student.ID);
            }
            else{
            Dprintf("Invalid input or list is smaller than %d\n", n);
            }
            break;
        case 9:
            middle_node=find_middle_node();
            if(middle_node!=NULL)
            {
                Dprintf("the middle node has an ID of : %d",middle_node->student.ID);
            }
            else{
            Dprintf("Invalid input or list is smaller than %d\n", n);
            }
            break;
        case 10:
            find_loop();
            break;
            case 11:
            view_students();

            reverse_list();
            Dprintf("\nreversed List: \n")

            view_students();
            break;
		default:
			Dprintf("\n wrong option");
			break;
		}
	}
}
