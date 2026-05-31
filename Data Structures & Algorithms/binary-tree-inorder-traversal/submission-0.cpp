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
    vector<int> output;
private :
    void inorder(TreeNode* node){
        if(!node)
            return;
            
        inorder(node->left);
        output.push_back(node->val);
        inorder(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return output;
    }
};