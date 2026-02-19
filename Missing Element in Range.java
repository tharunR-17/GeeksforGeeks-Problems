class Solution {
    public ArrayList<Integer> missingRange(int[] arr, int low, int high) {
        // code here
        ArrayList<Integer> al=new ArrayList<Integer>();
        HashSet<Integer> set=new HashSet<Integer>();
        for(int i=low;i<=high;i++){
            set.add(i);
        }
        for (int num:arr){
          set.remove(Integer.valueOf(num));
        }
        al.addAll(set);
        Collections.sort(al);
        return al;
    }
}
