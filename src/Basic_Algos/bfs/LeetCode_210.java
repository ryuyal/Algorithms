package Basic_Algos.bfs;

import java.util.*;

public class LeetCode_210 {
    public static int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>();

        List<Integer> res = new ArrayList<>();

        int[] indegree = new int[numCourses];

        for (int i = 0; i < prerequisites.length; i++){
            int start = prerequisites[i][1];
            int end = prerequisites[i][0];

            graph.computeIfAbsent(start, x -> new ArrayList<>()).add(end);

            indegree[end]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++){
            if (indegree[i] == 0){
                queue.offer(i);
            }
        }
        int count = 0;
        while(!queue.isEmpty()){
            int cur = queue.poll();
            count++;
            res.add(cur);
            for (int nei : graph.getOrDefault(cur, new ArrayList<>())){
                if (--indegree[nei] == 0){
                    queue.offer(nei);
                }
            }
        }

        if (count == numCourses){
            int[] res2 = new int[res.size()];
            for (int i = 0; i < res2.length; i++){
                res2[i] = res.get(i);
            }
            return res2;
        }else{
            return new int[]{};
        }

    }

    public static void main(String[] args) {
        int[][] prerequisites = {{0, 1}, {1, 0}};

        int numCourses = 2;

        int[] res = findOrder(numCourses, prerequisites);

        System.out.println(Arrays.toString(res));
    }
}
