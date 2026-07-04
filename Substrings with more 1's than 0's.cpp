class Solution {
public:
    long long ans = 0;

    void merge(vector<int>& a, int l, int mid, int r) {

 
        int i = l;
        for (int j = mid + 1; j <= r; j++) {
            while (i <= mid && a[i] < a[j])
                i++;

            ans += (i - l);
        }

     
        vector<int> temp;
        int left = l;
        int right = mid + 1;

        while (left <= mid && right <= r) {
            if (a[left] <= a[right])
                temp.push_back(a[left++]);
            else
                temp.push_back(a[right++]);
        }

        while (left <= mid)
            temp.push_back(a[left++]);

        while (right <= r)
            temp.push_back(a[right++]);

        for (int k = l; k <= r; k++)
            a[k] = temp[k - l];
    }

    void mergeSort(vector<int>& a, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }

    int countSubstring(string& s) {

        int n = s.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }

        ans = 0;
        mergeSort(prefix, 0, n);

        return ans;
    }
};

