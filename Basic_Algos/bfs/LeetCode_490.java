package Basic_Algos.bfs;

import java.util.LinkedList;
import java.util.Queue;

/*
0 代表可以走
1 代表墙(只有撞到墙才能改变方向)

给一个迷宫矩阵，起点和终点
看是否可以从起点到终点
 */
public class LeetCode_490 {
    static int[][] dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // 代表四个方向
    public static boolean hasPath(int[][] maze, int[] start, int[] destination){
        boolean [][] visited = new boolean[maze.length][maze[0].length];
        Queue<int[]> q = new LinkedList<>();
        q.offer(start);

        visited[start[0]][start[1]] = true; // 该点已经访问过

        while(!q.isEmpty()){
            int[] cur = q.poll();
            if (cur[0] == destination[0] && cur[1] == destination[1]){
                return true;
            }

            for (int[] dir : dirs){
                int x = cur[0] + dir[0], y = cur[1] + dir[1];
                while(x >= 0 && y >=0 && x < maze.length && y < maze[0].length && maze[x][y] == 0){
                    x += dir[0];
                    y += dir[1];
                }
                x -= dir[0];  // 注意这里需要退一步 因为现在在的地方是invalid才跳出while循环
                y -= dir[1];

                if (!visited[x][y]){
                    q.offer(new int[]{x, y});
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        int[][] maze = {{0,0,1,0,0}, {0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};

        int[] start = {0, 4};
        int[] destination = {4, 4};

        boolean res = hasPath(maze, start, destination);

        System.out.println(res);
    }
}
