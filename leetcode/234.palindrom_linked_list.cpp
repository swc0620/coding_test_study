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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        
        // st에 값 모두 대입
        while (head != NULL){
            st.push(head->val);
            head = head->next;
        }
        
        // 맨 마지막 값과 맨 처음 값 비교
        while (temp != NULL){ 
            int i = st.top();
            st.pop();
            if (temp->val != i){
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
};