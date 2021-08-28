class Solution {
    int n=0;
    public boolean canJump(int[] nums) {
        N = nums.length;
        
        boolean[] visited = new boolean[nums.length];
        Queue<Integer> queue = new LinkedList<Integer>();
    
        visited[0] = true;
        queue.add(0);
        
        while(!queue.isEmpty()) {
            int idx = queue.poll();
  
            for (int i = 1; i <= nums[idx]; i++) {
                int newIdx = idx + i;

                if (!isInside(newIdx) || visited[newIdx])
                    continue;

                if (newIdx == N - 1)
                    return true;
                
                visited[newIdx] = true;
                queue.add(newIdx);
            }
        }
        
        return visited[N-1];
    }
    public boolean isInside(int x) {
        if (0 <= x && x < N)
            return true;;
        return false;
    }
    
}
