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
    TreeNode* FindPredecesor(TreeNode* node){
        while(node->right)
            node = node->right;
        
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        
        if(root->val < key){

            root->right = deleteNode(root->right,key);
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            if((root->left == nullptr) && (root->right == nullptr))
                return nullptr;
            
            if(root->left == nullptr){
                return root->right;
            }else if(root->right == nullptr){
                return root->left;
            }
            else{
                TreeNode* node = FindPredecesor(root->left);
                root->val = node->val;
                root->left = deleteNode(root->left, node->val);
            }
        }
        return root;
    }
};