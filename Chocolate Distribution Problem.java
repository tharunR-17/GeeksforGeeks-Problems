import java.util.*;
class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        Collections.sort(arr);
        int l=0;
        int result =Integer.MAX_VALUE;
        for(int r=0; r<arr.size(); r++)
        {
            if(r-l == m)
            {
                l++;
            }
            if(r-l+1 == m)
            {
                result = Math.min(result, arr.get(r) - arr.get(l));
            }
        }
        return result;
    }
}
