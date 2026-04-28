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
    /*bool checker(TreeNode* root, TreeNode* subRoot){
        if(root->val==subRoot->val){
            TreeNode* left=root->left;TreeNode*right=root->right;
            TreeNode* subleft=subRoot->left;TreeNode* subright=subRoot->right;
            while(true){
                if()

                left=root->right;right=root->left;
                subleft=subRoot->left;subright=subRoot->right;
            }
        }
        checker(root->left,subRoot);
        checker(tree->right,subRoot);
    }*/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        if(!p||!q) return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root && subRoot)return false;

        if(!subRoot)return true;

        if(root->val==subRoot->val){
            if(isSameTree(root,subRoot))return true;
        }    
        return isSubtree(root->left,subRoot)||
        isSubtree(root->right,subRoot);
        
    }
};
