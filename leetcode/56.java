import java.util.*;
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        LinkedList<Interval> merged = new LinkedList<>();
        if (intervals == null || intervals.size() == 0) {
            return merged;
        }
        Collections.sort(intervals, (a, b) -> a.start - b.start);
        for (Interval interval : intervals) {
            if (merged.isEmpty() || merged.getLast().end < interval.start) {
                merged.add(interval);
            } else {
                merged.getLast().end = Math.max(merged.getLast().end, interval.end);
            }
        }
        return merged;
    }
}
class Interval{
    int start;
    int end;
    Interval(int a,int b){
        this.start = a;
        this.end= b;
    }
}
