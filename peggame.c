// Ian Lewis
// COP 3223 Section #4
// Program 11
// peggame.c
// 11/16/2014

#include <stdio.h>

#define YES 1
#define NO 0
#define ROWS 5
#define COLS 9

void setboard(char board[ROWS][COLS]);
void printboard(char board[ROWS][COLS]);
void movepeg(char board[ROWS][COLS], int i, int j, int x, int y);
int checkmove(char board[ROWS][COLS], int *i, int *j, int *x, int *y);
void end(char board[ROWS][COLS], int i, int j);


int main() {

    int i, j, x, y;
    char board[ROWS][COLS];

    //Create board and print
    setboard(board);
    printboard(board);

    //While move is possible, ask for input and make move
    while (checkmove(board,&i,&j,&x,&y)==YES) {
        movepeg(board,i,j,x,y);
    }

    //If no move is possible, end game
    if (checkmove(board,&i,&j,&x,&y)==NO);
        end(board,i,j);

    return 0;
}

int checkmove(char board[ROWS][COLS], int *i, int *j, int *x, int *y) {

    int count=1;

    //Ask for user input
    printf("What are the row and column of your starting peg?\n");
    scanf("%d%d", &(*i), &(*j));
    printf("What are the row and column of the hole to jump to?\n");
    scanf("%d%d", &(*x), &(*y));

    //Check to see if any moves are possible on board (unfinished)
    //for (*i=0; *i<ROWS; *i++) {
      //  for (*j=0; *j<COLS; *j++) {
        //    if (board[*i][*j]=='P') {
          //      count++;
            //}
        //}
    //}

    //If moves are possible, return yes, otherwise return no (unfinished)
    //if (count>1)
        //return YES;

    //else return NO;
}

void movepeg(char board[ROWS][COLS], int i, int j, int x, int y) {

    //(1,1)=[0,4]
    //(2,1)=[1,3]/(2,2)=[1,5]
    //(3,1)=[2,2]/(3,2)=[2,4]/(3,3)=[2,6]
    //(4,1)=[3,1]/(4,2)=[3,3]/(4,3)=[3,5]/(4,4)=[3,7]
    //(5,1)=[4,0]/(5,2)=[4,2]/(5,3)=[4,4]/(5,4)=[4,6]/(5,5)=[4,8]

    //Following if's check to replace user input with proper array coordinates

    if (i==1) {
        j=4;
    }

    if (i==2) {
        if (j==1)
            j=3;
        else if (j==2)
            j=5;
    }

    if (i==3) {
        if (j==1)
            j=2;
        else if (j==2)
            j=4;
        else if (j==3)
            j=6;
    }

    if (i==4) {
        if (j==1)
            j=1;
        else if (j==2)
            j=3;
        else if (j==3)
            j=5;
        else if (j==4)
            j=7;
    }

    if (i==5) {
        if (j==1)
            j=0;
        else if (j==2)
            j=2;
        else if (j==3)
            j=4;
        else if (j==4)
            j=6;
        else if (j==5)
            j=8;
    }

    //Set x coordinate to x-1
    i-=1;

    //Set start point to a hole
    //Set end point to a P
    //Set mid point (average of the two x points and average of the two y points) to a hole
    board[i][j]='.';
    board[x][y]='P';
    board[(i+x)/2][(j+y)/2]='.';

    printboard(board);

}

void end(char board[ROWS][COLS], int i, int j) {

    int count=0;

    //Count how many pegs left
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (board[i][j]=='P') {
                count++;
            }
        }
    }

    //Print end result
    printboard(board);
    printf("No more jumps are possible. You have %d pegs.\n", count);
    printf("Good bye!");
}

void printboard(char board[ROWS][COLS]) {

    int i, j;

    printf("Here is the game board:\n");

    // Print the game board based on pegs and holes that are in the array
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if ((board[i][j]=='P')||(board[i][j]=='.')) {
                    printf("%c", board[i][j]);
            }
            else printf(" ");
        }
        printf("\n");
    }
}

void setboard(char board[ROWS][COLS]) {

    int i, ja, jb;

    // Initialize the game board.
    for (i=0,ja=4,jb=4; i<ROWS; i++) {
        board[i][ja+i] = 'P';
        board[i][jb-i] = 'P';

        if (i==3) {
            board[i][ja+1] = 'P';
            board[i][jb-1] = 'P';
        }

        if (i==4) {
            board[i][ja+2] = 'P';
            board[i][jb-2] = 'P';
            board[i][4] = 'P';
        }
    }

    //Set starting point
    board[2][4] = '.';
}
