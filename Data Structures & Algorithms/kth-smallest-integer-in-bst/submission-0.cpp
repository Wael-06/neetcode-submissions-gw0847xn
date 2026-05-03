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
    int kthSmallest(TreeNode* root, int k) {
       if(!root)return 0;

       stack<TreeNode*>s;
       int n=0;
       TreeNode*node=root;

       while(!s.empty()||node){
        while(node){
            s.push(node);
            node=node->left;
        }
        node=s.top();s.pop();
        n++;
        if(n==k)return node->val;
        node=node->right;

//k--;
//if(k==0)return node->val;

//        if(node->right)s.push(node->right);
//        if(node->left)s.push(node->left);
       }return -1;
    }
};


