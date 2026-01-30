class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        //initialize a Queue for 2nd Half
        Queue<Integer> queue = new LinkedList<>();
        //initialize a Queue for result
        Queue<Integer> res = new LinkedList<>();
        //Iterating until the both queue size are equal
        while (q.size() != queue.size()) {
            queue.add(q.poll());
        }
        //Adding elements to the queue until it is empty
        while(!q.isEmpty() && !queue.isEmpty()){
            res.add(queue.poll());
            res.add(q.poll());
        }
        for (Integer val : res) {
            System.out.print(val + " ");
        }
    }
}
