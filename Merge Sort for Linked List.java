/*
class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}
*/

class Solution {
    public Node mergeSort(Node head) {
        // code here
        ArrayList<Integer>al=new ArrayList<>();
        Node temp=head;
        while(temp!=null){
            al.add(temp.data);
            temp=temp.next;
        }
        int m=0;
        int n=al.size()-1;
        Quicksort(m,n,al);
        Node wq=new Node(-1);
        Node rt=wq;
        for(int i=0;i<al.size();i++){
            rt.next=new Node(al.get(i));
            rt=rt.next;
        }
        return wq.next;
    }
    public void Quicksort(int i,int j,ArrayList<Integer>al){
        if (i < j) {
        int p=partition(al,i,j);
         Quicksort(i,p-1,al);
          Quicksort(p+1,j,al);
        }
        
    }
    public int partition(ArrayList<Integer>al,int i,int j){
        int low=i;
        int pivot=al.get(j);
        int high=j-1;
        while(low<=high){
        while(low<=high&&al.get(low)<pivot){
            low++;
        }
        while(low<=high&&al.get(high)>pivot){
            high--;
        }
        if(low<=high){
            int temp=al.get(low);
            al.set(low,al.get(high));
            al.set(high,temp);
            low++;
            high--;
        }
        }
         int temp = al.get(low);
        al.set(low, al.get(j));
        al.set(j, temp);
        return low;
    }
}
