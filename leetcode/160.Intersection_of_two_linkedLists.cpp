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
    ListNode *compute(int d, ListNode *a, ListNode *b){
        ListNode *h1 = a, *h2 = b;
        for(int i=0;i<d;i++){
            if(h1 == NULL) return NULL;
            h1 = h1->next;
        }
        while(h1 and h2){ 
            if(h1 == h2)
                return h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1 = headA, *curr2 = headB;
        int c1=0, c2 = 0;
        while(curr1){
            c1++;
            curr1=curr1->next;
        }
        while(curr2){
            c2++;
            curr2=curr2->next;
        }
        
        if(c1>c2){
            int d = c1-c2;
            return compute(d,headA,headB);
        }
        else{
            int d = c2-c1;
            return compute(d,headB,headA);
        }
        return NULL;
    }
};