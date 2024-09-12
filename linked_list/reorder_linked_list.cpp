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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while (fast && fast -> next) {
            slow = slow -> next;

            fast = fast -> next;
            fast = fast -> next;
        }

        // reverse the latter half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow -> next;
        slow -> next = nullptr;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next; 
        }

        ListNode* head_back = prev;
        ListNode* head_front = head;
        while (head_back) {
            ListNode* next_front = head_front -> next;
            ListNode* next_back = head_back -> next;

            head_front -> next = head_back;
            head_back -> next = next_front;

            head_front = next_front;
            head_back = next_back;
        }
    }
};
