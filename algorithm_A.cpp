#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions 
 * 1. ~ 4. are listed in next block)
 * 
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 * 
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/

int heuristic(Board board, char color){
    int score = 0, myOrbs = 0, oppOrbs = 0;
    bool vulnerable; // vulnerable means its neighbor is almost explosion
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            vulnerable = false;
            if(board.get_cell_color(i, j) == color){
                myOrbs += board.get_orbs_num(i, j);
                switch(board.get_capacity(i, j)){
                    case 2:
                        if(i == 0 && j == 0){
                            if(board.get_cell_color(0, 1) != color && board.get_cell_color(0, 1) != 'w' && board.get_orbs_num(0, 1) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(1, 0) != color && board.get_cell_color(1, 0) != 'w' && board.get_orbs_num(1, 0) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                        }
                        else if(i == 0 && j == 5){
                            if(board.get_cell_color(0, 4) != color && board.get_cell_color(0, 4) != 'w' && board.get_orbs_num(0, 4) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(1, 5) != color && board.get_cell_color(1, 5) != 'w' && board.get_orbs_num(1, 5) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                        }
                        else if(i == 4 && j == 0){
                            if(board.get_cell_color(3, 0) != color && board.get_cell_color(3, 0) != 'w' && board.get_orbs_num(3, 0) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(4, 1) != color && board.get_cell_color(4, 1) != 'w' && board.get_orbs_num(4, 1) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                        }
                        else if(i == 4 && j == 5){
                            if(board.get_cell_color(3, 5) != color && board.get_cell_color(3, 5) != 'w' && board.get_orbs_num(3, 5) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(4, 4) != color && board.get_cell_color(4, 4) != 'w' && board.get_orbs_num(4, 4) == 2){
                                score -= (5 - 2);
                                vulnerable = true;
                            }
                        }
                        break;
                    case 3:
                        if(i == 0){
                            if(board.get_cell_color(i+1, j) != color && board.get_cell_color(i+1, j) != 'w' && board.get_orbs_num(i+1, j) == (board.get_capacity(i+1, j)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i, j-1) != color && board.get_cell_color(i, j-1) != 'w' && board.get_orbs_num(i, j-1) == (board.get_capacity(i, j-1)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i, j+1) != color && board.get_cell_color(i, j+1) != 'w' && board.get_orbs_num(i, j+1) == (board.get_capacity(i, j+1)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                        }
                        else if(j == 0){
                            if(board.get_cell_color(i, j+1) != color && board.get_cell_color(i, j+1) != 'w' && board.get_orbs_num(i, j+1) == (board.get_capacity(i, j+1)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i-1, j) != color && board.get_cell_color(i-1, j) != 'w' && board.get_orbs_num(i-1, j) == (board.get_capacity(i-1, j)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i+1, j) != color && board.get_cell_color(i+1, j) != 'w' && board.get_orbs_num(i+1, j) == (board.get_capacity(i+1, j)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                        }
                        else if(i == 4){
                            if(board.get_cell_color(i-1, j) != color && board.get_cell_color(i-1, j) != 'w' && board.get_orbs_num(i-1, j) == (board.get_capacity(i-1, j)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i, j-1) != color && board.get_cell_color(i, j-1) != 'w' && board.get_orbs_num(i, j-1) == (board.get_capacity(i, j-1)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i, j+1) != color && board.get_cell_color(i, j+1) != 'w' && board.get_orbs_num(i, j+1) == (board.get_capacity(i, j+1)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                        }
                        else if(j == 5){
                            if(board.get_cell_color(i, j-1) != color && board.get_cell_color(i, j-1) != 'w' && board.get_orbs_num(i, j-1) == (board.get_capacity(i, j-1)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i-1, j) != color && board.get_cell_color(i-1, j) != 'w' && board.get_orbs_num(i-1, j) == (board.get_capacity(i-1, j)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                            if(board.get_cell_color(i+1, j) != color && board.get_cell_color(i+1, j) != 'w' && board.get_orbs_num(i+1, j) == (board.get_capacity(i+1, j)-1)){
                                score -= (5 - 3);
                                vulnerable = true;
                            }
                        }
                        break;
                    case 4:
                        if(board.get_cell_color(i, j+1) != color && board.get_cell_color(i, j+1) != 'w' && board.get_orbs_num(i, j+1) == (board.get_capacity(i, j+1)-1)){
                            score -= (5 - 4);
                            vulnerable = true;
                        }
                        if(board.get_cell_color(i, j-1) != color && board.get_cell_color(i, j-1) != 'w' && board.get_orbs_num(i, j-1) == (board.get_capacity(i, j-1)-1)){
                            score -= (5 - 4);
                            vulnerable = true;
                        }
                        if(board.get_cell_color(i-1, j) != color && board.get_cell_color(i-1, j) != 'w' && board.get_orbs_num(i-1, j) == (board.get_capacity(i-1, j)-1)){
                            score -= (5 - 4);
                            vulnerable = true;
                        }
                        if(board.get_cell_color(i+1, j) != color && board.get_cell_color(i+1, j) != 'w' && board.get_orbs_num(i+1, j) == (board.get_capacity(i+1, j)-1)){
                            score -= (5 - 4);
                            vulnerable = true;
                        }
                        break;
                }
            }else if(board.get_cell_color(i, j) != color && board.get_cell_color(i, j) != 'w'){
                oppOrbs += board.get_orbs_num(i, j);
            }
        }
    }

    score += myOrbs;
    if(oppOrbs == 0 && myOrbs > 1)
        return 10000;
    else if(myOrbs == 0 && oppOrbs > 1)
        return -10000;

    // adjacent not yet

    return score;
}

void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Experimental Heuristic ////////////
    //srand(time(NULL));
    int row, col, maxScore = -10001;
    char color = player.get_color();
    int score[5][6] = {{0}};
    Board newBoard;

    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            newBoard = board;
            if(board.get_cell_color(i, j) == color || board.get_cell_color(i, j) == 'w'){
                newBoard.place_orb(i, j, &player);
                score[i][j] = heuristic(newBoard, color);
            }else{
                score[i][j] = -10002;
            }
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            if(score[i][j] > maxScore){
                maxScore = score[i][j];
                row = i;
                col = j;
            }
        }
    }

    index[0] = row;
    index[1] = col;
}