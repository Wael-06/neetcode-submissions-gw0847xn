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

/*class Solution {
public:
    bool res=true;
    int maxDepth(TreeNode* root) {
        if(!root)return 0;

        int right=maxDepth(root->right);
        int left=maxDepth(root->left);
        if(left==right||left+1==right||right+1==left)res=true;
        else res=false;
        return 1+max(right,left);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return res;
        maxDepth(root);

        return res;
        if(!root)return true;
        int left=maxDepth(root->left);
        int right= maxDepth(root->right);
        if (left==right||left+1==right||right+1==left)return true;

        return false;*/
   // }
//};
class Solution {
public:
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        if (left == -1) return -1;

        int right = dfs(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
