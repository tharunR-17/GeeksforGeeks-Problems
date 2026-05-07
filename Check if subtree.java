/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/
class Solution {
    
    public void preOrder(Node root, ArrayList<String> list){
        
        if(root == null){
            list.add("#");
            return;
        }
        
        list.add(String.valueOf(root.data));
        preOrder(root.left, list);
        preOrder(root.right, list);
        
    }
    
    public boolean isSubTree(Node root1, Node root2) {
        // code here
        
        if(root1 == null || root2 == null) return true;
        if(root1 == null && root2 != null) return false;
        
        ArrayList<String> l1 = new ArrayList<>();
        ArrayList<String> l2 = new ArrayList<>();
        
        preOrder(root1, l1);
        preOrder(root2, l2);
        
        return Collections.indexOfSubList(l1, l2) != -1;
        
    }
}

