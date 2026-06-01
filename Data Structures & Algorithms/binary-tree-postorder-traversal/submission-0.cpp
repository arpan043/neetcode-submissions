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
private:
    void postOrder(TreeNode* node){
        if(node == nullptr)
            return;
        
        postOrder(node->left);
        postOrder(node->right);
        output.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return output;
    }
};