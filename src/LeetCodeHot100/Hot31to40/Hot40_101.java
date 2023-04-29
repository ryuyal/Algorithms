package LeetCodeHot100.Hot31to40;

import java.util.List;

public class Hot40_101 {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public static boolean isSymmetric(TreeNode root) {
        if (root == null){
            return true;
        }
        boolean res = compare(root.left , root.right);

        return res;
    }
    public static boolean compare(TreeNode nodeleft, TreeNode noderight){
        if (nodeleft == null && noderight != null){
            return false;
        }else if (nodeleft != null && noderight == null){
            return false;
        }else if (nodeleft == null && noderight == null){
            return true;
        }else if(nodeleft.val != noderight.val){
            return false;
        }

        // 剩下的情况就是 左右节点都不空 且数值相同
        boolean case1 = compare(nodeleft.left, noderight.right);
        boolean case2 = compare(nodeleft.right, noderight.left);

        return case1 && case2;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode l1_right = new TreeNode(2);
        TreeNode l2_left = new TreeNode(3);
        root.right = l1_right;
        l1_right.left = l2_left;

        boolean res = isSymmetric(root);
        System.out.println(res);
    }
}
