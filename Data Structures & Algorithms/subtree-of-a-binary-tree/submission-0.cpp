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
    bool equal(TreeNode* root, TreeNode* subRoot){
        if (!root && !subRoot)  return true;
        if (!root || !subRoot)  return false;
        if (root->val != subRoot->val)  return false;

        return (equal(root->left, subRoot->left) && equal(root->right, subRoot->right));    
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();
            for (int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();
                q.pop();

                if (temp->val == subRoot->val) 
                if (equal(temp, subRoot))  return true;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);            
            }
        }return false;
    }
};
