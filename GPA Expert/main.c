#include <stdio.h>
#include <stdlib.h>

void degree_status(int s,int d_s,float g)
{
    d_s=0;
  if(s<=8 && s>1&&g<2 && d_s==0)
  {
      d_s=1;
      printf("Degree status:Probation\n");
  }
  else if(s==8 && g>2 && d_s==0)
  {
      d_s=0;
      printf("Degree status:Completed\n");
  }
  else if(s>=1 && s<=7 && g>2 && d_s==0)
  {
      d_s=0;
      printf("Degree status:Continue\n");
  }
  else if(s>=1 && s<+8 && g<2 && d_s==1)
  {
      d_s=2;
      printf("Degree Status:DI\nStart over the next time,better luck next time!\n");
  }
  else if(s>=1 && s<=7 && g>2&&d_s==1)
  {
      d_s=0;
      printf("Degree Status:Continue\n");
  }
}
int main()
{
    int std_marks[8][7];
    int sems,subj;
    float swg,cgpa,ocgpa,sg;//swg=subject wise gpa,sg=semester gpa//
    int a=0,ds=0;//a is counter variable for while loop and ds is variable used for  function  //
    for(int i=0;i<8;i++) // means no marks have been entered//
    {
        for(int j=0;j<7;j++)
        {
            std_marks[i][j]=-1;
        }
    }
    printf("How many semesters have you completed?(max=8):");
    scanf("%d",&sems);
    printf("\n\n\n");
    while(sems>8||sems<1)//validation of input//
    {
        printf("Invalid input! ");
        printf("How many semesters have you completed?(max=8):");
        scanf("%d",&sems);
        printf("\n\n\n");
    }
        for(int i=0;i<sems;i++)
        {
            printf("\t\t\t***Semester %d***\n",i+1);
            printf("How many subjects have you studied in this semester?(max=7):");
            scanf("%d",&subj);
            while(subj>7||subj<1)//validation for subjects//
            {
                printf("Invalid input!\n");
                printf("How many subjects have you studied in this semester?(max=7)");
                scanf("%d",&subj);
            }
            for(int j=0;j<subj;j++)
            {
              printf("Enter marks(0-100) for subject#%d:",j+1);
              scanf("%d",&std_marks[i][j]);
              while (std_marks[i][j]>100 || std_marks[i][j]<1)//validation for marks//
              {
                fflush(stdin);
                printf("Invalid input!\n");
                printf("Enter marks(0-100) for subject#%d:",j+1);
                scanf("%d",&std_marks[i][j]);
              }

            }
        }
        for (int i=0;i<sems;i++)
{
	printf("==============================================\n");
	printf("Semester#%d Result\n",i+1);
    printf("==============================================\n");
    printf("Subject no.:\t\t\tSubject grade:\t\tGPA:\n");
    a=0;
    sg=0;
    while(std_marks[i][a]!=-1)//It will read the values until -1 comes//
    {
        if(std_marks[i][a]>90&&std_marks[i][a]<=100)
        {
            swg=4.0;
          printf("%d\t\t\t\t\tA\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>84&&std_marks[i][a]<=90)
        {
            swg=3.7;
             printf("%d\t\t\t\t\tA-\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>79&&std_marks[i][a]<=84)
        {
            swg=3.3;
            printf("%d\t\t\t\t\tB+\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>74&&std_marks[i][a]<=79)
        {
            swg=3.0;
            printf("%d\t\t\t\t\tB\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>69&&std_marks[i][a]<=74)
        {
            swg=2.7;
             printf("%d\t\t\t\t\tB-\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>64&&std_marks[i][a]<=69)
        {
            swg=2.3;
             printf("%d\t\t\t\t\tC+\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>59&&std_marks[i][a]<=64)
        {
            swg=2.0;
             printf("%d\t\t\t\t\tC\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>54&&std_marks[i][a]<=59)
        {
            swg=1.7;
              printf("%d\t\t\t\t\tC-\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]>49&&std_marks[i][a]<54)
        {
            swg=1.3;
             printf("%d\t\t\t\t\tD\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        else if(std_marks[i][a]<50)
        {
          swg=0;
           printf("%d\t\t\t\t\tF\t\t%.1f\t\t\t%d\n",a+1,swg,std_marks[i][a]);
        }
        sg=sg+swg;
        a=a+1;
    }
   printf("\t\t\t\t\t\t\tSemester GPA:%.2f\n\n",sg/a);
   cgpa=cgpa+(sg/a);
   printf("\t\t\t\t\t\t\t\tCGPA:%.2f\n",cgpa/(i+1));
   degree_status(sems,ds,cgpa);
}

printf("--------------------------------------\n");
ocgpa=cgpa/sems;
printf("Overall CGPA:%.2f\n",ocgpa);

}

