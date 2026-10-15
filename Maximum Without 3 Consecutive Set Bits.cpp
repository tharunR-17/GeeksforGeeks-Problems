class Solution {
  public:
    int maxValue(int n) {
        // Abhi Code Karo
        int n1 = n;
        string s;
        while(n1) {
            s += (n1%2 + '0');
            n1 /= 2;
        }
        reverse(s.begin(), s.end());
        int i=0;
        while(i+2 < s.length()) {
            if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '1') {
                s[i+2] = '0';
                i += 3;
            }
            else {
                i++;
            }
        }
        
        int ans = 0;
        int bit = 0;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '1') {
                ans += pow(2, bit);
            }
            bit++;
        }
        return ans;
    }
};
