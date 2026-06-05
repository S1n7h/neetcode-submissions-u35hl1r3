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
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        int idx_preorder = 0;
        return MakeTree(preorder, inorder, 0, preorder.Length - 1, ref idx_preorder);
    }

    TreeNode MakeTree(int[] preorder, int[] inorder, int l, int r, ref int idx_preorder){
        if (idx_preorder >= preorder.Length || l > r) return null;

        var node = new TreeNode();
        node.val = preorder[idx_preorder++];
        for(int i = l ; i <= r ; i++){
            if (inorder[i] == preorder[idx_preorder - 1]){
                node.left = MakeTree(preorder, inorder, l, i - 1, ref idx_preorder);
                node.right = MakeTree(preorder, inorder, i + 1, r, ref idx_preorder);
                break;
            }
        }return node;
    }
}
