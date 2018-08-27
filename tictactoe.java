import java.util.Scanner;

// The class to control all the parts of the matrix
class game{
    // the main game matrix
    char matrix[][] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    // To record and implement the current move
    public void play(char p, int row, int col){
        if(p=='X'){
            matrix[row][col] = 'X';
        }
        else if (p=='O'){
            matrix[row][col] = 'O';
        }
    }

    // To print the game
    public void print_game(){
        for(int i=0; i<3; i++){
            String print = matrix[i][0] + " | " + matrix[i][1] + " | " + matrix[i][2];
            System.out.println(print);
        }
    }

    // To check the winner
    public int check_winner(){
        // Checks the diagonals
        boolean winO_diagonal1 = (matrix[0][0]=='O') && (matrix[1][1]=='O') && (matrix[2][2]=='O');
        boolean winO_diagonal2 = (matrix[0][2]=='O') && (matrix[1][1]=='O') && (matrix[2][0]=='O');

        boolean winX_diagonal1 = (matrix[0][0]=='X') && (matrix[1][1]=='X') && (matrix[2][2]=='X');
        boolean winX_diagonal2 = (matrix[0][2]=='X') && (matrix[1][1]=='X') && (matrix[2][0]=='X');        

        if (winO_diagonal1 || winO_diagonal2){
            return 1;   // O won
        }
        else if (winX_diagonal1 || winX_diagonal2){
            return 2;   // X won
        }

        // Checks rows and columns simultaneously
        for(int i=0; i<3; i++){
            boolean winO_horizontal = (matrix[i][0]=='O') && (matrix[i][1]=='O') && (matrix[i][2]=='O');
            boolean winO_vertical   = (matrix[0][i]=='O') && (matrix[1][i]=='O') && (matrix[2][i]=='O');
            
            boolean winX_horizontal = (matrix[i][0]=='X') && (matrix[i][1]=='X') && (matrix[i][2]=='X');
            boolean winX_vertical   = (matrix[0][i]=='X') && (matrix[1][i]=='X') && (matrix[2][i]=='X');
            
            if (winO_horizontal || winO_vertical){
                return 1;   // O won
            } 
            else if(winX_horizontal || winX_vertical){
                return 2;   // X won
            }
        }

        return 0;
    }
}

public class tictactoe{
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        game tictac = new game();

        for(int i=0; i<9; i++){

            if(i%2==0){
                // Even Turn. O
                System.out.print("Enter row and column(O): ");
                String a = input.nextLine();
                String[] player_input = a.split(" ");   // "1 0" -> ["1","0"] 

                tictac.play('O', Integer.parseInt(player_input[0]), Integer.parseInt(player_input[1]));
                tictac.print_game();
                
                int result = tictac.check_winner();
                if(result==1){
                    System.out.println("O won");
                    break;
                } 
                else if (result==2){
                    System.out.println("X won");
                    break;
                }
            } 
            
            else {
                // Odd Turn. X
                System.out.print("Enter row and column(X): ");
                String a = input.nextLine();
                String[] player_input = a.split(" ");   // "0 0" -> ["0","0"] 

                tictac.play('X', Integer.parseInt(player_input[0]), Integer.parseInt(player_input[1]));
                tictac.print_game();
                
                int result = tictac.check_winner();
                if(result==1){
                    System.out.println("O won");
                    break;
                } 
                else if (result==2){
                    System.out.println("X won");
                    break;
                }
            }
        }
        input.close();
    }
}
