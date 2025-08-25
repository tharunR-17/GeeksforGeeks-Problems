import java.util.*;


class Solution {
    public int maximizeMedian(int[] arr, int k) {
        // code here
        
        Arrays.sort(arr);
        int n = arr.length;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        int low = 0 , high = n-1;
        
        int mid = (low + high)/2;
        
        for(int i = mid ; i<n ;i++)
        {
            pq.add(arr[i]);
        }
        
        for(int i = 0 ; i<k ;i++)
        {
            pq.add(pq.poll() + 1);
        }
        
        if(n %2 !=0)
        {
            return pq.peek();
        }
        else
        {
            return (pq.poll() + pq.peek())/2;
        }
        
        
    }
}

