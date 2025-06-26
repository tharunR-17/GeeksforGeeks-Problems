class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char, int> mp;
        for(int i =0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<int> maxh;
        for(auto it: mp)
        {
            maxh.push(it.second);
        }
        
        while(k-- && !maxh.empty())
        {
            int top = maxh.top();
            maxh.pop();
            top--;
            maxh.push(top);
        }
        int sum =0;
        while(!maxh.empty())
        {
            sum+=maxh.top() * maxh.top();
            maxh.pop();
        }
        
        return sum;
    }
};
