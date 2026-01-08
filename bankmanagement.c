#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define max_range 999999
#define min_range 100000
#define range_size (max_range-min_range+1)
int total_accounts=0;
typedef struct{
char name[100];
int account_no;
int mobile;
char date[10];
int balance;
int pin;
char adress[500];
char type[10];

}Account;
Account accounts[100];

int is_used(int n){
    for(int i=0;i<total_accounts;i++){
        if(accounts[i].account_no==n){
            return true;
        }
    }

    return false;
}
int generate_account_no(){
     bool used=false;
     int new_num;
    do{
       
        new_num = (rand() % range_size) + min_range;
     if(!is_used(new_num)){
        used=true;
     }
     
    }while(!used);

    return new_num;
}
void open_account(){
    int Pin=0;
    int Pin_2=0;
    printf("Enter the name of the account holder\n");
    fgets(accounts[total_accounts].name,100,stdin);
    printf("Enter the adress of the account holder:\n");
    fgets(accounts[total_accounts].adress,500,stdin);
    printf("Enter the type of account savings or current\n");
    fgets(accounts[total_accounts].type,10,stdin);
    printf("Enter the  mobile number:\n");
    scanf("%d",accounts[total_accounts].mobile);
    int num=generate_account_no();
    accounts[total_accounts].account_no=num;
    printf("Your account number is %d\n",num);
    while(1){

    printf("Create you pin number:");
    scanf("%d",&Pin);
    printf("Confrim your pin number\n");
    scanf("%d",&Pin_2);
    if(Pin==Pin_2){
        accounts[total_accounts].pin=Pin_2;
        break;
    }else{
        printf("Your pin does not match \n");
    }

    }


    total_accounts++;
}
int find_account(int num){
   for(int i=0;i<total_accounts;i++){
    if(accounts[i].account_no==num){
        return i;
    }
   }
}
void deposit(){
    int ammount;
    int ac_no;
    printf("Enter the number account number of employee\n");
    scanf("%d",&ac_no);
    int indx=find_account(ac_no);
    printf("your current balance is %d",accounts[indx].balance);
    printf("enter ammount to be deposited")

}
int main(){
  srand((unsigned)time(NULL));
  
  open_account();
 
}