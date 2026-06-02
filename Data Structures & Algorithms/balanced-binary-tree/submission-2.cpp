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
private:
    int getHeight(TreeNode* node){
        if(node == nullptr)
            return 0;
        
        int leftSubtreeHeight = getHeight(node->left);
        int rightSubtreeHeight = getHeight(node->right);

        if(leftSubtreeHeight == -1 || rightSubtreeHeight == -1)
            return -1;
            
        int balanced = abs(leftSubtreeHeight-rightSubtreeHeight);
        if(balanced > 1)
            return -1;
        
        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }    
public:
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        if(height != -1)
            return true;
        
        return false;
    }
};
