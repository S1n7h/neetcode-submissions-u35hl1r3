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
    public List<int> RightSideView(TreeNode root) {
        if (root == null)  return new List<int>();

        var ret = new List<int>();
        var q = new Queue<TreeNode>();
    
        q.Enqueue(root);

        while(q.Count != 0){
            int Size = q.Count;

            for (int i = 0 ; i < Size ; i++){
                TreeNode top = q.Dequeue();

                if (top.left != null)   q.Enqueue(top.left);
                if (top.right != null)  q.Enqueue(top.right);

                if (i == Size - 1)  ret.Add(top.val);
            }
        }return ret;
    }
}
