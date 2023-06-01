package LeetCodeHot100.Hot91to100;

public class Hot97_617 {
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
    public static TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        return dfs(root1, root2);
    }
    public static TreeNode dfs(TreeNode root1, TreeNode root2){
        if (root1 == null || root2 == null){
            return root1 == null ? root2 : root1;
        }

        root1.val += root2.val;

        root1.left = dfs(root1.left, root2.left);
        root1.right = dfs(root1.right, root2.right);

        return root1;
    }
    public static void main(String[] args) {

    }
}
