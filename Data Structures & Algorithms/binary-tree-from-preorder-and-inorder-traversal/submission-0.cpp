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
/*

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
       
        v.push_back(root->val);
        inorder(root->right);
        inorder(root->left);
         
*/
class Solution {
public:
    unordered_map<int,int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,int left,int right){
         if(left>right)return nullptr;

        int root_val=preorder[preIndex++];
        TreeNode* root= new TreeNode(root_val);

        int mid=pos[root_val];

        root->left=build(preorder,left,mid-1);
        root->right=build(preorder,mid+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
        pos[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};
