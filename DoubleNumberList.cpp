// 2816. Double a number represented as a Linked list
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head); 
        ListNode *temp = head, *prev = nullptr;
        int carry = 0;

        while (temp != nullptr) {
            int doubledValue = temp->val * 2 + carry;
            temp->val = doubledValue % 10;
            carry = doubledValue / 10; 
            prev = temp;
            temp = temp->next;
        }

        if (carry > 0) {
            prev->next = new ListNode(carry);
        }

        head = reverseList(head); 
        return head;
    }
};
