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
    Node mergeKLists(Node[] arr) {
        // code here
        ArrayList<Integer> a = new ArrayList<>();
        for(int i = 0; i < arr.length; i++)
        {
            Node curr = arr[i];
            while(curr != null)
            {
                a.add(curr.data);
                curr = curr.next;
            }
        }
        Collections.sort(a);
        Node ans = new Node(a.get(0));
        Node curr = ans;
        for(int i = 1; i < a.size(); i++)
        {
            curr.next = new Node(a.get(i));
            curr = curr.next;
        }
        return ans;
    }
}
