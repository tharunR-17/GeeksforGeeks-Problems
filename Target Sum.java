class Solution {
    
    HashMap<String , Integer> dpMap;
    
    public int solve(int[] arr , int currSum , int i , int target , int n){
        if(i == n - 1){
            if(currSum + arr[i] == target || currSum - arr[i] == target){
                return 1;
            }
            return 0;
        }
        String key = i + " " + currSum;
        if(dpMap.containsKey(key)){
            return dpMap.get(key);
        }
        //contribute as a positive
        int way1 = solve(arr , currSum + arr[i] , i + 1 , target , n);
        //contribute as a negative
        int way2 = solve(arr , currSum - arr[i] , i + 1 , target , n);
        
        int ways = way1 + way2;
        
        dpMap.put(key , ways);
        
        return ways;
        
    }
    public int totalWays(int[] arr, int target) {
        // code here
        dpMap = new HashMap<>();
        int n = arr.length;
        return solve(arr , 0 , 0 , target , n);
    }
}
