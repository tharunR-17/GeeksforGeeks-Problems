class Solution {
    public Node swapKth(Node head, int k) {
        // code here
        int size = 0;
        int idx =0;
        if(head == null || head.next == null){
            return head;
        }
        Node NxtNode = head;
        
        while(NxtNode != null){
            size++;
            NxtNode = NxtNode.next;
        }
        NxtNode = head;
        while(NxtNode != null){
            idx++;
            
             if(idx == k || idx == size-k+1){
                 int data1 = NxtNode.data;
                  Node lastNxt = NxtNode;
                  int condn = idx<k?k:size-k+1;
                 while(idx != condn){
                     idx++;
                    lastNxt = lastNxt.next;
                 }
                 int data2 = lastNxt.data;
                 
                 NxtNode.data = data2;
                 lastNxt.data = data1;
            }
            NxtNode = NxtNode.next;
        }
        
        return head;
        
    }
}
