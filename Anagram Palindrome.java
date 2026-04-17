class Solution {
    boolean canFormPalindrome(String s) {
        // code here
        int count=0;
        int temp=0;
        if(s.length()%2==1){
             count=1;
        }

        int ans[]= new int[26];
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            ans[ch-'a']++;
        }
        for(int i=0;i<25;i++){
            if(ans[i]%2!=0){
                temp++;
            }
        }
        if(temp>count){
            return false;
        }
        return true;
    }
}
