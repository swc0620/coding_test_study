// 33.Search_in_Rotated_Sorted_Array.cpp

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if (A[m] == target)
                return m;
            else if (A[l] <= A[m]) { /* left part is sorted */
                if (A[l] <= target && target < A[m]) /* target is in the left part */
                    r = m - 1;
                else  /* target is in the right part */
                    l = m + 1;                               
            } else {/* right part is sorted */
                if (A[m] < target && target <= A[r]) /* target is in the right part */
                    l = m + 1;
                else /* target is in the left part */
                    r = m - 1;
            }
        }
        
        return -1;
    }
};