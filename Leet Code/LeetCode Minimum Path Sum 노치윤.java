class Solution {
    public int minPathSum(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        
        int[][] shortest=new int[m][n];
        shortest[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            shortest[0][i]=grid[0][i]+shortest[0][i-1];
        }
        for(int j=1;j<m;j++){
            shortest[j][0]=grid[j][0]+shortest[j-1][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++){
                shortest[j][i]=(shortest[j-1][i]>shortest[j][i-1])?shortest[j][i-1]+grid[j][i]:shortest[j-1][i]+grid[j][i];
            }
        }
        return shortest[m-1][n-1];
    }
}