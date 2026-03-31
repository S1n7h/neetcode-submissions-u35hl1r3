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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root)  return ret;
        queue<TreeNode*> temp;
        temp.push(root);
        ret.push_back(root->val);
        while(!temp.empty()){
            int size = temp.size();
            int counter = 0;
            for (int i = 0 ; i < size ; i++){
                TreeNode* top = temp.front();
                temp.pop();
                if (top->right){
                    if (counter == 0){
                        ret.push_back(top->right->val);
                        counter++;
                    }temp.push(top->right);
                }if (top->left){
                    if (counter == 0){
                        ret.push_back(top->left->val);
                        counter++;
                    }temp.push(top->left);
                }
            }
        }return ret;
    }
};
