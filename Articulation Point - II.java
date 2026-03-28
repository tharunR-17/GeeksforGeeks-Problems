import java.util.*;

class Solution {
    
    static class Frame {
        int node, parent, idx;
        Frame(int n, int p, int i) {
            node = n;
            parent = p;
            idx = i;
        }
    }
    
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        int[] tin = new int[V];
        int[] low = new int[V];
        boolean[] visited = new boolean[V];
        boolean[] isAP = new boolean[V];

        int timer = 0;

        for (int start = 0; start < V; start++) {
            if (visited[start]) continue;

            Stack<Frame> stack = new Stack<>();
            int[] childrenCount = new int[V];

            stack.push(new Frame(start, -1, 0));

            while (!stack.isEmpty()) {
                Frame f = stack.peek();
                int node = f.node;
                int parent = f.parent;

                if (!visited[node]) {
                    visited[node] = true;
                    tin[node] = low[node] = timer++;
                }

                if (f.idx < adj.get(node).size()) {
                    int neighbor = adj.get(node).get(f.idx++);
                    
                    if (neighbor == parent) continue;

                    if (!visited[neighbor]) {
                        childrenCount[node]++;
                        stack.push(new Frame(neighbor, node, 0));
                    } else {
                        low[node] = Math.min(low[node], tin[neighbor]);
                    }

                } else {
                    stack.pop();

                    if (parent != -1) {
                        low[parent] = Math.min(low[parent], low[node]);

                        if (low[node] >= tin[parent]) {
                            isAP[parent] = true;
                        }
                    }
                }
            }

            if (childrenCount[start] <= 1) {
                isAP[start] = false;
            }
        }

        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (isAP[i]) res.add(i);
        }

        if (res.size() == 0) res.add(-1);

        Collections.sort(res);
        return res;
    }
}
