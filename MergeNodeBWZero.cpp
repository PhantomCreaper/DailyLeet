// 2181. Merge Node Between Zero
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
    ListNode* mergeNodes(ListNode* head) {
        int currSum = 0;
        ListNode* node = head->next;
        ListNode* newHead = new ListNode(0);
        ListNode* tail = newHead;
        while(node != nullptr){
            if(node->val == 0){
                ListNode* newNode = new ListNode(currSum);
                tail->next = newNode;
                tail = newNode;
                currSum = 0;
            }
            else{
                currSum += node->val;
            }
            node = node->next;
        }
        return newHead->next;
    }
};
