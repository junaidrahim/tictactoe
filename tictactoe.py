# A dictionary of the grid values as tuples
# {(0,0):'X', (0,1):'O', ...}
matrix = {(r,c):' ' for r in range(0,3) for c in range(0,3)}

def check_winner(game):
    # Check Diagonals
    winX_diagonal1 = game[0,0] == game[1,1] == game[2,2] == 'X'
    winX_diagonal2 = game[0,2] == game[1,1] == game[2,0] == 'X'

    winO_diagonal1 = game[0,0] == game[1,1] == game[2,2] == 'O'
    winO_diagonal2 = game[0,2] == game[1,1] == game[2,0] == 'O'

    if(winO_diagonal1 or winO_diagonal2):
        return 1   # O won
    elif(winX_diagonal1 or winX_diagonal2):
        return 2   # X won

    for m in range(0,3):
        winX_vertical = game[0,m] == game[1,m] == game[2,m] == 'X'
        winX_horizontal = game[m,0] == game[m,1] == game[m,2] == 'X'

        winO_vertical = game[0,m] == game[1,m] == game[2,m] == 'O'
        winO_horizontal = game[m,0] == game[m,1] == game[m,2] == 'O'

        if(winO_vertical or winO_horizontal):
            return 1   # O won
        elif(winX_vertical or winX_horizontal):
            return 2   # X Won
    
    return 0   # no winner


def input_validity_check(game, row, col):
    if game[row,col] == ' ':
        return True
    else:
        return False


def print_game(game): 
    for i in range(0,3):
        print(" {} | {} | {} \n".format(game[i,0],game[i,1],game[i,2]))


for t in range(0,9):
    if t%2 == 0:
        # Even Turn. O
        play = input("Enter Row and Column(O): ")
        play = play.split(" ")

        row = int(play[0])
        col = int(play[1])

        if input_validity_check(matrix, row, col):
            matrix[row,col] = 'O'
            print_game(matrix)
        else:
            print("Invalid, that position is already taken")
            print("Play again")
            break
        
        if check_winner(matrix) == 1:
            print("O won")
            break

    else:
        # Odd Turn. X
        play = input("Enter Row and Column(X): ")
        play = play.split(" ")

        row = int(play[0])
        col = int(play[1])

        if input_validity_check(matrix, row, col):
            matrix[row,col] = 'X'
            print_game(matrix)
        else:
            print("Invalid, that position is already taken")
            print("Play again")
            break

        if check_winner(matrix) == 2:
            print("X won")
            break
        