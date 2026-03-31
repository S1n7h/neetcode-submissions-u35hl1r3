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
    int dfs(TreeNode* root){
        if (!root)  return 0;

        int leftnode = dfs(root->left);
        if (leftnode == -1) return -1;

        int rightnode = dfs(root->right);
        if (rightnode == -1) return -1;

        if (abs(rightnode - leftnode) > 1)  return -1;
        return 1 + max(leftnode, rightnode);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (dfs(root) != -1)  return true;
        return false;
    }
};
