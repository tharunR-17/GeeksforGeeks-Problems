class Solution {
  public:
  vector<int>nge(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[n-1]=-1;
      stack<int>st;
      st.push(arr[n-1]);
      for(int i=n-2;i>=0;i--){
          while(!st.empty() && st.top()<=arr[i])st.pop();
          ans[i]=(st.empty()?-1:st.top());
          st.push(arr[i]);
      }
      return ans;
     
  }
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n=arr.size();
        arr.insert(arr.end(),arr.begin(),arr.end());
        vector<int>result=nge(2*n,arr);
        result.resize(n);
        return result;
    }
};

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n);
        stack<int> st;
        for (int i=2*n-1; i >= 0; i--) {
            int idx = (i-1+n)%n; // to go backward one step in a circular array.
            //int idx = (i+1)%n; // to go forward one step in a circular array.
            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }
            // Only set answer in the first pass (i < n)
            if (i < n) {
                ans[idx]=(st.empty()?-1:st.top());
            }
            // Push current element into the stack
            st.push(arr[idx]);
        }
        return ans;
    }
};
