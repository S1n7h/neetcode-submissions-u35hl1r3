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
    int gmaximum = -1001;
private:
    int helper(TreeNode* root){
        if (!root)  return -1001;

        int tleft = helper(root->left);
        int tright = helper(root->right);
        
        int compare = root->val + tleft + tright;

        if (compare > tright && compare > tleft && compare > root->val && compare > tright + root->val && compare > tleft + root->val){
            gmaximum = max(gmaximum, compare);
        }else{
            gmaximum = max(gmaximum, max(tleft, tright));
        }return max(root->val, max(root->val + tright, root->val + tleft));
    }
public:
    int maxPathSum(TreeNode* root) {
        cout << gmaximum;
        int temp = helper(root);
        if (gmaximum > temp)    return gmaximum;
        return temp;
    }
};
