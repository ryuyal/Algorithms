package JianZhiOffer2;

public class Offer2_62 {
    static class TrieNode{
        TrieNode[] children;
        boolean isWord;

        TrieNode(){
            children = new TrieNode[26];
        }
    }
    static class Trie {

        TrieNode root;
        /** Initialize your data structure here. */
        public Trie() {
            root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        public void insert(String word) {
            TrieNode node = root;

            for (char ch : word.toCharArray()){
                if (node.children[ch - 'a'] == null){
                    node.children[ch - 'a'] = new TrieNode();
                }
                node = node.children[ch - 'a'];
            }
            node.isWord = true;

        }

        /** Returns if the word is in the trie. */
        public boolean search(String word) {
            TrieNode node = root;

            for (char ch : word.toCharArray()){
                if (node.children[ch - 'a'] == null){
                    return false;
                }
                node = node.children[ch - 'a'];
            }
            return node.isWord;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        public boolean startsWith(String prefix) {
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

    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.insert("apple");
        System.out.println(trie.search("apple"));   // 返回 True
        System.out.println(trie.search("app"));     // 返回 False
        System.out.println(trie.startsWith("app")); // 返回 True
        trie.insert("app");
        System.out.println(trie.search("app"));     // 返回 True

    }
}
