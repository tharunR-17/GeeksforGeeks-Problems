class Solution {
 public ArrayList<Integer> nextGreater(int[] arr) {  
   
        if (arr == null || arr.length == 0) return new ArrayList<>();

        int n = arr.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);

        Deque<Integer> stack = new ArrayDeque<>(); 

       
        for (int i = 0; i < 2 * n; i++) {
            int val = arr[i % n];

            while (!stack.isEmpty() && arr[stack.peek()] < val) {
                res[stack.pop()] = val;
            }

            
            if (i < n) stack.push(i);
        }

        ArrayList<Integer> ans = new ArrayList<>(n);
        for (int x : res) ans.add(x);
        return ans;
    

    }
}
