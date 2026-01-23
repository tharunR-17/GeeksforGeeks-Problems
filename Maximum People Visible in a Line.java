class Solution {
    public int maxPeople(int[] arr) {
        // code here
        int max = arr[0];
        int n = arr.length;
        for(int num:arr)max = Math.max(max,num);
        int prev = -1;
        int cur = -1;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(cur==-1 && arr[i]==max){
                cur=i;
            }else if(arr[i]==max){
                ans = Math.max(ans,((cur-prev)+(i-cur))-1);
                prev=cur;
                cur=i;
            }
        }
        ans = Math.max(ans,((cur-prev)+(n-cur))-1);
        return ans;
    }
}
