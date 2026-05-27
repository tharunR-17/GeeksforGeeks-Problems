class Solution {
  public:
    
    bool wifiRange(string s, int x) {
        
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for(int i = 0; i < n; i++) {

            if(s[i] == '1') {

                int l = max(0, i - x);
                int r = min(n - 1, i + x);

                diff[l]++;

                if(r + 1 < n)
                    diff[r + 1]--;
            }
        }

        int cover = 0;

        for(int i = 0; i < n; i++) {

            cover += diff[i];

            if(cover <= 0)
                return false;
        }

        return true;
    }
};
