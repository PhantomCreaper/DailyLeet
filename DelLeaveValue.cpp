// 1325. Delete Leaves With A Given Value
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
    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right){
            return true;
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        queue<TreeNode*> q;
        if(root == nullptr){
            return nullptr;
        }

        root->left  = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(root->left == nullptr && root->right == nullptr && root->val == target){
            delete root;
            return nullptr;
        }
        return root;
    }
};
