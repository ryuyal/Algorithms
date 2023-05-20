package Basic_Algos.bfs;

import java.util.*;

public class LeetCode_207 {
    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>(); // 图的邻接表表示方式
        int[] indegree = new int[numCourses]; // 根据边建立图 计算入度

        for (int i = 0; i < prerequisites.length; i++){
            int end = prerequisites[i][0];
            int start = prerequisites[i][1];

//            if (!graph.containsKey(start)){
//
//                graph.put(start, new ArrayList<>(end));
//
//            }else{
//                List<Integer> tmp = graph.get(start);
//                tmp.add(end);
//                graph.put(start, tmp);
//            }
            graph.computeIfAbsent(start, x -> new ArrayList<>()).add(end);
            indegree[end]++; // [0, 1] 图的方向是 从1指向0, 0的入度有所增加
        }

        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < indegree.length; i++){
            if (indegree[i] == 0){
                q.add(i); // 入度为0的点作为入口
            }
        }
        int count = 0; // 一共能遍历多少个点
        while(!q.isEmpty()){ // 广度优先搜索
            int cur = q.poll();
            count++;
            for (int nei : graph.getOrDefault(cur, new ArrayList<>())){
                if (--indegree[nei] == 0){
                    q.offer(nei);
                }
            }
        }
        return count == numCourses;
    }

    public static void main(String[] args) {
        int[][] prerequisites = {{0, 1}, {1, 0}};

        int numCourses = 2;

        boolean res = canFinish(numCourses, prerequisites);

        System.out.println(res);
    }
}
