class Solution {
    public int longestCycle(int v, int[][] mat) {
        // code here
        int n=mat.length,res=-1;
        HashMap<Integer,Integer> hm=new HashMap<>();
        for(int i=0;i<n;i++){
            hm.put(mat[i][0],mat[i][1]);
        }
        for(int i=0;i<v;i++){
            boolean vis[]=new boolean[v];
            int p=i,c=0;
            boolean de=false;
            while(vis[p]==false){
                vis[p]=true;c++;
                if(hm.containsKey(p))
                    p=hm.get(p);
                else{
                    de=true;
                    break;
                }
            }
            if(!de && p==i)
                res=Math.max(res,c);
        }
        return res;
    }
}
