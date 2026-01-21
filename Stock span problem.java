class Solution {
    public int[] getNextHigherElement(int[] a,int n){
        int[] nse = new int[n];
        var s = new Stack<Integer>();
        for(int i = n-1;i >= 0; --i){
            while(!s.isEmpty() && a[s.peek()] < a[i]) s.pop();
            nse[i] = !s.isEmpty() ? s.peek() : -1;
            s.push(i);
        }
        return nse;
    }
    public ArrayList<Integer> calculateSpan(int[] a) {
        int n = a.length;
        int[] nse = getNextHigherElement(a,n);
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n,1));
        for(int i = 0; i < n; ++i){
            // System.out.print(nse[i] + " ");
            if(nse[i] != -1)
                ans.set(nse[i],ans.get(i)+ans.get(nse[i]));
        }
        return ans;
    }
}
