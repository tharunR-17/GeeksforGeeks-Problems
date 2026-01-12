class Solution {
    maxOfSubarrays(arr, k) {
        const n = arr.length;
        const result = [];
        const deque = []; // stores indices

        for (let i = 0; i < n; i++) {
            // Remove elements outside the current window
            if (deque.length && deque[0] <= i - k) {
                deque.shift();
            }

            // Remove smaller elements from the back
            while (deque.length && arr[deque[deque.length - 1]] <= arr[i]) {
                deque.pop();
            }

            // Add current index
            deque.push(i);

            // Window formed
            if (i >= k - 1) {
                result.push(arr[deque[0]]);
            }
        }

        return result;
    }
}
