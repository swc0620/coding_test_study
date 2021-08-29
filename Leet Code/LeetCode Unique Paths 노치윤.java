class Solution {
    public int uniquePaths(int m, int n) {
        int [][]path=new int[m][n];
        for(int i=0;i<n;i++){
            path[0][i]=1;
        }
        for(int j=0;j<m;j++){
            path[j][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                path[j][i]=path[j-1][i]+path[j][i-1];
            }
        }
        return path[m-1][n-1];
    }
}