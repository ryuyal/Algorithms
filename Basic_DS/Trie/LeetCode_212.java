package Basic_DS.Trie;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode_212 {
    static class TrieNode{
        TrieNode[] children;
        boolean isWord;
        TrieNode(){
            children = new TrieNode[26];
        }
    }
    static class Trie{
        TrieNode root;

        Trie(){
            root = new TrieNode();
        }

        public void insert(String word){
            TrieNode node = root;

            for (char ch : word.toCharArray()){
                if (node.children[ch - 'a'] == null){
                    node.children[ch - 'a'] = new TrieNode();
                }
                node = node.children[ch - 'a'];
            }
            node.isWord = true;
        }

        public boolean search(String word){
            TrieNode node = root;

            for (char ch : word.toCharArray()){
                if (node.children[ch - 'a'] == null){
                    return false;
                }
                node = node.children[ch - 'a'];
            }
            return node.isWord;
        }
        public boolean startsWith(String prefix){
            TrieNode node = root;
            for (char ch : prefix.toCharArray()){
                if (node.children[ch - 'a'] == null){
                    return false;
                }
                node = node.children[ch - 'a'];
            }
            return true;
        }
    }

    static Set<String> res = new HashSet<>();
    public static List<String> findWords(char[][] board, String[] words) {
        int M = board.length;
        int N = board[0].length;

        Trie trie = new Trie();
        for (String word : words){ // 把words存入前缀树
            trie.insert(word);
        }

        boolean[][] visited = new boolean[M][N];
        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j){
                dfs(board, visited, "", i, j, trie);
            }
        }
        return new ArrayList<String>(res);
    }

    public static void dfs(char[][] board, boolean[][] visited, String str, int x, int y, Trie trie){
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) { // 超出矩阵边界
            return;
        }

        if (visited[x][y]){ // 已经遍历过
            return;
        }

        str += board[x][y];
        if (!trie.startsWith(str)){ // 当前的字符串是否为 prefix 如果不是prefix就不用再往下找了
            return;
        }

        if (trie.search(str)){
            res.add(str);
        }
        visited[x][y] = true;

        dfs(board, visited, str, x-1, y, trie);
        dfs(board, visited, str, x+1, y, trie);
        dfs(board, visited, str, x, y-1, trie);
        dfs(board, visited, str, x, y+1, trie);

        visited[x][y] = false;

    }

    public static void main(String[] args) {
        char [][] board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};

        String[] words = {"oath","pea","eat","rain"};

        List<String> res = findWords(board, words);

        for (String s : res){
            System.out.println(s);
        }
    }
}
