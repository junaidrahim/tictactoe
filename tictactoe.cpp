#include <iostream>

using namespace std;

void printGame(char matrix[3][3]){
    // just prints a 3x3 char matrix
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            cout << " ";
            if(k==2){
                cout << matrix[j][k] ;
            } else {
                cout << matrix[j][k] << " |";
            } 
        }
        cout << endl;
    }
}

bool input_validity_check(char game[3][3], int row, int col){
    if (game[row][col]==' '){
        return true;
    }
    else {
        return false;
    }
}

int checkWinner(char game[3][3]){
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
}

int main(){
    char matrix[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    for(int i=0;i<9;i++){
        if(i%2==0) {
            // Even Turn. O
            int r,c;
            cout << "Enter Row and Column(o): " ;
            cin >> r >> c;

            if(input_validity_check(matrix, r, c)){
                matrix[r][c] = 'O';
                printGame(matrix);
            }
            else {
                cout << "Invalid, that position is already taken" << endl;
                cout << "Play again" << endl;
                break;
            }

            if (checkWinner(matrix) == 1){
                cout << "O won" << endl;
                break;
            }
        }

        else {
            // Odd turn. X
            int r,c;
            cout << "Enter Row and Column(x): " ;
            cin >> r >> c;

            if(input_validity_check(matrix, r, c)){
                matrix[r][c] = 'X';
                printGame(matrix);
            }
            else {
                cout << "Invalid, that position is already taken" << endl;
                cout << "Play again" << endl;
                break;
            }

            if (checkWinner(matrix) == 2){
                cout << "X won" << endl;
                break;
            }   
        }
    }


    return 0;
}
