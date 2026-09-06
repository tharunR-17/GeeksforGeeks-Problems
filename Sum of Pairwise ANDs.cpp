class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        long long ans = 0;


        for (int i = 0; i < 31; ++i) {

            long long set_bits = 0;

            for (int x : arr) {

                if ((x & (1LL << i)) != 0) {
                    set_bits++;
                }
            }

            long long pairs = set_bits * (set_bits - 1) / 2;
            long long num =  (1LL << i);

            ans += (pairs * num);
        }

        return ans;
    }
};
