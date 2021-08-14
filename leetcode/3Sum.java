// keypoints: need to know indexs 

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> answer = new HashSet<>();
        
        if (nums.length < 3)
            return new ArrayList<>(answer);
        
        Arrays.sort(nums); // to implement two pointers
        
        for (int i=0; i<nums.length-2; ++i) {
            if (nums[i] > 0) // smallest number among triplet -- unable to have sum of 0
                break;
            
            if(i == 0 || (i>0) && (nums[i]!=nums[i-1])) { // reduce redundancy -> a drastic 97% decrease in time
                int j = i + 1; // j starts at i + 1
                int k = nums.length - 1; // k starts at the end

                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                        answer.add(Arrays.asList(nums[i], nums[j++], nums[k--])); // can have another twoSum candidate
                    else if (sum < 0) // increase from lower num   
                        j++;
                    else // sum > 0 - decrease from higher num
                        k--;
                }
            }
        }
        
        return new ArrayList<>(answer);
    }
}