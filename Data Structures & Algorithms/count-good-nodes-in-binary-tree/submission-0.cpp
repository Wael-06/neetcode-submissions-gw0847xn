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
    int dfs(TreeNode* node, int mx) {
        if (!node) return 0;

        int good = 0;
        if (node->val >= mx) good = 1;

        mx = max(mx, node->val);

        good += dfs(node->left, mx);
        good += dfs(node->right, mx);

        return good;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
