package Basic_Algos.bfs;

import java.util.*;

public class LeetCode_127 {

    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);
        Queue<String> q = new LinkedList<>();
        if(!set.contains(endWord)){
            return 0;
        }

        q.offer(beginWord);
        int step = 1, N = beginWord.length();

        while(!q.isEmpty()){
            int size = q.size();

            for (int i = 0; i < size; i++){ // 相当于遍历当前层的所有的node
                String cur = q.poll();
                if(cur.equals(endWord)){
                    return step;
                }
                for (int j = 0; j < N; j++){ // 循环当前单词每一位替换
                    for (char letter = 'a'; letter <= 'z'; letter++){ // 都可以被替换成25个其他字母的情况
                        StringBuilder next = new StringBuilder(cur);
                        next.setCharAt(j, letter);
                        String nextWord = next.toString();
                        if (set.contains(nextWord)){
                            if (nextWord.equals(endWord)){
                                return step+1;
                            }
                            set.remove(nextWord); // 需要从set里面拿出来 否则就循环了
                            q.offer(nextWord);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }

    /*
    优化 双向bfs
     */
    public static int ladderLength2(String beginWord, String endWord, List<String> wordList) {
        Set<String> beginSet = new HashSet<>(), endSet = new HashSet<>();
        Set<String> wordListSet = new HashSet<>(wordList);
        Set<String> visited = new HashSet<>();
        if (!wordListSet.contains(endWord)){
            return 0;
        }

        int step = 1, N = beginWord.length();

        beginSet.add(beginWord);
        endSet.add(endWord);

        while(!beginSet.isEmpty() && !endSet.isEmpty()){
            Set<String> nextSet = new HashSet<>();
            for (String word : beginSet){ // 从beginSet中每一个word展开 看是否能到达endSet
                char[] chs = word.toCharArray();
                for (int i = 0; i < N; i++){ // 每一位的字母替换成 'a'-'z'
                    for (char c = 'a'; c <= 'z'; c++){
                        char pre = chs[i];
                        chs[i] = c;
                        String nextWord = new String(chs);

                        if (endSet.contains(nextWord)){
                            return step + 1;
                        }
                        if (visited.add(nextWord) && wordListSet.contains(nextWord)){
                            nextSet.add(nextWord);
                        }
                        chs[i] = pre;
                    }
                }
            }
            if (endSet.size() < nextSet.size()){ // 最核心的优化 选择较小的一端进行
                beginSet = endSet;
                endSet = nextSet;
            }else{
                beginSet = nextSet;
            }
            step++;
        }
        return 0;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String beginWord = sc.nextLine();

        String endWord = sc.nextLine();

        List<String> wordList = Arrays.stream(sc.nextLine().split(" ")).toList();

        int res = ladderLength(beginWord, endWord, wordList);

        System.out.println(res);
    }
}
