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
int maxi;
private:
    int helper(TreeNode* node){
        if(node==nullptr)return 0;
        int leftmax=helper(node->left);
        int rightmax=helper(node->right);
        maxi=max(leftmax+rightmax,maxi);
        return max(leftmax,rightmax)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxi;
    }
};
