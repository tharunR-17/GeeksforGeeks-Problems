class Solution 
{
    private boolean check_d(int n, int d)
    {
        //this function will check if n - sumOfDigits(n) >=d
        
        int a=n, sum=0;
        while(a>0)
        {
            sum+= a%10;
            a=a/10;
        }
        
        return (n-sum)>=d;
    }
    public int getCount(int n, int d) 
    {
        // code here
        int low=1, high=n, limit=0;;
        //limit is the minimum element for which the condition is being satisfied. once min is found then we can conclude that all the elements greater than limit will def satisfy the condition.
        while(low<=high)
        {
            int mid= (low+high)/2;
            if(check_d(mid,d)) //we will find the most minimum value for which the condition of n-sumdig>=d is true
            {
                limit=mid;
                high=mid-1; //if one element from 1 to n is found, I want to get the minimum elements for which the statement is true.
            }
            else
                low=mid+1; // there was no element that satisfied the condition, so we will check for higher numbers than the current.
        }
        
        if(limit!=0)
            return n-limit+1; // the ans will be the count from minimum element found till n
        return 0;
    }
}
