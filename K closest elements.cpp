class compare {
public:
bool operator()(pair<int, int>& a, pair<int, int>& b){
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first; 
    }
};
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(int i=0;i<arr.size();i++){
            int a=abs(arr[i]-x);
            pq.push({a,arr[i]});
        }
        vector<int>ans;
        while(k>0){
            if(pq.top().first==0){
                pq.pop();
            }
            else{
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
            }
        }
        return ans;
    }
};
