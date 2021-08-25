class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int loop=(n/2+n%2);
        int len=n-1;
        for(int i=0;i<loop;i++){//0,0 ~ (loop-1, loop-1) 까지
            for(int j=0;j<len;j++){//1칸씩 이동을 len번 반복
                int x=i;
                int y=i;
                int []direction={0,1,2,3};//0 -> right, 1 -> down, 2->left, 3->up
                int direc=0;
                int temp=matrix[x][y];
                do{
                    if(direc==0){
                        if(y==(n-i-1)){
                            direc++;
                        }
                        else{
                            int temp2=temp;
                            temp=matrix[x][y+1];
                            matrix[x][y+1]=temp2;
                            y++;                        
                        }
                    }
                    if(direc==1){
                        if(x==(n-i-1)){
                            direc++;
                        }
                        else{
                            int temp2=temp;
                            temp=matrix[x+1][y];
                            matrix[x+1][y]=temp2;
                            x++;                        
                        }
                    }
                    if(direc==2){
                        if(y==i){
                            direc++;
                        }
                        else{
                            int temp2=temp;
                            temp=matrix[x][y-1];
                            matrix[x][y-1]=temp2;
                            y--;                       
                        }
                    }
                    if(direc==3){
                        if(x!=i){
                            int temp2=temp;
                            temp=matrix[x-1][y];
                            matrix[x-1][y]=temp2;
                            x--;
                        }
                    }
                }
                while(x!=i||y!=i);                
            }
            len-=2;
        }
    }
}