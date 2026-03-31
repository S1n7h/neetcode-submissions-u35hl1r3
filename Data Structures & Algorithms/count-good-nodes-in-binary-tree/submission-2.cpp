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
    int goodNodes(TreeNode* root) {
        int ret = 0;
        if (!root)  return ret;
        queue<pair<TreeNode*, int>> temp;
        temp.push({root, root->val});
        ret++;
        while(!temp.empty()){
            int size = temp.size();

            for (int i = 0 ; i < size ; i++){
                pair<TreeNode*, int> top = temp.front();
                temp.pop();

                if (top.first->left){
                    int leftmax = max(top.first->left->val, top.second);
                    if (top.first->left->val >= leftmax)    ret++;
                    temp.push({top.first->left, leftmax});
                }if (top.first->right){
                    int rightmax = max(top.first->right->val, top.second);
                    if (top.first->right->val >= rightmax)    ret++;
                    temp.push({top.first->right, rightmax});
                }
            }
        }return ret;
    }
};
