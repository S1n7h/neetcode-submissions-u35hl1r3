/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
*/

public class Solution {
    public Node Connect(Node root) {
        if (root == null)   return root;
        Node NextConnectRoot = null;
        Node LeftNode = null;
        Node temp = root;

        //finding the leftmost node at any level
        while (LeftNode == null && temp != null){
            if (temp.left != null)  {
                LeftNode = temp.left;
            }else if (temp.right != null) {
                LeftNode = temp.right;
            }temp = temp.next;
        }NextConnectRoot = LeftNode;

        temp = root;

        while(temp != null){
            if (temp.left != null && temp.left != LeftNode){
                LeftNode.next = temp.left;
                LeftNode = temp.left;
            }
            if (temp.right != null && temp.right != LeftNode){
                LeftNode.next = temp.right;
                LeftNode = temp.right;
            }temp = temp.next;
        }Connect(NextConnectRoot);

        return root;
    }
}