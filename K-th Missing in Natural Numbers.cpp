class Solution {
	public:
	int findKthSmall(vector<int>& arr, int k) {
		// code here
		sort(arr.begin(), arr.end());
		for (const int&data:arr) {
			if (data <= k)k++;
		}
		return k;
	}
};
