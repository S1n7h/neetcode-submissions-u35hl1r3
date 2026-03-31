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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> check;
        if (!root)  return ret;
        check.push(root);

        while(!check.empty()){
            int size = check.size();
            vector<int> temp;
            for(int i = 0 ; i < size ; i++){
                TreeNode* top = check.front();
                check.pop();

                temp.push_back(top->val);

                if (top->left) check.push(top->left);
                if (top->right) check.push(top->right);
            }ret.push_back(temp);
        }return ret;
    }
};
