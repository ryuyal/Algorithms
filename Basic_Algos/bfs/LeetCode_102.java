package Basic_Algos.bfs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode_102 {
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

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null){
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while(!queue.isEmpty()){
            int size = queue.size();
            List<Integer> tmpList = new ArrayList<>();
            for (int i = 0; i < size; ++i){
                TreeNode tmpNode = queue.poll();
                tmpList.add(tmpNode.val);
                if (tmpNode.left != null){
                    queue.offer(tmpNode.left);
                }
                if (tmpNode.right != null){
                    queue.offer(tmpNode.right);
                }
            }
            res.add(tmpList);
        }
        return res;
    }

    public static void main(String[] args) {

    }
}
