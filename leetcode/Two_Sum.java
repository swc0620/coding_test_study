class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        HashMap<Integer,Integer> map = new HashMap<>();
        
        for (int i=0; i<nums.length; ++i) {
            if (!map.containsKey(nums[i])) {
                map.put(target-nums[i], i);
            } else {
                result[0] = map.get(nums[i]); // prev
                result[1] = i; // curr
                break; // got this
            }
        }
        return result;
    }
}