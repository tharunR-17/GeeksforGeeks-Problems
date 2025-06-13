class Solution {
  public:
    
    int count(vector<int>& arr, int mid) {
        
        int count = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            count = count + (arr[i] / mid);
            
            if(arr[i] % mid > 0){
                count++;
            }
        }
        return count;
    }
    int kokoEat(vector<int>& arr, int k) {
        
        int right = *max_element(arr.begin(),arr.end());
        int left = 1;
        int ans = 0;
        
        while(left <= right){
            int mid = left + (right -left)/2;
            
            if(count(arr,mid) <= k){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

