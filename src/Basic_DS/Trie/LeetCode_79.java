package Basic_DS.Trie;

public class LeetCode_79 {
    /*
    只考虑了小写的情况
     */
//    static class TrieNode{
//        TrieNode[] children;
//        boolean isWord;
//        TrieNode(){
//            children = new TrieNode[26];
//        }
//    }
//    static class Trie{
//        TrieNode root;
//        Trie(){
//            root = new TrieNode();
//        }
//
//        public void insert(String word){
//            TrieNode node = root;
//
//            for (char ch : word.toCharArray()){
//                if (node.children[ch - 'a'] == null){
//                    node.children[ch - 'a'] = new TrieNode();
//                }
//                node = node.children[ch - 'a'];
//            }
//            node.isWord = true;
//        }
//
//        public boolean search(String word){
//            TrieNode node = root;
//
//            for (char ch : word.toCharArray()){
//                if (node.children[ch - 'a'] == null){
//                    return false;
//                }
//                node = node.children[ch - 'a'];
//            }
//            return node.isWord;
//        }
//
//        public boolean startsWith(String prefix){
//            TrieNode node = root;
//
//            for (char ch : prefix.toCharArray()){
//                if (node.children[ch - 'a'] == null){
//                    return false;
//                }
//                node = node.children[ch - 'a'];
//            }
//            return true;
//        }
//    }
//    public static boolean exist(char[][] board, String word) {
//        Trie trie = new Trie();
//        trie.insert(word);
//
//        int M = board.length;
//        int N = board[0].length;
//
//        boolean[][] visited = new boolean[M][N];
//        for (int i = 0; i < M; ++i){
//            for (int j = 0; j < N; ++j){
//                if(dfs(board, visited, "", i, j, trie)){
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    public static boolean dfs(char[][] board, boolean[][] visited, String str, int x, int y, Trie trie){
//        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length){
//            return false;
//        }
//
//        if (visited[x][y]){
//            return false;
//        }
//
//        str += board[x][y];
//
//        if (!trie.startsWith(str)){
//            return false;
//        }
//        if (trie.search(str)){
//            return true;
//        }
//
//        visited[x][y] = true;
//
//        boolean res1 = dfs(board, visited, str, x-1, y, trie);
//        boolean res2 = dfs(board, visited, str, x+1, y, trie);
//        boolean res3 = dfs(board, visited, str, x, y-1, trie);
//        boolean res4 = dfs(board, visited, str, x, y+1, trie);
//
//        visited[x][y] = false;
//        return res1 || res2 || res3 || res4;
//    }


    public static boolean exist(char[][] board, String word) {
        int M = board.length;
        int N = board[0].length;
        boolean[][] visited = new boolean[M][N];

        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j){
                if (dfs(board, word, 0, i, j, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    public static boolean dfs(char[][] board, String word, int i, int x, int y, boolean[][] visited){
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length){
            return false;
        }

        // 重复访问
        if (visited[x][y]){
            return false;
        }

        // 当前字符不匹配
        if (board[x][y] != word.charAt(i)){
            return  false;
        }

        // 全部字符匹配
        if (i == word.length()-1){
            return true;
        }

        // 当前字符匹配 做访问标记
        visited[x][y] = true;

        boolean res1 = dfs(board, word, i+1, x-1, y, visited);
        boolean res2 = dfs(board, word, i+1, x+1, y, visited);
        boolean res3 = dfs(board, word, i+1, x, y-1, visited);
        boolean res4 = dfs(board, word, i+1, x, y+1, visited);

        boolean f = res1 || res2 || res3 || res4;

        if (f){
            return true;
        }

        // 回溯修改当前不能访问的点 但是接下来的方向可以访问它
        visited[x][y] = false;

        return false;
    }

    public static void main(String[] args) {
        char [][] board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};

        String word = "oath";

        boolean res = exist(board, word);

        System.out.println(res);
    }
}
