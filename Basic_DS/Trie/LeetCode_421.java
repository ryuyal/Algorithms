package Basic_DS.Trie;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_421 {
    static class TrieNode{
        TrieNode[] children;

        TrieNode(){
            children = new TrieNode[2];
        }
    }
    static class Trie{
        TrieNode root;

        Trie(){
            root = new TrieNode();
        }

        public void addNum(int num){
            TrieNode node = root;
            for (int i = 31; i >= 0; --i){
                int curBit = (num >> i) & 1; // 右移n位就是除以2的n次方 奇数&1为1，偶数&1为0
                if (node.children[curBit] == null){
                    node.children[curBit] = new TrieNode();
                }
                node = node.children[curBit];
            }
        }

        public int findMaxXor(int num){
            int sum = 0;
            TrieNode node = root;

            for (int i = 31; i >= 0; --i){
                int curBit = (num >> i) & 1;
                int otherChoice = curBit == 1 ? 0 : 1;
                if (node.children[otherChoice] != null){
                    sum += (1 << i); // 左移n位就是乘以2的n次方
                    node = node.children[otherChoice];
                }else{
                    node = node.children[curBit];
                }
            }
            return sum;
        }
    }
    public static int findMaximumXOR(int[] nums) {
        Trie trie = new Trie();

        for (int num : nums){
            trie.addNum(num);
        }

        int res = Integer.MIN_VALUE;
        for (int num : nums){
            res = Math.max(res, trie.findMaxXor(num));
        }

        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = findMaximumXOR(nums);

        System.out.println(res);
    }
}
