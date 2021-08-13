import java.util.Arrays;
import java.util.*;
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> answer=new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int left=-1;
        int right=nums.length;
        int zero=-1;
        if(nums.length<3){
            return answer;
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]<0) left++;//left는 음수의 마지막 지점
            if(zero==-1&&nums[i]==0){
                zero=i;//zero는 0의 시작지점
            }
            if(nums[i]>0){
                right=i;//right는 양수 시작지점
                break;
            }

        }
        
        Set<List<Integer>> set=new HashSet<List<Integer>>();
        
        if((zero!=-1&&right==nums.length&&nums.length-zero>=3)||(right!=nums.length&&zero!=-1&&right-zero>=3)) {
        	//0이 존재하고, 양수는 존재안하고,0의 개수가 3개이상인경우 or 양수와 0이 존재하고 0의 개수가 3개 이상이면 000을 추가.
            List<Integer> temp=new ArrayList<Integer>();
            temp.add(0);
            temp.add(0);
            temp.add(0);
            set.add(temp);            
        }

        //1. --+ 인 경우
        for(int i=0;i<left;i++){
            for(int j=i+1;j<=left;j++){
                for(int z=nums.length-1;z>=right;z--){
                        if(nums[i]+nums[j]+nums[z]==0){
                            List<Integer> temp=new ArrayList<Integer>();
                            temp.add(nums[i]);
                            temp.add(nums[j]);
                            temp.add(nums[z]);
                            set.add(temp);
                            break;
                        }
                        else if(nums[i]+nums[j]+nums[z]<0) break;
                }
            }
        }
        //2. -0+ 인 경우
        if(zero!=-1){
            for(int i=0;i<=left;i++){
                for(int j=nums.length-1;j>=right;j--){
                    if(nums[i]+nums[j]==0){
                        List<Integer> temp=new ArrayList<Integer>();
                        temp.add(nums[i]);
                        temp.add(0);
                        temp.add(nums[j]);
                        set.add(temp);
                        break;
                    }
                }
            }
        }
        
        //3. -++ 인 경우
        
        for(int i=nums.length-1;i>right;i--){
            for(int j=i-1;j>=right;j--){
                for(int z=0;z<=left;z++){
                        if(nums[i]+nums[j]+nums[z]==0){
                            List<Integer> temp=new ArrayList<Integer>();
                            temp.add(nums[z]);
                            temp.add(nums[j]);
                            temp.add(nums[i]);
                            set.add(temp);
                            break;
                        }
                        else if(nums[i]+nums[j]+nums[z]>0) break;
                }
            }
        }
        Iterator<List<Integer>> iter=set.iterator();
        while(iter.hasNext()){
            List<Integer> a=iter.next();
            answer.add(a);
        }
        return answer;
    }
}