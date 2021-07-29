/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        
        ListNode *fast = head, *slow = head;
        
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
                return true;
        }
        
        return false;
    }
};

/*
fast slow
3   3
0   2
2   0
-4  -4

fast slow
1   1
1   2
1   1
*/