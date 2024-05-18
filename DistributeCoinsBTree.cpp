// 979. Distribute Coins in Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int coinfs(TreeNode* root, int& moves){
        if(root == nullptr){
            return 0;
        }
        int left = coinfs(root->left, moves);
        int right = coinfs(root->right, moves);
        moves+= abs(left)+abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        coinfs(root, moves);
        return moves;
    }
};
