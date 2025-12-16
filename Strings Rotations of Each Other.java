class Solution {
    public boolean areRotations(String s1, String s2) {
        // code here
        String s3 = s1+s1;
        int i=0; 
        int j=0;
        while(i<s3.length() && j<s2.length()){
            if(s3.charAt(i)==s2.charAt(j)){
                i++;
                j++;
                if(s2.length()==j){
                    return true;
                }
            }else{
                i++;
                
            }
        }
        return false;
    }
}
