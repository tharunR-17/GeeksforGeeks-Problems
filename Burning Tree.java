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
    public int minTime(Node root, int target) {
        // code here
        if(root==null)
        return 0;
        
        Map<Integer,List<Integer>> graph = new HashMap<>();
        buildGraph(root,null,graph);
        
        int time=0;
        Queue<Integer>q= new LinkedList<>();
        Set<Integer>visited= new HashSet<>();
        q.add(target);
        visited.add(target);
        
        while(!q.isEmpty())
        {
            boolean burned=false;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                
                for(int neighbour:graph.get(q.poll()))
                {
                    if(!visited.contains(neighbour))
                    {
                       visited.add(neighbour);
                       q.add(neighbour);
                       burned=true;
                    }
                }
            }
            if(burned)
            time++;
        }
        
       return  time; 
    }
    
    public void buildGraph(Node root,Node parent,Map<Integer,List<Integer>>graph)
    {
        if(root==null)
        return;
        
        if(!graph.containsKey(root.data))
        {
            graph.put(root.data,new ArrayList<>());
        }
        if(parent!=null)
        {
              graph.get(root.data).add(parent.data);
            graph.get(parent.data).add(root.data);
        }
        
        buildGraph(root.left,root,graph);
        buildGraph(root.right,root,graph);
    }
}

