class Solution {
public:
    string longestString(vector<string> &arr) {
        unordered_set<string> st(arr.begin(), arr.end());
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            if (a.length() != b.length())
                return a.length() > b.length();
            return a < b;
        });

        for (string &s : arr) {
            bool allPrefix = true;
            for (int i = 1; i <= s.length(); ++i) {
                if (st.find(s.substr(0, i)) == st.end()) {
                    allPrefix = false;
                    break;
                }
            }
            if (allPrefix)
                return s;
        }

        return "";
    }
};

