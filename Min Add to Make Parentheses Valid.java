class Solution {
    public int minParentheses(String s) {
        // code here
        // just pop only when we already have opening bracket and now encounter a closing one
        // otherwise just push in the stack
        Stack<Character> st = new Stack<>();
        for(char c : s.toCharArray()){
            if(!st.isEmpty() && st.peek() == '(' && c ==')'){
                st.pop();
            }
            else st.push(c);
        }
        return st.size();
    }
}
