class Solution {
   public boolean stringStack(String pat, String tar) {
        // code here
       int i = pat.length() - 1;
        int j = tar.length() - 1;
        int skip = 0;  

        while (i >= 0) {
            char c = pat.charAt(i);

            if (skip > 0) {
                
                skip--;
            } else if (j >= 0 && c == tar.charAt(j)) {
               
                j--;
            } else {
               
                skip++;
            }
            i--;
        }

        return j < 0; 
    }

}

