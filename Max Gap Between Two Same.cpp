class Solution {
public:
    int maxCharGap(string &s) {
        int count[26] = {0};
        int count1[26] = {0};
        int maxi = INT_MIN;
        for(int i = 0;i<s.length();i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a'] == 1){
                count1[s[i]-'a'] = i;
            }
            else{
                maxi = max(maxi,i-count1[s[i]-'a']-1);
            }
        }
        if(maxi == INT_MIN){
            return -1;
        }
        return maxi;
    }
};
