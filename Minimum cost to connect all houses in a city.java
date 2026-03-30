class Solution {

 

    public int minCost(int[][] houses) {

        int n=houses.length;

        PriorityQueue<int[]>pq=new PriorityQueue<>((a,b)->a[0]-b[0]);

        boolean[]vis=new boolean[n];

        pq.offer(new int[]{0,0});

        int sum=0;

        while(!pq.isEmpty()){

            int[]cur=pq.poll();

            int wt=cur[0],idx=cur[1];

            if(vis[idx])continue;

            vis[idx]=true;

            sum+=wt;

         for(int i=0;i<n;i++){

             if(!vis[i]){

         int newWt=Math.abs(houses[idx][0]-houses[i][0])+Math.abs(houses[idx][1]-houses[i][1]);

         

                pq.offer(new int[]{newWt,i});

             }

         }

        }

        return sum;

        }

}
