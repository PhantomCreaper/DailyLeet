// 988. Smallest String from Leaf
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
    string smallestFromLeaf(TreeNode* root) {
        return helper(root, "");
    }

    string helper(TreeNode* root, string current){
        if(!root){
            return "|";
        }
        current = char('a' + root->val) + current;

        if (!root->left && !root->right) {
            return current;
        }

        string left = "|", right = "|";
        if (root->left) {
            left = helper(root->left, current);
        }
        if (root->right) {
            right = helper(root->right, current);
        }

        return min(left, right);
    }
};
