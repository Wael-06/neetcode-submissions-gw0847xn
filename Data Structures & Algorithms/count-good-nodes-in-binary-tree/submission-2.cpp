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
    int res=0;
    void dfs(TreeNode* root,int max_element){
        if(!root)return;

        if(root->val>=max_element){
            res++;
            max_element=max(max_element,root->val);
        }
        
        dfs(root->left,max_element);
        
        dfs(root->right,max_element);

    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return res;
    }
};
