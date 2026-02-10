class Solution {
    public boolean check(int arr[], int mid, int k)
    {
        int temp=0;
        for(int i=0; i<arr.length; i++)
        {
            int a = arr[i]/mid;
            if(arr[i]%mid != 0)
            {
                a++;
            }
            temp = temp + a;
        }
        if(temp <= k)
        {
            return true;
        }
        return false;
    }
    public int kokoEat(int[] arr, int k) 
    {
        int l=1;
        int r= 1000000;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            boolean res = check(arr, mid, k);
            if(res == false)
            {
                l =mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
}
