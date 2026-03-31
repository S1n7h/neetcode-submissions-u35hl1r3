class Solution {
private:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;   // both null → same
        if (!p || !q) return false;  // one null, one not → different
        if (p->val != q->val) return false;

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};
