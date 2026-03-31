/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public int GoodNodes(TreeNode root) {
        if (root == null)   return 0;
        int ret = 0;
        Dfs(root, root.val, ref ret);
        return ret;
    }

    public void Dfs(TreeNode root, int max, ref int ret){
        if (root == null)   return;

        if (root.val >= max) {
            ret++;
            max = root.val;
        }
        Dfs(root.left, max, ref ret);
        Dfs(root.right, max, ref ret);
    }
}
