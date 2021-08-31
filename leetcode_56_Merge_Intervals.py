class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        out = []
        for interval in sorted(intervals, key=lambda interval: interval[0]):
            if out and interval[0] <= out[-1][1]:
                out[-1][1] = max(out[-1][1], interval[1])
            else:
                out += interval,
        return out