class Solution {
  public:
    int longestKSubstr(string &s, int k) 
    {
        int n = s.size() , i = 0 , j = 0 , cnt = 0 , ans = -1;
        int freq[26] = {0};
        while(j < n)
        {
            if(freq[s[j++] - 'a']++ == 0)
                cnt++;
            while(cnt > k)
                if(--freq[s[i++] - 'a'] == 0)
                    cnt--;
            if(cnt == k)
                ans = max(ans , j - i);
        }
        return ans;
    }
};
