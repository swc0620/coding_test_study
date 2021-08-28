class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size() , i = 1 , j = 0 ;
        vector<vector<int>> res;
        if (n == 0 || n == 1) return intervals;
        sort(intervals.begin() , intervals.end());
        res.push_back(intervals[0]);
        while (i < n){
            if (res[j][1] >= intervals[i][1]){
               i++;
            }
            else if (res[j][1] >= intervals[i][0]){
               res[j][1] = intervals[i][1];
               i++;
            }
            else{
                res.push_back(intervals[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};