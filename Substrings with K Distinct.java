class Solution {
    private int atMostK(String s, int k){
        char[] str = s.toCharArray();
         int i =0; 
         int j =0;
        int[] hash = new int[26];
        int distinctCount=0;
        int ans = 0;
        
        while(j<str.length){
            
            hash[str[j]-'a']++;
            
            if(hash[str[j] - 'a'] == 1)distinctCount++; // seeing for the first time
            
           while(distinctCount > k){
               hash[str[i] - 'a']--;
               if(hash[str[i] - 'a'] == 0){
                 distinctCount--;
               }
               i++;
           }
           ans+=(j-i+1);
           j++;
        }
        return ans;
        
    }
    public int countSubstr(String s, int k) {
          return atMostK(s,k) -atMostK(s,k-1);
    }
}
