/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next) return NULL; // Since n is always valid so if size of listis 1 n will be 1 so we can return NULL. 
        
        ListNode* n1 = head; // First pointer
        ListNode* n2 = head; // Second Pointer
        
        int c = 0;
		// Take second pointer n2  to that node such that n2-n1 = n.
        while(c != n){
            n2 = n2->next;
            c++;
        }
        
		// If n2 reached the end of the list, it means we have to remove the head of the list.
        if(n2 == NULL)        
            return n1->next;
        
		// Taking n2 to end of the list and n1 n places before the end.
        while(n2->next != NULL){
            n1 = n1->next;
            n2 = n2->next;
        }
        // deleting nth node.
        n1->next = n1->next->next;
        return head;
    }
};