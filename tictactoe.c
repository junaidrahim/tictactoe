#include <stdio.h>
#include <stdbool.h>

void print_matrix(char game[3][3]){ // just to print the game
    for(int i=0; i<3; i++){
        printf("%c | %c | %c \n", game[i][0], game[i][1], game[i][2]);
    }
}

bool input_validity_check(char game[3][3], int row, int col){
    if(game[row][col]==' '){
        return true;
    } else {
        return false;
    }
}

int check_winner(char game[3][3]){
    // Checks diagonals
    bool winO_diagonal1 = (game[0][0]=='O') && (game[1][1]=='O') && (game[2][2]=='O');
    bool winO_diagonal2 = (game[0][2]=='O') && (game[1][1]=='O') && (game[2][0]=='O');

    bool winX_diagonal1 = (game[0][0]=='X') && (game[1][1]=='X') && (game[2][2]=='X');
    bool winX_diagonal2 = (game[0][2]=='X') && (game[1][1]=='X') && (game[2][0]=='X');
    
    if (winO_diagonal1 || winO_diagonal2){
        return 1;
    }
    else if (winX_diagonal1 || winX_diagonal2){
        return 2;
    }
    
    // Checks Rows and Columns simultaneously
    for (int i=0; i<3; i++){
        bool winO_horizontal = (game[i][0]=='O') && (game[i][1]=='O') && (game[i][2]=='O');
        bool winO_vertical   = (game[0][i]=='O') && (game[1][i]=='O') && (game[2][i]=='O');

        bool winX_horizontal = (game[i][0]=='X') && (game[i][1]=='X') && (game[i][2]=='X');
        bool winX_vertical   = (game[0][i]=='X') && (game[1][i]=='X') && (game[2][i]=='X');

        if (winO_horizontal || winO_vertical){
            return 1; // O won
        }
        else if (winX_horizontal || winX_vertical){
            return 2; // X won
        }

    }

    return 0; // no winner 
}

int main(){
    char matrix[3][3];

    for(int i=0; i<3; i++){ // Filling up the matrix
        matrix[i][0]=' ';
        matrix[i][1]=' ';
        matrix[i][2]=' ';
    }

    for(int t=0; t<9; t++){
        if(t%2==0){
            // Even Turn, O
            int row, col;
            
            printf("Enter Row and Column(O): ");
            scanf("%d %d", &row, &col);

            if (input_validity_check(matrix,row,col)){
                matrix[row][col] = 'O';
                print_matrix(matrix);
            } 
            else {
                printf("Invalid, that position is already taken\n");
                printf("Play Again\n");
                break;
            }

            if(check_winner(matrix)==1){
                printf("O Won\n");
                break;
            }  
        }
        else{
            // Odd Turn, X
            int row, col;
            
            printf("Enter Row and Column(X): ");
            scanf("%d %d", &row, &col);

            if (input_validity_check(matrix,row,col)){
                matrix[row][col] = 'X';
                print_matrix(matrix);
            } 
            else {
                printf("Invalid, that position is already taken\n");
                printf("Play Again\n");
                break;
            }

            if(check_winner(matrix)==2){
                printf("X Won\n");
                break;
            }  
        }

    }

    return 0;
}