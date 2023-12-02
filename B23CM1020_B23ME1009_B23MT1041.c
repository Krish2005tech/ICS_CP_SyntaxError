#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


#define SIZE 20

int maze[SIZE][SIZE];
int arr[SIZE][SIZE];

// check validity and if unvisited
int isValidCell(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 1;
}


int hasUnvisitedNeighbors(int x, int y) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int newX = x + 2 * dx[i];
        int newY = y + 2 * dy[i];

        if (isValidCell(newX, newY)) {
            return 1; 
        }
    }

    return 0; 
}


void dfs(int x, int y) {
    maze[x][y] = 0; // form path

    // define random direction vector
    int directions[] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int randIndex = i + rand() % (4 - i);
        int temp = directions[i];
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }

    // dfs now applied to surroundings
    for (int i = 0; i < 4; i++) {
        int newX = x + 2 * (directions[i] == 2 ? -1 : (directions[i] == 3 ? 1 : 0));
        int newY = y + 2 * (directions[i] == 0 ? 1 : (directions[i] == 1 ? -1 : 0));

        if (isValidCell(newX, newY)) {
            maze[x + (newX - x) / 2][y + (newY - y) / 2] = 0; // Making a passage
            dfs(newX, newY); // using Recursion
        }
    }
}


void initializeMaze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = 1;
        }
    }
}


void printMaze(int maze[SIZE][SIZE], int startX, int startY, int goalX, int goalY) {

/*
for(int k=0 ; k<SIZE+2 ; ++k){printf("# ");}
printf("\n");
    for (int i = 0; i < SIZE; i++) {
            printf("# ");
        for (int j = 0; j < SIZE; j++) {
            if(i==startX && j==startY){
                printf("S ");
            }
            else if(i==goalX && j==goalY){
                printf("G ");
            }
            else{
            printf("%d ", maze[i][j]);}
        }
        printf("# ");
        printf("\n");
    }
    for(int k=0 ; k<SIZE+2 ; ++k){printf("# ");}
     printf("\n\n\n");*/


     for(int k=0 ; k<SIZE+1 ; ++k){printf("# ");}
     printf("\n");
 for (int i = 0; i < SIZE-1; i++) {
    printf("# ");
        for (int j = 0; j < SIZE-1; j++) {

            if(i==startX && j==startY){
                printf("S ");
            }
            else if(i==goalX && j==goalY){
                printf("G ");
            }
            else{
            if(maze[i][j] == 0){
                printf("  ");
            }else if(maze[i][j] == 1){
                printf("[]");
            }else if(maze[i][j] == 2){
                printf("S ");
            }else if(maze[i][j] == 3){
                printf("G ");
            }else if(maze[i][j] == 4){
                printf(". ");
            }else if(maze[i][j] == 5){
                printf("+ ");
            }}
        }
        printf("# ");
        printf("\n");
    }
    for(int k=0 ; k<SIZE+1 ; ++k){printf("# ");}
}


int isValid(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}


int solveMazeDFS(int maze[SIZE][SIZE], int x, int y, int goalX, int goalY,int startX,int startY) {
  
// for animation effct
    system("cls");
    printMaze(maze,startX,startY,goalX,goalY);
    delay(0.01); 




    if (!isValid(x, y) || maze[x][y] == 1 || maze[x][y] == 4) {
        return 0;
    }

    
    if (x == goalX && y == goalY) {
        maze[x][y] = 5; 
        return 1;
    }

   // 4 == '.'  means path checked/in process of checking
    maze[x][y] = 4;

    // Explore neighbors in a specific order: up, right, down, left
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (solveMazeDFS(maze, newX, newY, goalX, goalY,startX,startY)) {
            maze[x][y] = 5;
            return 1;
        }
    }

    return 0;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void intro_project(){
    printf("####################################\n");
    printf("####################################\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##      RANDOM MAZE GENERATOR     ##\n");
    printf("##           AND SOLVER           ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##         BY : KRISH             ##\n");
    printf("##              ANSHIT            ##\n");
    printf("##              SUDHANSHU         ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("##      PRESS ENTER TO CONTNUE :  ##\n");
    printf("##                                ##\n");
    printf("##                                ##\n");
    printf("####################################\n");
    printf("####################################\n");
    getch();
}

/*
maze markers:
0-> empty space
1-> wall
2-> start
3-> goal
4-> path checked
5-> path to goal by dfs
*/


int main() {
    system("cls");
    srand(time(NULL)); // Seed for random number generation
    initializeMaze();
    intro_project();

    // start maze generation from top left
    dfs(0, 0);

    int startX, startY, goalX, goalY;

    // Randomly selecting a start and goal
    do {
        startX = rand() % SIZE;
        startY = rand() % SIZE;
    } while (maze[startX][startY] != 0);

    do {
        goalX = rand() % SIZE;
        goalY = rand() % SIZE;
    } while (maze[goalX][goalY] != 0 || (goalX == startX && goalY == startY));

  
    maze[startX][startY] = 2;
    maze[goalX][goalY] = 3;

    printf("\n\nThe Generated maze  \n\n");
    printMaze(maze, startX, startY, goalX, goalY);
    printf("\n\n\n");
    printf("Press Enter to start solving : ");
    getch();
    printf("\n\n\n");
    if (solveMazeDFS(maze, startX, startY, goalX, goalY, startX, startY))
    {
        printf("Solved Maze:\n\n\n");
        // printMaze(maze,startX,startY,goalX,goalY);
    }
    else
    {
        printf("No solution found.\n");
    }
    system("cls");
    printMaze(maze, startX, startY, goalX, goalY);
    // delay(5);
    // system("cls");
    getch();

    return 0;
}




