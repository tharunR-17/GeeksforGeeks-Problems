class Solution {
    public int longestSubarray(int[] arr, int k) {
        // Code Here
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0,-1);
        int diff = 0;
        int gt = 0;
        int lt = 0;
        int maxLen = 0;
        for(int i = 0;i < arr.length;i++){
            if(arr[i] > k) gt++;
            else lt++;
            diff = gt - lt;
            int res = diff - 1;
            if(map.containsKey(res)){
                maxLen = Math.max(maxLen, i-map.get(res));
            }
            if(!map.containsKey(diff)){
                map.put(diff, i);
            }
            
        }
        // edge case where entire array could be a possible subarray
        if((gt-lt) > 1) return arr.length;
        return maxLen;
    }
}

