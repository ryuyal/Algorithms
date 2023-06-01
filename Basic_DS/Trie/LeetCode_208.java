package Basic_DS.Trie;

public class LeetCode_208 {
    static class TrieNode{
        TrieNode[] children;
        boolean isWord;

        TrieNode(){
            children = new TrieNode[26];
        }
    }
    static class Trie {
        TrieNode root;
        public Trie(){
            root = new TrieNode();
        }

        public void insert(String word){
            TrieNode node = root;
            for(char c : word.toCharArray()){
                if(node.children[c - 'a'] == null){
                    node.children[c - 'a'] = new TrieNode();
                }
                node = node.children[c - 'a'];
            }
            node.isWord = true;
        }

        public boolean search(String word){
            TrieNode node = root;
            for(char c : word.toCharArray()){
                if(node.children[c - 'a'] == null){
                    return false;
                }
                node = node.children[c - 'a'];
            }
            return node.isWord;
        }

        public boolean startsWith(String prefix){
            TrieNode node = root;
            for(char c : prefix.toCharArray()){
                if(node.children[c - 'a'] == null){
                    return false;
                }
                node = node.children[c - 'a'];
            }
            return true;
        }
    }
    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.insert("apple");
        boolean res1 = trie.search("apple");
        boolean res2 = trie.search("app");
        boolean res3 = trie.startsWith("app");
        trie.insert("app");
        boolean res4 = trie.search("app");

        System.out.println(res1);
        System.out.println(res2);
        System.out.println(res3);
        System.out.println(res4);
    }
}
