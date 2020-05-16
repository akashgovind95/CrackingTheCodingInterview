/*
Design 1: Have all possible winning board scenarions in a map and check if the current board is a winning board or not. If yes, return the winner. If no, return 0;

Although now you can know if there is a winner in O(1) lookup but converting the board into a way that it can be looked up is O(N^2) where N is the number of rows or columns in the board. 
Here we use base 3 representation of the board.

In the board, 0 == empty space, 1 == player1, 2 == player2
The base 3 representation of the board is saved as the key in the map and value as who has won.
*/



int hasWon(vector<vector<int>> &board, unordered_map<int,int> &winnerTable){
    int size = baord.size();
    int sum = 0;
    for(int i =0;i<N;i++)
        for(int j =0;j<N;j++)
            sum = sum*3 + value;
    
    return winnerTable[sum];
    
}


/*
Design 2: What if we know the last move? 
For every move, call hasWon() and it'll tell if we can of the row, column or diagnol is filled by the same player. 
We only need to pass the current board and the lastes move to the function. 

*/

bool hasWon(vector<vector<int>> &board, int row, int col){

    if(checkRow(board,row) || checkCol(board,col))
        return true;
    
    if(checkDiagnol(board))
        return true;

    retun false;
}

checkRow(vector<vector<int>> &board, int row){

    for(int i=1;i<board.size();i++){
        if(board[row][i] != board[row][0])
            return false;
    }
    return true;
}

checkCol(vector<vector<int>> &board, int col){

    for(int i=1;i<board.size();i++){
        if(board[i][col] != board[0][col])
            return false;
    }
    return true;
}
checkDiagnol(vector<vector<int>> &board, int col){

    int N=board.size()-1;
    //check left to right diagnol
    for(int i = 1;i<=N;i++){
        if(board[i][i] != board[0][0])
            return false;
    }
    return true;
    
    //check right to left diagnol
    for(int i = 1;i<=N;i++){
        if(board[i][N-i] != board[0][N])
            return false;
    }
    return true;

}

/*
Design 3:  Solving for 3x3 board. Here, we can hardcode value to check if we have a winner. We don't really need to know the last move here.
*/

bool hasWon(vector<vector<int>> board){
    int N = board.size();

    for(int i = 0;i<N;i++){
        if(hasWinner(board[i][0],board[i][1],board[i][2]))
            return true;
        if(hasWinner(board[0][i],board[1][i],board[2][i]))
            return true;
    }

    if(hasWinner(board[0][0],board[1][1],board[2][2]))
        return true;
    if(hasWinner(board[0][2],board[1][1],board[2][0]))
        return true;
}

bool hasWinner(int x, int y, int z){
    if(x==y && y==z)
        return true;
    return false
}

