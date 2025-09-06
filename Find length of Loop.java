/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    public int lengthOfLoop(Node head) {
        // code here
        if(head == null){
            return 0;
        }
        Node cur = head;
        while(cur != null){
            if(cur.data == -1 ){
                break;
            }
            cur.data = -1;
            cur = cur.next;
        }
        if(cur == null){
            return  0;
        }
        int len = 0;
        while(cur.data != -2){
            len++;
            cur.data = -2;
            cur = cur.next;
        }
        return len;
    }
}
