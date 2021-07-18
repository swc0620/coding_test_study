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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();//Head Node을 temp로 지정.
        ListNode* ans = temp;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                ans->next = l1;
                l1 = l1->next;
            }
            else {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;//처음에는 head Node를 가리키고 있다가 그 다음 노드를 가리키게됨 
        }
        if (l1 != nullptr) {
            ans->next = l1;
        }
        if (l2 != nullptr) {
            ans->next = l2;
        }
        return temp->next;//Head Node 가 dummy head 이기에 다음노트부터 출력하면 됨.
    }
};