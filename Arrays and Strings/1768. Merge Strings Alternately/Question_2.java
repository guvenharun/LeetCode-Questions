class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder merged = new StringBuilder();
        int i=0,j=0;

        while(i < word1.length() || j < word2.length   () ){
            if(i< word1.length()){
                merged.append(word1.charAt(i++));
            }
            if(j < word2.length()){
                merged.append(word2.charAt(j++));

            }
        }
        return merged.toString();
    }
}
 
public class Question_2 {
    public static void main(String[] args) {
        String word1 = "abc";
        String word2 = "qwe";
        Solution sol = new Solution();
        System.out.println(sol.mergeAlternately(word1, word2));
        System.exit(0); 
    }
}

