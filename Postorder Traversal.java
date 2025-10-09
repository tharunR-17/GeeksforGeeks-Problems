/*
class Node {
    int data;
    Node left, right;
    Node(int val){
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    public ArrayList<Integer> postOrder(Node root) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        
        postOrder2(root,list);
        
        return list;
    }
    private void postOrder2(Node root, ArrayList<Integer> list){
        if(root == null) return;
        
        postOrder2(root.left,list);
        postOrder2(root.right,list);
        
        list.add(root.data);
    }
}
