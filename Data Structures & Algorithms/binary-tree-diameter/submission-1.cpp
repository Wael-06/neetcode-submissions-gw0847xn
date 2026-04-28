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
    int diameter=0;
    int depth (TreeNode*root){
        if(!root)return 0;

        int rightlen=depth(root->right);
        int leftlen=depth(root->left);
        diameter=max(diameter, rightlen+leftlen);
        return 1+max(rightlen,leftlen);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};
/*
class Solution {
public:
    int diameter = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        // update diameter (path through this node)
        diameter = max(diameter, left + right);

        // return height
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};*/