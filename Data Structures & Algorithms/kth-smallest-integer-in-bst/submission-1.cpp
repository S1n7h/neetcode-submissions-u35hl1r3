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
    int dfs(TreeNode* root, int k, int& counter){
        if (!root)  return -1;

        int left = dfs(root->left, k, counter);
        if (left != -1) return left;

        counter++;
        if (counter == k)   return root->val;

        return dfs(root->right, k, counter); 
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        return dfs(root, k, counter);
    }
};
