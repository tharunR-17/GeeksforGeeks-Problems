class Solution {
    static class Node{
        ArrayList<Integer> list;
        
        Node(ArrayList<Integer> list){
            this.list = list;
        }
        
        @Override
        public boolean equals(Object o){
            if(this == o) return true;
            if(o == null || getClass() != o.getClass()) return false;
            
            Node node = (Node)o;
            
            return this.list.equals(node.list);
        }
        
        @Override
        public int hashCode(){
            return list.hashCode();
        }
    }
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] arr) {
        // code here
        int n = arr.length;
        HashSet<Node> hs = new HashSet<>();
        boolean[] vis = new boolean[n];
        ArrayList<ArrayList<Integer>> main = new ArrayList<>();
        ArrayList<Integer> list = new ArrayList<>();
        
        find(main,hs,arr,list,vis,-1,n);
        
        Collections.sort(main,new Comparator<ArrayList<Integer>>(){
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2){
                for(int i = 0; i < o1.size(); i++){
                    int cmp = 0;
                    if(o1.get(i) != o2.get(i)){
                        cmp = o1.get(i)-o2.get(i);
                    }
                    if(cmp != 0) return cmp;
                }
                return 0;
            }
        });
        
        return main;
        
    }
    private static void find(ArrayList<ArrayList<Integer>> main, HashSet<Node> hs, int[] arr, ArrayList<Integer> list, boolean[] vis, int idx, int n){
        if(idx >= n) return;
        if(list.size() == n){
            Node node = new Node(list);
            if(!hs.contains(node)){
                hs.add(node);
                main.add(list);
            }
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ArrayList<Integer> list2 = new ArrayList<>(list);
                list2.add(arr[i]);
                vis[i] = true;
                find(main,hs,arr,list2,vis,i,n);
                vis[i] = false;
            }
        }
    }
}
