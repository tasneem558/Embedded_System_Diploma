/*
 * SIMS.c
 *
 *  Created on: Mar 21, 2024
 *      Author: tasneem
 */
#include "SIMS.h"
char temp_str[30];
//########system-functions
SISM_Buff_status FIFO_init(SISM_Buff_t* fifo,st* buff, int length)
{
    if(buff == NULL)
		return SISM_null;
	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	fifo->length = length;
	fifo->count =0;
	return SISM_no_error;

}
//######################################################################################################
int check_roll(SISM_Buff_t* fifo,int r) // to check if roll number is exist before or not
{
    int i;
    st* ptr = fifo->base;
    for(i=0;i<(fifo->count);i++)
    {
        if(ptr->roll == r)
        {
            return 0;
        }
        ptr++;
    }
    return 1;

}
//######################################################################################################
SISM_Buff_status add_student_manually(SISM_Buff_t* fifo)
{
   int temp,i,x;
   //check queue is exist or not
   if(!fifo->base || !fifo->head || !fifo->tail)
   {
     DPRINTF("No database exist\n");
     return SISM_null;
   }
   //check if queue is full or not yet
   if(fifo->count == fifo->length)
   {
     DPRINTF("[ERROR] DATA BASE IS FULL\n");
     return SISM_full;
   }
    DPRINTF("--------------------------------------------\n");
    //add student informations
    DPRINTF("Add Student Details \n");
    DPRINTF("--------------------------------------------\n");
    DPRINTF("Enter the Roll Number\n");
    gets(temp_str);
    temp =atoi(temp_str);
    if(check_roll(fifo,temp)==0)
    {
        DPRINTF("[ERROR] Roll Number is already taken before \n");
        return SISM_error;
    }
    //roll number not exist
    fifo->head->roll=temp;

    DPRINTF("Enter First name of the student:\n");
    gets(fifo->head->Fname);

    DPRINTF("Enter Last name of the student:\n");
    gets(fifo->head->Lname);

    DPRINTF("Enter the GPA you obtained\n");
    gets(temp_str);
    fifo->head->GPA=atof(temp_str);

    DPRINTF("Enter the course id of each course\n");
    for(i=0;i<5;i++)
    {
        DPRINTF("course %d id :\n",i+1);
        gets(temp_str);
        x=atoi(temp_str);
        if(x>0 && x<30) // check if course id is available
        {
            fifo->head->Cid[i]=x;
            continue;
        }
        DPRINTF("[ERROR] course id is not correct\n");
        i--;
    }


   fifo->head++;
   fifo->count++;
   DPRINTF("[INFO] Student Details are added successfully \n");
   DPRINTF("--------------------------------------------\n");
   DPRINTF("[INFO] the total number of students is : %d\n",fifo->count);
   DPRINTF("[INFO] you can add up to %d students \n",fifo->length);
   DPRINTF("[INFO] you can add more about %d students \n",fifo->length - fifo->count);
   DPRINTF("--------------------------------------------\n");
   return SISM_no_error;
}
//######################################################################################################
SISM_Buff_status add_student_file(SISM_Buff_t* fifo)
{
  char Fname[50];
  char Lname[50];
  int i,count_file=0,flag=0,roll_num,Cid[5];
  float gpa;
  int l=0;
  //check queue is exist or not
  if(!fifo->base || !fifo->head || !fifo->tail)
  {
    DPRINTF("No database exist\n");
    return SISM_null;
  }
  //check if queue is full or not yet
  if(fifo->count == fifo->length)
  {
    DPRINTF("[ERROR] DATA BASE IS FULL\n");
    return SISM_full;
  }
  FILE *p_file = fopen("text.txt","r");
  if(p_file==NULL)
  {
    DPRINTF("[ERROR] File not found \n");
    return SISM_error;
  }

  //read from file
  while(fscanf(p_file,"%d %49s %49s %f %d %d %d %d %d", &roll_num, Fname, Lname, &gpa, &Cid[0], &Cid[1], &Cid[2], &Cid[3], &Cid[4]) != EOF)

  {
    if(fifo->count==fifo->length)
    {
        DPRINTF("[ERROR] data base is full\n");
        DPRINTF("[INFO] students added : %d\n",count_file);
        DPRINTF("[INFO] remaining students are :%d\n",l-count_file); //due to size or errors
        return SISM_full;
    }

    if(check_roll(fifo,roll_num)==0)
    {
        DPRINTF("[ERROR] IN line %d : Roll Number is already taken before \n",l);
        l++;
        continue; //skip this student
    }

    fifo->head->roll=roll_num;
    fifo->head->GPA=gpa;
    strcpy(fifo->head->Fname,Fname);
    strcpy(fifo->head->Lname,Lname);
    for(i=0;i<5;i++)
    {
        flag=0;
        if(Cid[i]<0 || Cid[i]>30)
        {
            flag=1;
            break;
        }
        fifo->head->Cid[i]=Cid[i];
    }
    if(flag==1)
    {
        DPRINTF("[ERROR] IN line %d : non valid course id\n",l); //skip this student
        l++;
        continue;
    }

    fifo->head++;
    fifo->count++;
    l++;
    count_file++;
  }

  //close file
  fclose(p_file);
  DPRINTF("[INFO] students added : %d\n",count_file);
  DPRINTF("[INFO] remaining students are :%d\n",l-count_file); //due to errors
  return SISM_error;
}
//######################################################################################################
SISM_Buff_status find_rl(SISM_Buff_t* fifo)
{
    int temp_roll ,i,j;
    st* current_student = fifo->base;

   //check queue is exist or not
   if(!fifo->base || !fifo->head || !fifo->tail)
   {
     DPRINTF("No database exist\n");
     return SISM_null;
   }
   //check if is empty
   if(fifo->count ==0)
   {
    DPRINTF("[ERROR] database is empty\n");
	return SISM_empty;
   }
   //search
   DPRINTF("Enter student roll number\n");
   gets(temp_str);
   temp_roll = atoi(temp_str);

   for(i=0;i<(fifo->count);i++)
   {
     if(current_student->roll == temp_roll)
     {
        DPRINTF("Student Roll number : %d\n",current_student->roll);
	    DPRINTF("Student first name : %s\n",current_student->Fname);
	    DPRINTF("Student last name : %s\n",current_student->Lname);
	    DPRINTF("Student GPA : %.2f\n",current_student->GPA);
        for(j=0;j<5;j++)
        {
            DPRINTF("course %d id : %d \n",j+1,current_student->Cid[j]);
        }
        return SISM_no_error;
     }
    current_student++;
   }
   DPRINTF("--------------------------------------------\n");
   DPRINTF("[ERROR] Roll number is not found\n");                 // loop finished and roll not found
   DPRINTF("--------------------------------------------\n");
   return SISM_error;
}
//######################################################################################################
SISM_Buff_status find_Fn(SISM_Buff_t* fifo)
{
    int flag=0,i,j;
    st *current_student = fifo->base;

   //check queue is exist or not
   if(!fifo->base || !fifo->head || !fifo->tail)
   {
     DPRINTF("No database exist\n");
     return SISM_null;
   }
   //check if is empty
   if(fifo->count ==0)
   {
    DPRINTF("[ERROR] database is empty\n");
	return SISM_empty;
   }
   //search
   DPRINTF("Enter student first name\n");
   gets(temp_str);
   for(i=0;i<fifo->count;i++)
   {
    if(strcmpi(current_student->Fname,temp_str)==0)
    {
        DPRINTF("Student Roll number : %d\n",current_student->roll);
	    DPRINTF("Student first name : %s\n",current_student->Fname);
	    DPRINTF("Student last name : %s\n",current_student->Lname);
	    DPRINTF("Student GPA : %.2f\n",current_student->GPA);
        for(j=0;j<5;j++)
        {
            DPRINTF("course %d id : %d \n",j+1,current_student->Cid[j]);
        }
        flag =1; //to know that Fname found at least one time
    }
    current_student ++;
   }
   if(flag==0)
   {
     DPRINTF("[ERROR] No first name matched this name\n");
     return SISM_error;
   }
   return SISM_no_error;
}
//######################################################################################################
SISM_Buff_status find_C(SISM_Buff_t* fifo)
{
    int temp_Cid,flag=0,i,j,k;
    st* current_student = fifo->base;
    //check queue is exist or not
   if(!fifo->base || !fifo->head || !fifo->tail)
   {
     DPRINTF("No database exist\n");
     return SISM_null;
   }
   //check if is empty
   if(fifo->count ==0)
   {
    DPRINTF("[ERROR] database is empty\n");
	return SISM_empty;
   }
   //search
   DPRINTF("Enter course id\n");
   gets(temp_str);
   temp_Cid=atoi(temp_str);
   for(i=0;i<(fifo->count);i++)
   {
      for(j=0;j<5;j++)
      {
        if(current_student->Cid[j]==temp_Cid)
        {
            DPRINTF("Student Roll number : %d\n",current_student->roll);
	        DPRINTF("Student first name : %s\n",current_student->Fname);
	        DPRINTF("Student last name : %s\n",current_student->Lname);
	        DPRINTF("Student GPA : %.2f\n",current_student->GPA);
            for(k=0;k<5;k++)
            {
                DPRINTF("course %d id : %d \n",k+1,current_student->Cid[k]);
            }
            flag =1; //to know that Cid found at least one student
        }
      }
    current_student++;
   }
   if(flag==0)
   {
        DPRINTF("[ERROR] No student registered\n");
        return SISM_error;
   }
   return SISM_no_error;
}
//######################################################################################################
SISM_Buff_status tot_s(SISM_Buff_t* fifo)
{
    //check queue is exist or not
   if(!fifo->base || !fifo->head || !fifo->tail)
   {
     DPRINTF("No database exist\n");
     return SISM_null;
   }
   //check if is empty
   if(fifo->count ==0)
   {
    DPRINTF("[ERROR] database is empty\n");
	return SISM_empty;
   }

   DPRINTF("--------------------------------------------\n");
   DPRINTF("[INFO] the total number of students is : %d\n",fifo->count);
   DPRINTF("[INFO] you can add up to %d students \n",fifo->length);
   DPRINTF("[INFO] you can add more about %d students \n",fifo->length - fifo->count);
   DPRINTF("--------------------------------------------\n");
   return SISM_no_error;
}
//######################################################################################################
SISM_Buff_status shift_buffer(int index,SISM_Buff_t* fifo)
{
   int i;
   for(i=index;i<fifo->count;i++)
   {
     buff[i]=buff[i+1];
   }
   DPRINTF("Student deleted successfully\n");
   return SISM_no_error;
}
//######################################################################################################
SISM_Buff_status del_s(SISM_Buff_t* fifo)
{
    int temp_roll,i,index=0;
    st* current_student = fifo->base;
   //check queue is exist or not
   if(!fifo->base || !fifo->head || !fifo->tail)
   {
     DPRINTF("No database exist\n");
     return SISM_null;
   }
   //check if is empty
   if(fifo->count ==0)
   {
    DPRINTF("[ERROR] database is empty\n");
	return SISM_empty;
   }
   DPRINTF("Enter student roll number\n");
   gets(temp_str);
   temp_roll=atoi(temp_str);
   for(i=0;i<fifo->count;i++)
   {
     if(current_student->roll==temp_roll)
     {
        shift_buffer(index,fifo);
        fifo->head--;
        fifo->count--;
        return SISM_no_error;
     }
     current_student++;
     index++;
   }
   DPRINTF("[ERROR] Roll number is not found\n");
   return SISM_error;
}
//######################################################################################################
SISM_Buff_status up_s(SISM_Buff_t* fifo)
{
    int i,j,k,temp_option,temp_roll;
    st* current_student = fifo->base;
    //check queue is exist or not
    if(!fifo->base || !fifo->head || !fifo->tail)
    {
        DPRINTF("No database exist\n");
        return SISM_null;
    }
    //check if is empty
    if(fifo->count ==0)
    {
        DPRINTF("[ERROR] database is empty\n");
	    return SISM_empty;
    }
    DPRINTF("Enter student roll number\n");
    gets(temp_str);
    temp_roll = atoi(temp_str);

    for(i=0;i<(fifo->count);i++)
    {
      if(current_student->roll == temp_roll)
      {
        DPRINTF("Student Roll number : %d\n",current_student->roll);
	    DPRINTF("Student first name : %s\n",current_student->Fname);
	    DPRINTF("Student last name : %s\n",current_student->Lname);
	    DPRINTF("Student GPA : %.2f\n",current_student->GPA);
        for(j=0;j<5;j++)
        {
            DPRINTF("course %d id : %d \n",j+1,current_student->Cid[j]);
        }
        DPRINTF("Enter option to update data\n");
        DPRINTF("1- first name\n");
        DPRINTF("2- last name\n");
        DPRINTF("3- GPA\n");
        DPRINTF("4- courses\n");
        gets(temp_str);
        temp_option = atoi(temp_str);
        switch(temp_option)
        {
            case 1:
            {
               DPRINTF("Enter New first name\n");
               gets(current_student->Fname);
               break;
            }

            case 2:
            {
               DPRINTF("Enter New second name\n");
               gets(current_student->Lname);
               break;
            }

            case 3:
            {
                DPRINTF("Enter New GPA \n");
                gets(temp_str);
                current_student->GPA=atof(temp_str);
                break;
            }

            case 4:
            {
                DPRINTF("Enter the new course id of each course\n");
                for(i=0;i<5;i++)
			    {
				    DPRINTF("course %d id :\n",i+1);
				    gets(temp_str);
				    j=atoi(temp_str);
				    if(j>0 && j<30)              // check if course id is available id
				    {
					    current_student->Cid[i]=j;
					    continue;
				    }
				    DPRINTF("[ERROR] course id is not correct\n");
				    i--;
			    }
			    break;
            }

            default:
            {
                DPRINTF("[ERROR] invalid choice \n");
                return SISM_error;
            }
        }
        // print student information after update
        DPRINTF("information updated successfully \n");
        DPRINTF("--------------------------------------------\n");
        DPRINTF("Student Roll number : %d\n",current_student->roll);
        DPRINTF("Student first name : %s\n",current_student->Fname);
        DPRINTF("Student last name : %s\n",current_student->Lname);
        DPRINTF("Student GPA : %.2f\n",current_student->GPA);
		for(k=0;k<5;k++)
		{
			DPRINTF("course %d id : %d \n",k+1,current_student->Cid[k]);
		}
        return SISM_no_error;
       }
       current_student++;
    }
    DPRINTF("[ERROR] Roll number is not found\n");
    return SISM_error;
}
//######################################################################################################
SISM_Buff_status show_s(SISM_Buff_t* fifo)
{
  st* current_student =fifo->base;
  int i,j;
  //check queue is exist or not
  if(!fifo->base || !fifo->head || !fifo->tail)
    {
        DPRINTF("No database exist\n");
        return SISM_null;
    }
  //check if is empty
  if(fifo->count ==0)
    {
        DPRINTF("[ERROR] database is empty\n");
	    return SISM_empty;
    }

   for(i=0;i<fifo->count;i++)
    {
        DPRINTF("Student Roll number : %d\n",current_student->roll);
	    DPRINTF("Student first name : %s\n",current_student->Fname);
	    DPRINTF("Student last name : %s\n",current_student->Lname);
	    DPRINTF("Student GPA : %.2f\n",current_student->GPA);
        for(j=0;j<5;j++)
            {
                DPRINTF("course %d id : %d \n",j+1,current_student->Cid[j]);
            }
        current_student++;
    }
    DPRINTF("total number of students : %d\n",fifo->count);
    return SISM_no_error;
}
