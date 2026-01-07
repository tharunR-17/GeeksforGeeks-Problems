class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        // code here
        ArrayList<Integer> res=new ArrayList<>();
        HashMap<Integer,Integer> map=new HashMap<>();
        
        for(int i=0;i<k;i++){
            map.put(arr[i],map.getOrDefault(arr[i], 0)+1);
        }
        res.add(map.size());
        int left=0;
        for(int i=k;i<arr.length;i++){
            map.put(arr[left],map.get(arr[left])-1);
            if(map.get(arr[left])==0)map.remove(arr[left]);
            left++;
            map.put(arr[i],map.getOrDefault(arr[i],0)+1);
            res.add(map.size());
        }
        return res;
    }
}
