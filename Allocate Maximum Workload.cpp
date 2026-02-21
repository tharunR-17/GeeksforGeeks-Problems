#include <bits/stdc++.h>
using namespace std;

bool canAllocate(const vector<int>& tasks, int W, long long maxLoad) {
    long long currentLoad = 0;
    int workersUsed = 1;

    for (int t : tasks) {
        if (t > maxLoad) return false;

        if (currentLoad + t <= maxLoad) {
            currentLoad += t;
        } else {
            workersUsed++;
            currentLoad = t;

            if (workersUsed > W) return false;
        }
    }

    return workersUsed <= W;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> tasks(N);
    long long sum = 0, mx = 0;

    for (int i = 0; i < N; i++) {
        cin >> tasks[i];
        sum += tasks[i];
        mx = max(mx, (long long)tasks[i]);
    }

    int W;
    cin >> W;

    // ✅ IMPORTANT FIX
    if (W > N) {
        cout << -1 << "\n";
        return 0;
    }

    long long left = mx;
    long long right = sum;
    long long answer = sum;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canAllocate(tasks, W, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
