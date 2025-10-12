/*
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    class Node2{
        int sum, nodes;
        
        Node2(int sum, int nodes){
            this.sum = sum;
            this.nodes = nodes;
        }
    }
    int count;
    public int distCandy(Node root) {
        // code here
        count = 0;
        countMoves(root);
        return count;
    }
    public Node2 countMoves(Node root){
        if(root == null) return new Node2(0,0);
        
        Node2 left = countMoves(root.left);
        Node2 right = countMoves(root.right);
        
        int sum = left.sum+right.sum+root.data;
        int nodes = left.nodes+right.nodes+1;
        count += (Math.abs(sum - nodes));
        
        return new Node2(sum,nodes);
    }
}
