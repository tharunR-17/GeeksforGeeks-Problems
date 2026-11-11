class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        
        int mx = *max_element(arr.begin() , arr.end()) ;
        vector<pair<int, vector<int>>> p;
        vector<int> freq(mx+1,0) ;
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(freq[arr[i]] == 0){
                p.push_back({arr[i], {i}});
            }
            else{
                for(int j = 0; j < p.size(); j++) {
                    if(p[j].first == arr[i]) {
                        p[j].second.push_back(i);
                        break;
                    }
                }
            }
            freq[arr[i]]++ ;
            
        }
        
        for(int i = 0; i < p.size(); i++){
            if(p[i].second.size() >= 2) {
                for(int j = 1; j < p[i].second.size(); j++){
                    if(p[i].second[j] - p[i].second[j-1] <= k)
                        return true;
                }
            }
        }
        return false;
    }
};
