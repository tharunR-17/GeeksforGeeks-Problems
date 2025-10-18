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
    private void inorder(Node root,List<Integer> list){
        if(root==null)return;
        
        inorder(root.left,list);
        list.add(root.data);
        inorder(root.right,list);
    }
    public int findMedian(Node root) {
        // Code here
        List<Integer> list=new ArrayList<>();
        inorder(root,list);
        
        int n=list.size();
        
        return n%2==0 ? list.get((n/2)-1) : list.get(((n+1)/2)-1); // doing -1 because of 0 based indexing
    }
}
