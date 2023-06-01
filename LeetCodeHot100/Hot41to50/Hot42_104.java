package LeetCodeHot100.Hot41to50;

public class Hot42_104 {
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
    public static int maxDepth(TreeNode root) {
        if (root == null){
            return 0;
        }
        if (root.left == null && root.right == null){
            return 1;
        }
        return 1+(Math.max(maxDepth(root.left), maxDepth(root.right)));
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode l1_left = new TreeNode(2);
        TreeNode l1_right = new TreeNode(3);
        TreeNode l2_left = new TreeNode(4);

        root.left = l1_left;
        root.right = l1_right;

        l1_left.right = l2_left;

        int res = maxDepth(root);

        System.out.println(res);
    }
}
