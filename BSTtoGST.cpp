// 1038. BST to GST
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInOrder(root, sum);
        return root;
    }
    
    void reverseInOrder(TreeNode* root, int& sum) {
        if (root == nullptr) return;
        
        reverseInOrder(root->right, sum);
        
        sum += root->val;
        root->val = sum;
        
        reverseInOrder(root->left, sum);
    }
};
