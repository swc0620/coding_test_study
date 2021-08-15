class Solution
{
    public int solution(int [][]board)
    {

		int[][] newBoard = new int[board.length+1][board[0].length+1];
		
		for ( int i = 0 ; i < board.length; i++ ) {
			for ( int j = 0 ; j < board[0].length; j++ ) {
				newBoard[i+1][j+1] = board[i][j];
			}
		}
		
		int max = 0;
		for ( int i = 1 ; i < newBoard.length; i ++ ) {
			for ( int j = 1 ; j < newBoard[i].length; j++ ) {

				if ( newBoard[i][j] >= 1 ) {
					
					int left = newBoard[i-1][j];
					int up = newBoard[i][j-1];
					int leftDiagonal = newBoard[i-1][j-1];

					int min = Math.min(left, up);
					min = Math.min(min, leftDiagonal);
					newBoard[i][j] = min+1;
					max = Math.max(max, min+1);
				}
			}
		}
		return (int)Math.pow(max, 2);
	
    }
}
