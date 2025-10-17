/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
} */

class Solution {
    private static void getnodeValues(Node root,List<Integer> list){
        if(root==null)return;
        
        getnodeValues(root.left,list);
        list.add(root.data);
        getnodeValues(root.right,list);
    }
    private static void UpdateTree(Node root,Map<Integer,Integer> map){
        if(root==null)return;
        
        root.data=map.get(root.data); // updating the data to it's sum of all nodes greater than current node.
        UpdateTree(root.left,map);
        UpdateTree(root.right,map);
        
    }
    public static void transformTree(Node root) {
        // code here
        List<Integer> list=new ArrayList<>();
        getnodeValues(root,list);
        
        int n=list.size();
        int[] PrefixSum=new int[n];
        PrefixSum[0]=list.get(0);
        
        for(int i=1;i<n;i++){
            PrefixSum[i]=list.get(i)+PrefixSum[i-1];
        }
        
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<n;i++){
            int nodeVal=list.get(i);
            int sum=PrefixSum[n-1]-PrefixSum[i];
            map.put(nodeVal,sum);
        }
        
        UpdateTree(root,map);
    }
}
