class Solution {
  public:
    string minSum(vector<int> &arr) {
       priority_queue<int, vector<int>, greater<int>> pq;
       string first = "";
       string second = "";
       bool isFirst = true;
       for(auto &e : arr){
          pq.push(e);
       }
        
        isFirst = true;
        while(pq.empty() == false) {
            int tp = pq.top();
            pq.pop();
            if(isFirst){
                isFirst = false;
                first += to_string(tp);
            }
            else{
                second += to_string(tp);
                isFirst = true;
            }
        }
        return addString(first, second);
    }
    
    string addString(string &first, string &second){
        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());
        int carry = 0;
        int i = 0;
        int j = 0;
        string ans = "";
        while(i < first.length() || j < second.length()){
            int val1 = i >= first.length() ? 0 : first[i] - '0';
            int val2 = j >= second.length() ? 0 : second[j] - '0';
            int sum = ( val1 + val2 + carry ) % 10;
            carry = ( val1 + val2 + carry ) / 10;
            ans += to_string(sum);
            i++;
            j++;
        }
        if(carry){
            ans += to_string(carry);
        }
        i = ans.length() - 1;
        while(i >= 0 && ans[i] == '0'){
            i--;
        }
        ans = ans.substr(0, i + 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
