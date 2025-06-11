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
    TreeNode* insertIntoBST(TreeNode* ans, int n) {

        TreeNode* root = ans;
        if(root  == NULL){
            ans = new TreeNode(n);
            return ans;
        }
        while(true){
            if(root->val < n){
                if(root->right == NULL){
                    break;
                }
                root = root->right;
            }
            else{
                if(root->left == NULL){
                    break;
                }
                root = root->left;
            }
        }
        TreeNode* node = new TreeNode(n);
        if(root->val > n){
            root->left = node;
        }
        else{
            root->right = node;
        }
        return ans\;
    }
};