// 48.rotate_image.cpp

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix[0].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0, k=matrix[0].size()-1; j < k; j++, k--)
                swap(matrix[i][j], matrix[i][k]);
        }
    }
};


/* 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int j=0;j<matrix[0].size();j++){
            vector<int>v;
            for(int i=size-1;i>=0;i--){
                v.push_back(matrix[i][j]);  // start from the end and take the jth element of each vector and push it in the new vector
            }
            matrix.push_back(v);  // now push this new vector in matrix list 
        }
        for(int i=0;i<size;i++)
            matrix.erase(matrix.begin());    // delete the given vectors
    }
};
*/