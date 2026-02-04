#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
typedef struct
{
    int x_cord;
    int y_cord;
} coordinates;

typedef struct Node
{
    coordinates cord;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initialize_queue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

bool is_empty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int x, int y)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->cord.x_cord = x;
    newnode->cord.y_cord = y;
    newnode->next = NULL;
    if (is_empty(q))
    {
        q->front = newnode;
        q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}
coordinates dequeue(Queue *q)
{
    if (is_empty(q))
    {
        printf("queue under flow");
    }

    coordinates value;
    Node *temp = q->front;

    value = q->front->cord;

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);

    return value;
}

coordinates generate_food(int y_max, int x_max)
{
    coordinates c;
    c.y_cord = rand() % (y_max - 8);
    c.x_cord = rand() % (x_max - 8);

    return c;
}
Queue snake;
int main()
{
    initialize_queue(&snake);
    initscr();
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);
    WINDOW *gamewindow = newwin(y_max - 5, x_max - 5, 2, 2);
    nodelay(gamewindow, true);
    keypad(gamewindow, true);
    noecho();
    cbreak();
    curs_set(0);

    bool gameover = false;
    int start_y = y_max / 2;
    int start_x = x_max / 2;

    enqueue(&snake, start_x, start_y);
    enqueue(&snake, start_x - 1, start_y);
    enqueue(&snake, start_x - 2, start_y);
    int dx, dy;
    dx = 1, dy = 0;
    coordinates food = generate_food(y_max - 5, x_max - 5);
    int score=0;
    while (!gameover)
    {

        int ch = wgetch(gamewindow);
        if (ch != ERR)
        {
            if (ch == KEY_LEFT && dx != 1)
            {
                dx = -1;
                dy = 0;
            }
            if (ch == KEY_RIGHT && dx != -1)
            {
                dx = 1;
                dy = 0;
            }
            if (ch == KEY_UP && dy != 1)
            {
                dx = 0;
                dy = -1;
            }
            if (ch == KEY_DOWN && dy != -1)
            {
                dx = 0;
                dy = 1;
            }
        }
        coordinates head = snake.rear->cord;

        int new_x = head.x_cord + dx;
        int new_y = head.y_cord + dy;

        if (new_x >= x_max-7 || new_y >= y_max-7||new_x<1||new_y<1)
        {
            gameover = true;
        }

        if (new_x == food.x_cord && new_y == food.y_cord)
        {

            food = generate_food(y_max - 5, x_max - 5);
            score++;
        }
        else
        {
            dequeue(&snake);
        }

        enqueue(&snake, new_x, new_y);

        werase(gamewindow);
        box(gamewindow, 0, 0);

        Node *current = snake.front;
        while (current != NULL)
        {
            mvwprintw(gamewindow, current->cord.y_cord, current->cord.x_cord, "O");
            current = current->next;
        }

        mvwprintw(gamewindow, food.y_cord, food.x_cord, "*");
        wrefresh(gamewindow);
      
        usleep(150000);
    }

     werase(gamewindow);


    int high_score;
    FILE *scorefile=fopen("high_scores.txt","r+");
    if(scorefile!=NULL){
        fscanf(scorefile,"%d",&high_score);

        if(score>high_score){
            fprintf(scorefile,"%d",score);
        }

        fclose(scorefile);
    }else{
        scorefile=fopen("high_scores.txt","w");

        if(scorefile!=NULL){
            fprintf(scorefile,"%d",score);
            fclose(scorefile);
        }
    }
    while(1){
    box(gamewindow,0,0);
    mvwprintw(gamewindow,y_max/2,(x_max/2)-7,"GAME OVER");
    mvwprintw(gamewindow,y_max/2-2,(x_max/2)-8," your score %d",score);
    mvwprintw(gamewindow,y_max/2-4,(x_max/2)-8," high score %d",high_score);
    wrefresh(gamewindow);
    }
    getch();
    endwin();
}