package Basic_Algos.bfs;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

/*
迪杰斯特拉 单源最短路径算法
 */
public class LeetCode_505 {
    static int[][] dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    public static void dijkstra(int[][] maze, int[] start, int[][] distance){
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[2] - b[2]);

        q.offer(new int[] {start[0], start[1], 0}); // x坐标 y坐标  从起点到当前 x y 的距离distance
        while(!q.isEmpty()) {
            int[] cur = q.poll();

            for (int[] dir : dirs) {
                int x = cur[0] + dir[0];
                int y = cur[1] + dir[1];
                int count = 0;

                while (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    count++;
                }
                x -= dir[0];
                y -= dir[1];

                if (distance[cur[0]][cur[1]] + count < distance[x][y]){
                    distance[x][y] = distance[cur[0]][cur[1]] + count;
                    q.add(new int[]{x, y, distance[x][y]});
                }
            }
        }
    }
    public static int shortestDistance(int[][] maze, int[] start, int[] destination){

        int[][] distance = new int[maze.length][maze[0].length];
        for (int[] row : distance){
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        distance[start[0]][start[1]] = 0;
        dijkstra(maze, start, distance);

        return distance[destination[0]][destination[1]] == Integer.MAX_VALUE ? -1 : distance[destination[0]][destination[1]];
    }
    public static void main(String[] args) {
        int[][] maze = {{0,0,1,0,0}, {0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};

        int[] start = {0, 4};
        int[] destination = {4, 4};

        int res = shortestDistance(maze, start, destination);

        System.out.println(res);
    }
}
