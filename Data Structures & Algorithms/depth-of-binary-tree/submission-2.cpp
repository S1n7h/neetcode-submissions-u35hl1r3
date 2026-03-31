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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root)   q.push(root);

        int length = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0 ; i < size ; i++){
                TreeNode* top = q.front();
                q.pop();

                if (top->left)  q.push(top->left);
                if (top->right)  q.push(top->right);
            }length++;
        }return length;
    }
};
