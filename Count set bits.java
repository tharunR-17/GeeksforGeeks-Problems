class Solution{ 
    private static int findx(int n){
        int x=0;
        while((1<<x)<=n)x++;
        return x-1;
    }
    public static int countSetBits(int n){
        if(n==0)return 0;
        int x=findx(n);
        int bitstill2x=x*(1<<(x-1));
        int msb=n-(1<<x)+1;
        int rest=n-(1<<x);
        int ans=bitstill2x+msb+countSetBits(rest);
        return ans;
    }
}
