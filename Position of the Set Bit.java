class Solution {
    public int findPosition(int n) {
        String s="";
        int c=0, pos=0;
        
        while(n>0 && c<2){
            if(n%2==0){
                s+="0";//s="0"+s;
            }
            else{
                s+="1";//s="1"+s;
                c++;
            }
            n=n/2;
        }
        
        return (c==1)?(s.indexOf('1')+1):-1;
    }
}
