package main

import (
	"fmt"
)

func check_winner(game [3][3]string) int {

	winO_diagonal1 := (game[0][0]=="O") && (game[1][1]=="O") && (game[2][2]=="O")
	winO_diagonal2 := (game[0][2]=="O") && (game[1][1]=="O") && (game[2][0]=="O")

	winX_diagonal1 := (game[0][0]=="X") && (game[1][1]=="X") && (game[2][2]=="X")
	winX_diagonal2 := (game[0][2]=="X") && (game[1][1]=="X") && (game[2][0]=="X")

	if (winO_diagonal1 || winO_diagonal2){
		return 1
	} else if (winX_diagonal1 || winX_diagonal2) {
		return 2
	}

	for i:=0; i<3; i++ {

		winO_vertical   := (game[0][i]=="O") && (game[1][i]=="O") && (game[2][i]=="O" )
		winO_horizontal := (game[i][0]=="O") && (game[i][1]=="O") && (game[i][2]=="O")

		winX_vertical   := (game[0][i]=="X") && (game[1][i]=="X") && (game[2][i]=="X")
		winX_horizontal := (game[i][0]=="X") && (game[i][1]=="X") && (game[i][2]=="X")

		if (winO_horizontal || winO_vertical) {
			return 1
		} else if (winX_horizontal || winX_vertical) {
			return 2
		}
	}

	return 0;

}

func print_game(game [3][3]string){
	for i:=0; i<3; i++{
		p := game[i][0] + " | " + game[i][1] + " | " + game[i][2]
 		fmt.Println(p)
	}
}


func main(){
	var matrix [3][3]string

	for i:=0; i<3; i++{
		matrix[i][0] = " "
		matrix[i][1] = " "
		matrix[i][2] = " "
	}

	for t:=0; t<9; t++{

		if (t%2 == 0){
			// Even turn, O
			var play [2]int

			fmt.Print("Enter Row and Column(O): ")
			for i:=0; i<2; i++{ fmt.Scan(&play[i]) }

			matrix[play[0]][play[1]] = "O"
			
			print_game(matrix)
			
			if (check_winner(matrix)==1){
				fmt.Println("O Won")
				break;
			}

		} else {

			var play [2]int

			fmt.Print("Enter Row and Column(X): ")
			for i:=0; i<2; i++ { fmt.Scan(&play[i]) }

			matrix[play[0]][play[1]] = "X"
			
			print_game(matrix)
			
			if (check_winner(matrix)==2){
				fmt.Println("X won")
				break
			}
		}
	}
}