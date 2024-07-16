// 2096. Step-by-step directions from BT node to another
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
    bool findPath(TreeNode* root, int tar, string &str){
        if(root == NULL) return false;
        if(root->val == tar) return true;
        bool left = findPath( root->left, tar, str);
        if(left){
            str += 'L';
            return true;
        }
        bool right = findPath( root->right, tar, str);
        if(right){
            str += 'R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
       string rootToSrc="";
       findPath(root,startValue,rootToSrc);

       string rootToDst="";
       findPath(root,destValue,rootToDst);
       cout<<"src "<<rootToSrc<<endl;
       cout<<"dst "<<rootToDst<<endl;
       int i = rootToSrc.size() - 1;
        int j = rootToDst.size() - 1;
         while(i>=0 && j>=0 && rootToSrc[i] == rootToDst[j]){
            rootToSrc.pop_back();
            rootToDst.pop_back();
            i--;
            j--;
        }
        i = rootToSrc.size();
        for(int j=0; j<i; j++){
            rootToSrc[j] = 'U';
        }
        reverse(rootToDst.begin(), rootToDst.end());
        return rootToSrc + rootToDst;
    }
};
