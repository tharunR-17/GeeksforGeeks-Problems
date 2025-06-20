class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        //saransh naole
        int n = arr.size();
        if(n % k != 0) return false;
        
        unordered_map<int, int>mpp;
        for(int i = 0; i < n; i++){
            mpp[arr[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto &it : mpp){
            int value = it.first;
            int freq = it.second;
            pq.push({value, freq});
        }
        while(!pq.empty()){
            vector<pair<int, int>>temp;
            int prev = 0;
            for(int i = 0; i < k; i++){
                auto it  = pq.top();
                int num = it.first;
                int freq = it.second;
                freq--;
                pq.pop();
                
                if(i != 0 && (prev - num) != 1) return false;
                prev = num;
                if(freq != 0){
                    temp.push_back({num , freq});
                }
            }
            for(int i = 0; i< temp.size(); i++){
                pq.push(temp[i]);
            }
        }
        
        return true;
    
        
    }
};
