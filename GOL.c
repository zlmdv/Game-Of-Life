#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>  
#include <string.h>

/* RULES OF CONWAYS GAME OF LIFE:
    1. Any empty cell with three live neighbours becomes alive, as if by reproduction. 
    2. Any live cell with more than three live neigbors becomes dead, as if by overpopulation.
    3. Any live cell with fewer than two neighbours dies, as if by underpopulation.
    4. Any cell with two or three live neighbours lives on the the next generation.
*/
#define rows 80
#define cols 40

char BoardA[rows][cols]; 
char BoardB[rows][cols]; 
int sum; 

int initBoard();
int cellCount(char BoardA [rows][cols],char BoardB [rows][cols], int x, int y);
void Evo(char BoardA [rows][cols],char BoardB [rows][cols]);
void drawBoard(char BoardA [rows][cols]);
void Swap(char BoardA[rows][cols], char BoardB[rows][cols]); 

int initBoard(){
    int i;
    int j; 
    for(i =0; i <rows; i++){
        for(j =0; j<cols; j++){
            BoardA[i][j] = rand()%2;  //inits each cell to be alive or dead
        }
    }
    return(BoardA[i][j]);
}

int cellCount(char BoardA [rows][cols],char BoardB [rows][cols], int x, int y){
    int sum = 0; 
    for(int i = -1; i <2; i++){
        for (int j = -1; j<2; j++){ //counts neighbor cells
            sum += BoardA[i][j];
        }
    }
    sum -= BoardA[x][y]; 
    return sum;
}     

void Evo(char BoardA [rows][cols],char BoardB [rows][cols]){    //function to control the evolution of the game according to the rules
    for(int i=0; i <rows; i++){
        for(int j=0; j<cols; j++){
            int state = BoardA[i][j];
            if( state ==1 && sum < 2){  //if an alive cell has two live neighbors it dies
                BoardB[i][j] ==0; 
            }else if(state==1 && sum >3){ //more than three neighbours it dies
                BoardB[i][j]==0; 
            }else if(state == 0 && sum==2 ||sum ==3){
                BoardB[i][j]==1; 
            }else if(state==1 &&sum ==3){
                BoardB[i][j]==1; 
            }
        }
    }
}
void Swap(char BoardA[rows][cols], char BoardB[rows][cols]){
    for(int i = 0; i <rows; i++){
        for(int j = 0; j <cols; j++){
            BoardA[i][j] = BoardB[i][j];
            BoardB[i][j] = BoardA[i][j];
        }
    }
}

void drawBoard(char BoardA[rows][cols]){
    for(int i=0; i <rows; i++){
        for(int j=0; j<cols; j++){
            if(BoardA[i][j]){
                printf("█"); 
           }else{
               printf(" ");
           } 
           printf("\n"); 
        }
    }
}

int main(char BoardA [rows][cols],char BoardB [rows][cols]){
    srand(time(0));  //uses internal clock to choose random numbers

    initBoard(BoardA); 

    while(1){
        system("clear"); 
        //drawBoard(BoardA); //pointer to a new board

        Evo(BoardA, BoardB); 

        Swap(BoardA, BoardB); 

        usleep(10000/4);

    }
    return 0; 
}
    

