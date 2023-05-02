package LeetCodeHot100.Hot91to100;

public class Hot94_543 {
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

    static int maxd = 0;
    public static int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return maxd;
    }
    public static int depth(TreeNode root){
        if (root == null){
            return 0;
        }

        int left = depth(root.left);
        int right = depth(root.right);

        maxd = Math.max(left + right, maxd); //将每个节点最大直径(左子树深度+右子树深度)当前最大值比较并取大者

        return Math.max(left,right)+1;//返回节点深度

    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode l1_left = new TreeNode(2);
        TreeNode l1_right = new TreeNode(3);
        TreeNode l2_left = new TreeNode(4);
        TreeNode l2_right = new TreeNode(5);

        root.left = l1_left;
        root.right = l1_right;

        l1_left.left = l2_left;
        l1_left.right = l2_right;

        int res = diameterOfBinaryTree(root);
        System.out.println(res);
    }
}
