package Basic_Algos.bfs;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode_111 {
    static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(){}
        TreeNode(int val){
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    // level order
    public static int minDepth(TreeNode root) {
        if (root == null){
            return 0;
        }
        int depth = 1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()){
            int size = q.size();
            for (int i = 0; i < size; ++i){
                TreeNode cur = q.poll();
                if (cur.left == null && cur.right == null){
                    return depth;
                }
                if (cur.left != null){
                    q.offer(cur.left);
                }
                if (cur.right != null){
                    q.offer(cur.right);
                }
            }
            depth++;
        }
        return depth;
    }

    public static int minDepth2(TreeNode root) {
        if (root == null){
            return 0;
        }

        // 左子树为空
        if (root.left == null){
            return minDepth2(root.right) + 1;
        }

        // 右子树为空
        if (root.right == null){
            return minDepth2(root.left) + 1;
        }

        // 左右子树都不为空
        return Math.min(minDepth2(root.right), minDepth2(root.left)) + 1;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        TreeNode l1_left = new TreeNode(9);
        TreeNode l1_right = new TreeNode(20);

        TreeNode l2_left = new TreeNode(15);
        TreeNode l2_right = new TreeNode(7);

        root.left = l1_left;
        root.right = l1_right;

        l2_right.left = l2_left;
        l2_right.right = l2_right;

        int res = minDepth(root);

        System.out.println(res);
    }
}
