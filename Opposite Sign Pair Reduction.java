class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        // code here
        Stack<Integer> stack=new Stack<>();
        for(int num:arr){
            boolean destroyed=false;
            while(!stack.isEmpty() && ((stack.peek()>0 && num<0) || (stack.peek()<0 && num>0))){
                if(Math.abs(stack.peek())<Math.abs(num)){
                    stack.pop();
                }else if(Math.abs(stack.peek())==Math.abs(num)){
                    stack.pop();
                    destroyed=true;
                    break;
                }else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                stack.push(num);
            }
        }
        return new ArrayList<>(stack);
    }
}
