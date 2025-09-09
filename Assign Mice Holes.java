class Solution {
    public int assignHole(int[] mices, int[] holes) {
        // code here
        Arrays.sort(mices);
        Arrays.sort(holes);
        int max=0;
        int sum=0;
        for(int i=0;i<mices.length;i++)
        {
            sum=Math.abs(mices[i] - holes[i]);
            max=Math.max(sum,max);
           
        }
        return max;
    }
}
