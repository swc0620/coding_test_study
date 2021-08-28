class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = nums.size();
		int target = size - 1, i;

		for (i = size - 1; i >= 0; i--) {
            if ((nums[i] + i) >= target)
                target = i;
		}

		return (target == 0);
	}
};