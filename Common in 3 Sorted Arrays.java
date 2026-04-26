class Solution {
    public ArrayList<Integer> commonElements(int[] a, int[] b, int[] c) {
        // code here
        Set<Integer> s1=new HashSet<>();
        Set<Integer> s2=new HashSet<>();
        Set<Integer> s3=new HashSet<>();
        
        for(int i:a){
            s1.add(i);
        }
        
        for(int i : b){
           s2.add(i);
        }
        
        for(int i : c){
            if(s1.contains(i) && s2.contains(i)){
               s3.add(i);  
            }
        }
        
        ArrayList<Integer> arr = new ArrayList<>(s3);
        Collections.sort(arr);
        return arr;
    }
}
