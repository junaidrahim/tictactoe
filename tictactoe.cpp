#include <iostream>

using namespace std;

void printGame(char matrix[3][3]){
    // just prints a 3x3 char martix
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

int checkWinner(char game[3][3]){
    // 1. Check all horizontal rows
    // 2. Check all vertical colums
    // 3. Check the diagonals

    //horizontal check
    for(int x=0; x<3; x++){
        bool winX = (game[x][0]=='x') && (game[x][1]=='x') && (game[x][2]=='x');

        bool winO = (game[x][0]=='o') && (game[x][1]=='o') && (game[x][2]=='o');
        
        if(winX){
            return 1;
        }
        else if(winO){
            return 2;
        }
    }

    // vertical check
    for(int y=0; y<3; y++){
        bool winX = (game[0][y]=='x') && (game[1][y]=='x') && (game[2][y]=='x');

        bool winO = (game[0][y]=='o') && (game[1][y]=='o') && (game[2][y]=='o');
        
        if(winX){
            return 1;
        }
        else if(winO){
            return 2;
        }
    }

    // diagonal check
    
    bool winX1 = (game[0][2]=='x') && (game[1][1]=='x') && (game[2][0]=='x');
    bool winX2 = (game[0][0]=='x') && (game[1][1]=='x') && (game[2][2]=='x');

    bool winO1 = (game[0][2]=='o') && (game[1][1]=='o') && (game[2][0]=='o');
    bool winO2 = (game[0][0]=='o') && (game[1][1]=='o') && (game[2][2]=='o');

    if(winX1 || winX2){
        return 1;
    }
    else if(winO1 || winO2){
        return 2;
    }
    else{
        return 0;
    }
        
}

int main(){
    char matrix[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    for(int i=0;i<9;i++){
        int row,col;

        if(i%2==0) {
            // Even Turn. O
            cout << "Enter Row and Column(o): " ;
            cin >> r >> c;

            matrix[row][col] = 'o';
            printGame(matrix);
            if (checkWinner(matrix) == 2){
                cout << "O won" << endl;
                break;
            }
        }

        else {
            // Odd turn. X
            cout << "Enter Row and Column(x): " ;
            cin >> r >> c;

            matrix[row][col] = 'x';
            printGame(matrix);
        
            if (checkWinner(matrix) == 1){
                cout << "X won" << endl;
                break;
            }   
        }
    }


    return 0;
}
