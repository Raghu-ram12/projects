#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RESET  "\033[0m"
#define COLOR_BLUE   "\e[34m"
typedef struct{
  int x;
  int y;
}cordinates;
int board[10][10];
int row=10;
int player1=0;
int player2=0;
void create_board(){
for(int i=0;i<10;i++){
   if(row%2==0){
    int k=row*10;
    for(int j=0;j<10;j++){
        board[i][j]=k;
        k--;
    }
   }else{
    int k=(row-1)*10+1;
    for(int j=0;j<10;j++){
        board[i][j]=k;
        k++;
    }
   }
   row--;
}
}
void Display_board(char name1[],char name2[],int x1,int y1,int x2,int y2){
     printf("\n   SNAKES AND LADDERS BOARD\n\n");
     printf("%s's  score is : %d\n",name1,player1);
     printf("%s's  score is : %d\n",name2,player2);
    for (int i = 0; i < 10; i++) {
    
        printf("   ");
        for (int k = 0; k < 10; k++) {
            printf("+-----");
        }
        printf("+\n");

        printf("   ");
        for (int j = 0; j < 10; j++) {
         int flag1=1;
         int flag2=1;
          if(j==y1&&j==y2&&i==x1&&j==y2){
            printf("%s",COLOR_BLUE);
            printf("| %3d ", board[i][j]);
            printf("%s",COLOR_RESET);
            flag1=0;
          }else{


            if(i==x1&&j==y1){
            printf("%s",COLOR_GREEN);
            printf("| %3d ", board[i][j]);
            printf("%s",COLOR_RESET);
            flag1=0;
            }

            if(i==x2&&j==y2){
            printf("%s",COLOR_RED);
            printf("| %3d ", board[i][j]);
            printf("%s",COLOR_RESET);
            flag2=0;
            }
            
            if(flag1&&flag2){
                printf("| %3d ", board[i][j]);
            }
            
           

        }
        
        }
        printf("|\n");
    }
   
    printf("   ");
    for (int k = 0; k < 10; k++) {
        printf("+-----");
    }
    printf("+\n");
}

int roll_a_die(){
    srand(time(NULL));
    return (rand()%6)+1;
}

cordinates get_position(int n){
    cordinates result;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(board[i][j]==n){
                result.x=i;
                result.y=j;
            }
        }
    }
    return result;
}

cordinates move(int p,int n){

    int ladders_start[]={4,21,29,43,63,71};
    int ladders_end[]={25,39,74,76,80,89};
    int snakes_start[]={98,92,82,73,56,47,30};
    int snakes_end[]={55,75,42,51,19,15,7};
    cordinates points;
 if(p==1){
    if(player1+n<=100){
     player1=player1+n;
     for(int i=0;i<6;i++){
        if(player1==ladders_start[i]){
            player1=ladders_end[i];
             printf("hurray you got a ladder from %d to %d\n",ladders_start[i],ladders_end[i]);
        }
     }

     for(int i=0;i<7;i++){
        if(player1==snakes_start[i]){
            player1=snakes_end[i];
             printf("oops you bit by a snake you drop from %d to %d\n",snakes_start[i],snakes_end[i]);
        }
     }

    

    }else{
        printf("OOPS! THE MOVE IS NOT POSSIBLE \n");
    }

     return  points=get_position(player1);
 }else{

    if(player2+n<=100){
       player2=player2+n;

      for(int i=0;i<6;i++){
        if(player2==ladders_start[i]){
            player2=ladders_end[i];
            printf("hurray you got a ladder from %d to %d\n",ladders_start[i],ladders_end[i]);
        }
      }
    
     
      for(int i=0;i<7;i++){
        if(player2==snakes_start[i]){
            player2=snakes_end[i];
            printf("oops you bit by a snake you drop from %d to %d\n",snakes_start[i],snakes_end[i]);
        }
     }

    
    return  points=get_position(player2);

 }
}
}
int main(){
    system("cls");
    create_board();

    char name1[50];
    char name2[50];

    printf("Enter the name of the first player\n");
    scanf(" %[^\n]",name1);

    printf("enter the name  of the second player\n");
    scanf(" %[^\n]",name2);
     int x1=0,y1=0;
     int x2=1,y2=1;
    Display_board(name1,name2,x1,y1,x2,y2);
    int player=1;
    while(player1<100&&player2<100){
    system("cls");
    Display_board(name1,name2,x1,y1,x2,y2);
    if(player==1){
    printf("player1 press R to  roll your die \n");
    if(getchar()=='r'){
          printf("rooling\n");
          Sleep(500);
          int n=roll_a_die();
          printf("you rolled %d\n",n);
          cordinates res= move(1,n);
          x1=res.x;
          y1=res.y;
           Sleep(2000);
          player=2;
    }else{
        continue;
    }
  
    }else if(player=2){
         printf("player2 press R to  roll your die \n");
        if(getchar()=='r'){
          printf("rooling\n");
          Sleep(500);
          int n=roll_a_die();
          printf("you rolled %d\n",n);
         cordinates res= move(2,n);
         x2=res.x;
         y2=res.y;
          Sleep(2000);
          player=1;
    }else{
        continue;
    }
      



   }
}
system("cls");
Display_board(name1,name2,x1,y1,x2,y2);
if(player1>player2){
    printf("%s won\n",name1);
}else{
    printf("%s won\n",name2);
}




}