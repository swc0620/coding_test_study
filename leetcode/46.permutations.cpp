// 46.permutations.cpp

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ans.push_back(nums);
        }
        
        return ans;
    }
};

/* 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>vec;
        DFS(nums, 0, vec, res);
        return res;
    }
    
    void DFS(vector<int>& nums, int pos, vector<int>& vec, vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i = 0; i <= vec.size(); i++){
            vec.insert(vec.begin() + i, nums[pos]);
            DFS(nums, pos + 1, vec, res);
            vec.erase(vec.begin() + i);
        }
        return;
    }
};
*/