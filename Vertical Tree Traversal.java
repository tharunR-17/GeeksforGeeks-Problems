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
    Map<Integer, Map<Integer, ArrayList<Integer>>> map = new TreeMap<>();
    void trav(Node root, int row, int col) {
        if(root == null) return;
        
        map
        .computeIfAbsent(col, k -> new TreeMap<>())
        .computeIfAbsent(row, k -> new ArrayList<>())
        .add(root.data);
        trav(root.left, row + 1, col - 1);
        trav(root.right, row + 1, col + 1);
    }
    public ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        // code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        trav(root, 0, 0);
        
        for(int col : map.keySet()) {
            Map<Integer, ArrayList<Integer>> t = map.get(col);
            ArrayList<Integer> curr = new ArrayList<>();
            for(int nx : t.keySet()) {
                curr.addAll(t.get(nx));
            }
            ans.add(curr);
        }
        return ans;
        
    }
}
