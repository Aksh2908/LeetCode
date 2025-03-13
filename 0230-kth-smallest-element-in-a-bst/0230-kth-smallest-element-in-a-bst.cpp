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
    void inOrder(TreeNode* root,int k,vector<int>& inorder){
        if(!root) return;
        inOrder(root->left,k,inorder);
        inorder.push_back(root->val);
        inOrder(root->right,k,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        vector<int> inorder;
        inOrder(root,k,inorder);
        return inorder[k-1];
    }
};