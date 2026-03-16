/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    
    public int helper(Node node, int k, int currentSum) {
        if(node == null) return 0;
        
        int count = 0;
        currentSum += node.data;
        if(currentSum == k) {
            count++;
        }
        
        count += helper(node.left, k, currentSum);
        count += helper(node.right, k, currentSum);
        
        return count;
    }
    
    public int dfs(Node node, int k) {
        if(node == null) return 0;
        
        int currentSum = helper(node, k, 0);
        
        currentSum += dfs(node.left, k);
        currentSum += dfs(node.right, k);
        
        return currentSum;
    }
    
    public int countAllPaths(Node root, int k) {
        return dfs(root, k);
    }
}
