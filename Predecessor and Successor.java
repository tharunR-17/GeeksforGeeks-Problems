/*
class Node {
    int data;
    Node left, right;
    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/

class Solution {
    public ArrayList<Node> findPreSuc(Node root, int k) {
        
        ArrayList<Node> res = new ArrayList<Node>();
        
        res.add(null); // predecessor
        res.add(null); // successor
        
        Node node = root;
        while(node != null) {
            
            if(node.data < k) {
                res.set(0, node); // possible predecessor
                node = node.right;
            } 
            else if(node.data > k) {
                res.set(1, node); // possible successor
                node = node.left;
            }
            else {
                // predecessor (max in left subtree)
                Node temp = node.left;
                while(temp != null && temp.right != null) {
                    temp = temp.right;
                }
                if(temp != null) res.set(0, temp);
                
                // successor (min in right subtree)
                temp = node.right;
                while(temp != null && temp.left != null) {
                    temp = temp.left;
                }
                if(temp != null) res.set(1, temp);
                
                break;
            }
        }
        return res;
    }
}
