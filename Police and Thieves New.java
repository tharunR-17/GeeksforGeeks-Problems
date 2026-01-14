class Solution {
    public int catchThieves(char[] arr, int k) {
        // code here
     ArrayList<Integer> l1=new ArrayList<>();
     ArrayList<Integer> l2=new ArrayList<>();
    
    
    for(int i=0;i<arr.length;i++){
        if(arr[i]=='P'){
            l1.add(i);
        }else{
        
            l2.add(i);
        }
    }
    int i=0,j=0,count=0;
    while(i<l1.size() && j<l2.size()){
       if (Math.abs(l1.get(i) - l2.get(j)) <= k) {
            count++;
            i++;
            j++;
        }else if(l2.get(j)<l1.get(i)){
            j++;
        }else{
            i++;
        }
    }
    return count;
     }
}
