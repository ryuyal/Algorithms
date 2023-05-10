package Basic_DS.UnionFind;


public class LeetCode547 {
    static class DSU{
    int[] parent;

    public DSU(int N){
        parent = new int[N];
        for (int i = 0; i < N; i++){
            parent[i] = i;
        }
    }

    public int find(int x){
        if (parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void union(int x, int y){
        parent[find(x)] = find(y);
    }
}

    public static int findCircleNum(int[][] isConnected) {
        DSU dsu = new DSU(isConnected.length);

        for (int i = 0; i < isConnected.length; ++i){
            for (int j = 0; j < isConnected[0].length; ++j){
                if (isConnected[i][j] == 1){
                    dsu.union(i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < isConnected.length; i++){
            if (dsu.find(i) == i){ // root parent
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[][] isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

        int res = findCircleNum(isConnected);
        System.out.println(res);
    }
}
