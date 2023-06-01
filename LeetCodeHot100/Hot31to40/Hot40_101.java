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
        if (root.left == null && root.right == null){
            return true;
        }

        return compare(root.left, root.right);
    }
    public static boolean compare(TreeNode nodeleft, TreeNode noderight){
        if (nodeleft == null && noderight == null){
            return true;
        }else if (nodeleft == null){
            return false;
        }else if (noderight == null){
            return false;
        }else if(nodeleft.val != noderight.val){
            return false;
        }

        boolean res1 = compare(nodeleft.left, noderight.right);
        boolean res2 = compare(nodeleft.right, noderight.left);

        return res1 && res2;
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
