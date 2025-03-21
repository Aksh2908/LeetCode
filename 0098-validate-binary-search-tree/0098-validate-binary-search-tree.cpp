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
    bool inOrder(TreeNode* root,long long &prev){
        if(!root) return true;
        if(!inOrder(root->left,prev)) return false;
        if(root->val<=prev) return false;
        prev=root->val;
        return inOrder(root->right,prev);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return -1;
        long long flag=LLONG_MIN;
        return inOrder(root,flag);
    }
};