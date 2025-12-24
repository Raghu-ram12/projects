#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
typedef struct {
     char name[50];
     int age;
     int id;

}employee;

employee employess[100];

int employee_count=0;
bool read(){
    FILE *file=fopen("employee.txt","r");

    if(file==NULL){
        printf("Error occured while opening the employee file\n");
        return false;
    }

    fscanf(file,"%d\n",&employee_count);

    for(int i=0;i<employee_count;i++){
        fscanf(file,"%s %d %d\n",&employess[i].name,&employess[i].age,&employess[i].id);
    }

    return true;
}

void add_employee(){
    system("cls");
    printf("=================Adding an employee=================\n");
    printf("Enter the name of the employee\n");
    scanf("%s[^\n]",&employess[employee_count].name);

    printf(" Enter the age of the employee\n");
    scanf(" %d",&employess[employee_count].age);

    int emp_id =(rand() % (99999 - 10000 + 1)) + 10000;;
    employess[employee_count].id=emp_id;

    printf("EMPLOYEE ID IS %d\n",emp_id);

    employee_count++;
    printf("employee added sucessfully\n");
    Sleep(500);

}
void Display_employee(){
    system("cls");
    for(int i=0;i<employee_count;i++){
        printf("NAME :%s\n",employess[i].name);
        printf("age  :%d\n",employess[i].age);
        printf("empid:%d\n",employess[i].id);
        printf("\n");
    }
    char c;
    while(true){
       printf("press Y to exit to menu\n");
       scanf("%c",&c);
       if(c=='Y'){
        break;
       }
    }    
   Sleep(500);
}
bool delete_employee(){
       
}
bool search_employee(){
      system("cls");

      char Name[50];
      printf("Enter the name of the employee\n");
      scanf("%s",Name);
    
    int flag=1;
    for(int i=0;i<employee_count;i++){
        if(strcmp(employess[i].name,Name)==0){
        printf("Name :%s\n",employess[i].name);
        printf("Age  :%d\n",employess[i].age);
        printf("employee id: %d\n",employess[i].id);
        printf("press Y key to exit to menu\n");
        char choice;
        scanf(" c",&choice);  
        flag=0;
        if(choice=='Y'){
            continue;
        }
           
           }
      }
      
      if(flag){
        printf("Employee not found\n");
      }

      Sleep(500);
    
}
bool save_changes(){
    system("cls");
    FILE* file=fopen("employee.txt","w");

    if(file==NULL){
        printf("error opening the file ");
        return false;
    }
    fprintf(file,"%d\n",employee_count);
    for(int i=0;i<employee_count;i++){
    fprintf(file,"%s %d %d\n",employess[i].name,employess[i].age,employess[i].id);
   }

   printf("changes saved sucessfully\n");
   
    Sleep(500);
   return true;;
}
bool edit_employee(){
    system("cls");
    char Name[50];
    printf("enter the name of the employee\n");
    scanf("%s",Name);
    int index=0;
    int flag=0;
    for(int i=0;i<employee_count;i++){
        if(strcmp(Name,employess[i].name)==0){
             index=i;
             flag=1;
        }
    }
    
    if(flag){
         int choice=0;
         printf("what do you want to edit\n");
         printf("1. Name\n2. age\n");
         printf("enter your choice\n");
          scanf("%d",&choice);
         if(choice==1){
         printf("Enter the new name\n");
         scanf("%s",&employess[index].name);
         }else if(choice==2){
         printf("enter new age\n");
         scanf(" %d",&employess[index].age);
         }else{
          printf("INVALID CHOICE\n");
          }
    }else{
        printf("Employee not found\n");
    }
   
    
        Sleep(500);
}
int main(){
    read();
    int choice=0;
    while(true){
        system("cls");
        printf("===================================================================================\n");
        printf("                           EMPLOYEEE MANAGEMENT SYSTEM                                    \n");
        printf("1. Add an employee \n");
        printf("2. Edit an employee\n");
        printf("3. search an employee\n");
        printf("4. Delete an employee\n");
        printf("5. Display all employes\n");
        printf("6. clear screen\n");
        printf("7. save changes\n");
        printf("8. Exit\n");
        printf("===================================================================================\n");
        printf("enter your choice: \n");
        scanf("%d",&choice);

        if(choice==1){
          add_employee();
        }else if(choice==2){
            edit_employee();
        }else if(choice==3){
            search_employee();
        }else if(choice==4){
            delete_employee();
        }else if(choice==5){
            if(employee_count==0){
                printf("there are no employess\n");
                continue;
            }else{
                Display_employee();
            }
           
        }else if(choice==6){
            system("cls");
        }else if(choice==7){
             save_changes();
        }else if(choice==8){
            printf("Thank you for using\n");
            break;
           
        }
        else{
            printf("INVALID CHOICE ENTER A NUMBER BETWEEN 1 TO 8\n");
        }
     
    }
}