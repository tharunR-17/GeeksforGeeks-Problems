/*
class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
*/
class Solution {
    public static Node merge(Node a, Node b){
        if(a == null){
            return b;
        }
        if(b == null){
            return a;
        }
        
        Node result;
        
        if(a.data<b.data){
            result = a;
            result.bottom = merge(a.bottom, b);
        }else{
            result = b;
            result.bottom = merge(a, b.bottom);
        }
        
        return result;
    }
    
    public Node flatten(Node root) {
        // code here
        if(root == null || root.next == null){
            return root;
        }
        
        root.next = flatten(root.next);
        
        root = merge(root, root.next);
        return root;
    }
}

