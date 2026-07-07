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
    int height(TreeNode* node){
        if(node==nullptr)return 0;
        int maxleft=height(node->left);
        if(maxleft==-1)return -1;
        int maxright=height(node->right);
        if(maxright==-1)return -1;
        if(abs(maxright-maxleft)>1)return -1;
        return max(maxleft,maxright)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};
