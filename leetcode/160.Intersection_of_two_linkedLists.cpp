class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;
		ListNode *curA = headA;
		ListNode *curB = headB;
		int lenA = std::numeric_limits<int>::max() / 2, lenB = lenA;
		for (int i = 0; i != lenA + lenB - 1; ++i)
			if (curA->next)
				curA = curA->next;
			else {
				curA = headB;
				lenA = i + 1;
			}
			if (curB->next)
				curB = curB->next;
			else {
				curB = headA;
				lenB = i + 1;
			}
			if (curA == curB)
				return curA;
		}
		return NULL;
    }
};