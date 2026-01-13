class Solution {
    public boolean canServe(int[] arr) {
        // code here
        int costOfTicket = 5;
        int[] freq = new int[5];
        
        for(int amount : arr){
            if(amount == costOfTicket){
                
            }else{
                int remainingAmount = amount - costOfTicket;
                if(remainingAmount == 15){
                    if(freq[2] >= 1 && freq[1] >= 1) {
                        freq[2]-=1;
                        freq[1]-=1;
                    }else if(freq[1] >= 3){
                        freq[1] -= 3;
                    }else{
                        return false;
                    }
                }else{
                    if(freq[1] >= 1){
                        freq[1] -= 1;
                    }else{
                        return false;
                    }
                }
            }
            
            freq[amount/costOfTicket]+=1;
        }
        
        return true;
    }
}
