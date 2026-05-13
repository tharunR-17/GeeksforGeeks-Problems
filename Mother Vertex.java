class Solution {
    static int c=0;
    public int findMotherVertex(int V, int[][] edges) {
        // code here
        boolean vis[]=new boolean[V];
        ArrayList<ArrayList<Integer>> adj=new ArrayList<>();
        
        for(int i=0;i<V;i++)
        {
            adj.add(new ArrayList<>());
        }
        
        for(int i[]:edges)
        {
            adj.get(i[0]).add(i[1]);
        }
        
        for(int i=0;i<V;i++)
        {
            
             
             HashSet<Integer> set=new HashSet<>();
             
             dfs(adj,i,vis,set);
                
              if(set.size()==V)
              return i;
              
            
        }
        
        return -1;
        
    }
    void dfs(ArrayList<ArrayList<Integer>> adj,int node,boolean vis[],HashSet<Integer> set)
    {
        // vis[node]=true;
        
        set.add(node);
        c++;
        
        for(int i:adj.get(node))
        {
            if(!set.contains(i))
            {
                dfs(adj,i,vis,set);
            }
        }
    }
}
