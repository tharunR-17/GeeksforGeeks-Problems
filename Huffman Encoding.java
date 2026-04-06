class Solution {

  class Node{

      int freq;

      int minIdx;

      Node left,right;

      Node(int freq,int minIdx){

          this.freq=freq;

          this.minIdx=minIdx;

          this.left=left;

          this.right=right;

      }

  }

  public ArrayList<String> huffmanCodes(String s, int f[]) {

        PriorityQueue<Node>pq=new PriorityQueue<>((a,b)->a.freq!=b.

        freq?a.freq-b.freq:a.minIdx-b.minIdx);

        for(int i=0;i<s.length();i++){

            pq.offer(new Node(f[i],i));

        }

      if(pq.size()==1)

      return new ArrayList<String>(Arrays.asList("0"));

      while(pq.size()>1){

          Node left=pq.poll();

          Node right=pq.poll();

          Node parent=new Node(left.freq+right.freq,Math.min(left.minIdx,right.minIdx));

          parent.left=left;

          parent.right=right;

          pq.add(parent);

          

      }

      ArrayList<String>ans=new ArrayList<>();

      inorder(pq.poll(),"",ans);

      return ans;

      

    }

    void inorder(Node node,String code,ArrayList<String>ans){

        if(node==null)return;

        if(node.left==null&&node.right==null){

        ans.add(code);

        return;

        }

    inorder(node.left,code+'0',ans);

    inorder(node.right,code+'1',ans);

    }

}
