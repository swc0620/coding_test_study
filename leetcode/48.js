class Solution {
    public void rotate(int[][] matrix) {
       int len = matrix[0].length;
        for(int i=0;i<len/2;i++){
            for(int j=0;j<len;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[len-i-1][j];
                matrix[len-i-1][j]=temp;
            }
        }
        for(int i=0;i<len;i++){
            for(int j=len-1;j>i;j--){
                if(i==j) continue;
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
}
