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
    int height(TreeNode* root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+(left>=right?left:right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(abs(leftHeight-rightHeight)>1) return false;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(!left || !right) return false;
        return true;
    }
};