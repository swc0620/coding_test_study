class Solution {
  public int[][] merge(int[][] intervals) {
      if (intervals.length <= 1)
          return intervals;
      
      Arrays.sort(intervals, (a,b) -> a[0] - b[0]); // compare first element
      List<int[]> answer = new ArrayList<>();
      
      int start = intervals[0][0];
      int end = intervals[0][1];
      
      for (int[] interval : intervals) {
          if (interval[0] <= end) { // is mergeable
              end = Math.max(end, interval[1]); // more wider
          } else {
              answer.add(new int[]{ start, end });
              start = interval[0];
              end = interval[1];
          }
      }
       answer.add(new int[]{ start, end });
      
      return answer.toArray(new int[answer.size()][2]); // specify size        
  }
}