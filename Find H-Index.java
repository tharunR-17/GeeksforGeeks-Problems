class Solution {
    public int hIndex(int[] nums) {
        // code here
        int n = nums.length;
        int max = nums[0];
        for(int i=0;i<n;i++) max = Math.max(nums[i],max);
        
        int [] pref = new int[max+1];
        
        for(int i=0;i<n;i++){
            pref[nums[i]]++;
        }
        
        for(int i=max-1;i>=0;i--){
            pref[i]+=pref[i+1];
        }
        
        for(int i=max;i>=0;i--){
            if(pref[i]>=i) return i;
        }
        return 0;
    }
}
