import java.util.*;
public class Solution {
  public static void main(String[] args) {
		String s = "1 2 3 4";
		String s2 = "-1 -2 -3 -4";
		String s3 = "-1 -1";
		solution(s);
	}
	public static String solution(String s) {
		String[] arr = s.split(" ");
		ArrayList<Integer> nums = new ArrayList<>();
		for(int i = 0; i < arr.length; i++) {
			nums.add(Integer.parseInt(arr[i]));
		}
		
		Collections.sort(nums);
		
		return String.valueOf(nums.get(0)) + " " + String.valueOf(nums.get(nums.size() - 1));
	}
}
