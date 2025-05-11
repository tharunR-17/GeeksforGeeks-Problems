from typing import List


class Solution:
    def kthLargest(self, arr, k) -> int:
        # code her
        sm=[]
        for i in range(len(arr)):
            curr=0
            for j in range(i,len(arr)):
                curr+=arr[j]
                sm.append(curr)
        sm.sort(reverse=True)
        return sm[k-1]
