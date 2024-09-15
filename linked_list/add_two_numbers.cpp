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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 && l2) {
            l1->val += l2->val;
            if (l1->val >= 10) {
                l1->val -= 10;
                if (l1->next) {
                    l1->next->val += 1;
                } else {
                    l1->next = new ListNode(1);
                }
            }

            if (!l1->next && l2->next) {
                l1->next = new ListNode();
            }
        }

        return l1;
    }
};
