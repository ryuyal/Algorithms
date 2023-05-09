package Basic_DS.Trie;

public class LeetCode211 {
    static class TrieNode{
        TrieNode[] children;
        boolean isWord;

        TrieNode(){
            children = new TrieNode[26];
        }
    }
    static class WordDictionary {
        TrieNode root;
        public WordDictionary() {
            root = new TrieNode();
        }

        public void addWord(String word) {
            TrieNode node = root;

            for (char ch : word.toCharArray()){
                if (node.children[ch - 'a'] == null){
                    node.children[ch - 'a'] = new TrieNode();
                }
                node = node.children[ch - 'a'];
            }
            node.isWord = true;
        }

        public boolean search(String word) {
            return helper(word, 0, root);
        }

        public boolean helper(String word, int pos, TrieNode node){

            if (pos == word.length()){
                return node.isWord;
            }
            char ch = word.charAt(pos);
            if (ch != '.'){
                return node.children[ch - 'a'] != null && helper(word, pos+1, node.children[ch - 'a']);
            }else{
                for (int i = 0; i < 26; ++i){
                    if (node.children[i] != null && helper(word, pos+1, node.children[i])){
                        return true;
                    }
                }
                return false;
            }

        }

        public static void main(String[] args) {
            WordDictionary wordDictionary = new WordDictionary();
            wordDictionary.addWord("bad");
            wordDictionary.addWord("dad");
            wordDictionary.addWord("mad");

            System.out.println(wordDictionary.search("pad")); // 返回 False
            System.out.println(wordDictionary.search("bad")); // 返回 True
            System.out.println(wordDictionary.search(".ad")); // 返回 True
            System.out.println(wordDictionary.search("b..")); // 返回 True
        }
    }
}
