#include<stdio.h>
int  is_leap(int year){
    if((year%4==0&&year%100!=0)||(year%400==0)){
        return 1;
    }else{
        return -1;
    }
}
int get_day(int n){
    switch(n){
        case 0:
         printf("Sunday\n");
         break;
        case 1:
        printf("Monday\n");
        break;
        case 2:
        printf("Tuesday\n");
        break;
        case 3:
        printf("Wednesday\n");
        break;
        case 4:
        printf("Thrusday\n");
        break;
        case 5:
        printf("Friday\n");
        break;
        case 6:
        printf("saturday\n");
        break;
    }
}
int caluclate_odd_days(int day,int month,int year){

    int odd=0;
    int leap=0;
    if(is_leap(year)==1){
        leap=1;
    }
    if(year>=400){
        year=year%400;
        
     }
    if(year>=300){
       year=year%300;
       
        odd++;
    }

    if(year>=200){
        year=year%200;
        
        odd=odd+3;
    }

    if(year>=100){
        year=year%100;
       
        odd+=5;
    }

    if(month>0){
        year--;
    }
   
    int leap_years=year/4-(year/100)+(year/400);
    int normal_years=year-leap_years;
    odd=odd+(leap_years*2+normal_years);

   int months[]={0,3,0,3,2,3,2,3,3,2,3,2,3};

   for(int i=1;i<month;i++){
    if(i==2&&leap==1){
        odd+=1;
        
    }else{
        odd+=months[i];
        
    }
   }

   odd+=day;
   return odd%7;

}

int get_no_days_in_month(int month,int year){
   if(month==1){
    return 31;
   }else if(month==2){
       if(is_leap(year)==1){
        return 29;
       }else{
        return 28;
       }
   }else if(month==3){
       return 31;
   }else if(month==4){
       return 30;
   }else if(month==5){
    return 31;
   }else if(month==6){
    return 30;
   }else if(month==7){
    return 31;
   }else if(month==8){
    return 31;
   }else if(month==9){
    return 30;
   }else if(month==10){
    return 31;
   }else if(month==11){
    return 30;
   }else{
    return 31;
   }
}
void print_calender(int month, int year){
    int start=caluclate_odd_days(1,month,year);
    int days=get_no_days_in_month(month,year);
    int k=0;

    printf("sun    mon    tue    wed    thu    fri    sat    \n");
    for(int i=0;i<start;i++){
      printf("       ");
      k++;
    }

    for(int j=1;j<=days;j++){
        printf("%3d    ",j);


        if(++k>6){
           printf("\n");
           k=0;
        }
    }
}
int main(){
    int d,m,y;
  printf("enter the date in format dd-mm-yyy\n");
  scanf("%d-%d-%d",&d,&m,&y);
  get_day(caluclate_odd_days(d,m,y));

  print_calender(2,2026);
}