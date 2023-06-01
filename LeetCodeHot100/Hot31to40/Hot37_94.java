package LeetCodeHot100.Hot31to40;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Hot37_94 {
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

      /*
      递归
       */
    public static List<Integer> inorderTraversal(TreeNode root){
         List<Integer> res = new ArrayList<>();
         inorder(root, res);
         return res;
    }
    public static void inorder(TreeNode root, List<Integer> list){
         if (root == null){
             return;
         }
         inorder(root.left, list);
         list.add(root.val);
         inorder(root.right, list);
    }

    /*
    迭代
     */
    public static List<Integer> inorderTraversal2(TreeNode root){
        Stack<TreeNode> stack = new Stack<>();
        List<Integer> resList = new ArrayList<>();

        TreeNode cur = root;

        while(cur != null || !stack.isEmpty()){
            if (cur != null){
                stack.push(cur);
                cur = cur.left;
            }else {
                cur = stack.pop();
                resList.add(cur.val);
                cur = cur.right;
            }
        }
        return resList;
    }
    public static void main(String[] args) {
         TreeNode root = new TreeNode(1);
         TreeNode l1_right = new TreeNode(2);
         TreeNode l2_left = new TreeNode(3);
         root.right = l1_right;
         l1_right.left = l2_left;

         List<Integer> res = inorderTraversal(root);
         for (int num : res){
             System.out.println(num);
         }
    }
}
