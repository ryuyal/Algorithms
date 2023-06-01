package LeetCodeHot100.Hot41to50;

import LeetCodeHot100.Hot31to40.Hot37_94;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class Hot41_102{
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

    public static List<List<Integer>> levelOrder(TreeNode root) {
          List<List<Integer>> res = new ArrayList<>();
          if (root==null){
              return res;
          }
          Deque<TreeNode> queue = new LinkedList<>();

          queue.add(root);

          while (!queue.isEmpty()){
              int len = queue.size();
              List<Integer> tmplist = new ArrayList<>();
              while (len > 0){
                  TreeNode tmp = queue.remove();
                  tmplist.add(tmp.val);
                  if (tmp.left!=null){
                      queue.add(tmp.left);
                  }
                  if (tmp.right!=null){
                      queue.add(tmp.right);
                  }
                  len--;
              }
              res.add(tmplist);
          }
          return res;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode l1_right = new TreeNode(2);
        TreeNode l2_left = new TreeNode(3);
        root.right = l1_right;
        l1_right.left = l2_left;

        List<List<Integer>> res = levelOrder(root);
        for (List<Integer> list : res) {
            for (int num : list) {
                System.out.print(num+" ");
            }
            System.out.println();
        }
    }
}
