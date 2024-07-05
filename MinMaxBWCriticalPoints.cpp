// 2058. Return Min and Max Number of Node Between Critical Points
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        ListNode* prev = nullptr;
        ListNode* node = head;
        int pos = 0;
        while(node && node->next){
            if(prev && node->next){
                if((node->val > prev->val && node->val > node->next->val) ||
                    (node->val < prev->val && node->val < node->next->val)){
                        points.push_back(pos);
                    }
            }
            prev = node;
            node = node->next;
            pos++;
        }
        if(points.size() < 2){
            return {-1, -1};
        }
        int minD = INT_MAX;
        int maxD = points.back() - points.front();
        for(int i = 1; i < points.size(); i++){
            minD = min(minD, points[i] - points[i-1]);
        }
        return {minD, maxD};
    }
};
