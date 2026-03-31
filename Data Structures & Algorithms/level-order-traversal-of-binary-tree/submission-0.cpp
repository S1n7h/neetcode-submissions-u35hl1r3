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
        if (!root)  return ret;
        queue<TreeNode*> check;
        check.push(root);
        vector<int> ugh = {root->val};
        ret.push_back(ugh);
        while(!check.empty()){
            int size = check.size();
            vector<int> temp;
            for(int i = 0 ; i < size ; i++){
                TreeNode* top = check.front();
                check.pop();
                if (top->left){
                    temp.push_back(top->left->val);
                    check.push(top->left);
                }if (top->right){
                    temp.push_back(top->right->val);
                    check.push(top->right);
                }
            }if (!temp.empty()) ret.push_back(temp);
        }return ret;
    }
};
