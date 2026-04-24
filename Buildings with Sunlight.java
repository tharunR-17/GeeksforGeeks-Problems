class Solution {
    public int visibleBuildings(int arr[]) {
        int build=0, ptr=arr[0];
        
        for(int i=0;i<arr.length;i++){
            if(arr[i]>=ptr){
                build++;
                ptr= arr[i];
            }
        }
        
        return build;
    }
}
