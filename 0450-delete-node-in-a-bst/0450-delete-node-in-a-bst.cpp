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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val<key) root->right=deleteNode(root->right,key);
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else{
            if(!(root->left) && !(root->right)) {
                delete root;
                return nullptr;
            }
            if(!(root->right)){
                TreeNode *t=root->left;
                delete root;
                return t;
            }
            if(!(root->left)){
                TreeNode *t=root->right;
                delete root;
                return t;
            }
            else{
                TreeNode *succesor=root->right;
                while(succesor->left) succesor=succesor->left;
                root->val=succesor->val;
                root->right=deleteNode(root->right,succesor->val);
            }
        }
        return root;
    }
};