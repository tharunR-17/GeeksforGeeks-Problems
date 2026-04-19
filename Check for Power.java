class Solution {
    public boolean isPower(int x, int y) {
        // code here
        if(x == 1) return y ==1;
        if(x == 0) return y == 0;
        while(y%x == 0){
            y = y/x;
        }
        return y == 1;
    }
}
