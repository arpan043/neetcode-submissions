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
    int search(vector<int>& inorder, int left, int right,int val){
        for(int i = left; i <= right;i++){
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preOrderIndex,
                         int left, int right)
    {
        if(left>right){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preOrderIndex]);

        int inOrderIndex = search(inorder, left, right, preorder[preOrderIndex] );
        preOrderIndex++;

        root->left = helper(preorder, inorder,preOrderIndex, left, inOrderIndex-1);
        root->right = helper(preorder, inorder,preOrderIndex, inOrderIndex+1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        return helper(preorder, inorder,preOrderIndex, 0, (int)inorder.size()-1);
    }
};