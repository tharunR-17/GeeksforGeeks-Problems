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

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.TreeMap;

class Solution {

    static class Pair {
        
        Node node;
        
        int hd;

        Pair(Node node, int hd) {
            
            this.node = node;
            
            this.hd = hd;
            
        }
        
    }

    public ArrayList<Integer> bottomView(Node root) {
        
        ArrayList<Integer> result = new ArrayList<>();
        
        if (root == null) {
            
            return result;
            
        }

        Map<Integer, Integer> bottomNodes = new TreeMap<>();
        
        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(root, 0));

        while (!q.isEmpty()) {
            
            Pair current = q.poll();
            
            Node node = current.node;
            
            int hd = current.hd;

            bottomNodes.put(hd, node.data);

            if (node.left != null) {
                
                q.add(new Pair(node.left, hd - 1));
                
            }

            if (node.right != null) {
                
                q.add(new Pair(node.right, hd + 1));
                
            }
            
        }

        for (int data : bottomNodes.values()) {
            
            result.add(data);
            
        }

        return result;
        
    }
    
}
