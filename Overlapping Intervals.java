class Solution {
    public ArrayList<int[]> mergeOverlap(int[][] arr) {
        // Code here
    //sort the array based on the first indexes
    Arrays.sort(arr,(a,b)->a[0]-b[0]);
    
    ArrayList<int[]> answer = new ArrayList<>();
    if(arr.length==0)
    return answer;
    
    int[]firstElement = new int[2];
    firstElement[0]=arr[0][0];
    firstElement[1]=arr[0][1];
    int length=0;
    answer.add(firstElement);
   
    int i=1;
    while(i<arr.length)
    {
        int []temp=answer.get(length);
      if(temp[1]>=arr[i][0])
      {
          int max=Math.max(temp[1],arr[i][1]);
          int[]newElement =  new int[2];
          newElement[0]=temp[0];
          newElement[1]=max;
          answer.set(length,newElement);
          
      }
      else{
         int[]newElement =  new int[2];
          newElement[0]=arr[i][0];
          newElement[1]=arr[i][1]; 
          answer.add(newElement);
          length++;
      }
     i++;   
    }
    
    return answer;
    }
}
