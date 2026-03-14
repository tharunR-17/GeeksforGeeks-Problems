/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}
*/
class Pair{
     Node node;
     int col;
     Pair(Node n, int c){
         node=n;
         col=c;
     }
}
class Solution {
    public ArrayList<Integer> topView(Node root) {
        
        
        TreeMap<Integer,Integer>mp=new TreeMap<>(); 
        Queue<Pair>q=new LinkedList<>();
        q.add(new Pair(root,0));
        
        while(q.size()>0){
              
              Pair p=q.peek();
              q.poll();
              
              if(!mp.containsKey(p.col)){
                  mp.put(p.col,p.node.data);
              }
              
              if(p.node.left!=null){
                  q.add(new Pair(p.node.left,p.col-1));
              }
              if(p.node.right!=null){
                  q.add(new Pair(p.node.right,p.col+1));
              }
        }
        
        ArrayList<Integer>list=new ArrayList<>();
        for(Integer e:mp.keySet()){
             list.add(mp.get(e));
        }
        
        return list;
        
    }
}

