/*
Definition for Node
class Node
{
    int data;
    Node left;
    Node right;

    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}
*/
class Solution {
    int count=0;
    public int getSize(Node root) {
        // code here
        if(root==null) return count;
        getSize(root.left);
        count++;
        getSize(root.right);
        return count;
    }
}
