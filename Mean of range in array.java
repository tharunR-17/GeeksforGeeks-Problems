class Solution {
    public ArrayList<Integer> findMean(int[] arr, int[][] queries) {
        
        // better approach (using prefix sum)
        ArrayList<Integer> res = new ArrayList<>();
        int sum[] = new int[arr.length];
        sum[0] = arr[0];
        
        for (int i=1; i<arr.length; i++){
            sum[i] = sum[i-1] + arr[i];
        }
        
        for (int i=0; i<queries.length; i++){
                
            int l = queries[i][0];  //left 
            int r = queries[i][1];  //right
            
            int total = sum[r] - (l>0 ? sum[l-1] : 0);
            int count = (r+1)-l;
            res.add(total / count);
        }
        return res;
        
        
        
        // Traditional Approach---------------------------------
        // ArrayList<Integer> res = new ArrayList<>();
        // for (int i=0; i<queries.length; i++){
        //     int sum = 0, count = 0;
        //     for (int k=queries[i][0]; k<=queries[i][1]; k++){
        //         sum += arr[k];
        //         count++;
        //     }
        //     res.add(sum/count);
        // }
        // return res;       
    }
}

