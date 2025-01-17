class Solution {
    public boolean isSubsequence(String s, String t) {
        int i =0, j=0;
        while (i < s.length() && j < t.length()) {

            if(s.charAt(i) == t.charAt(j)){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i == s.length();
    }
}
public class Question_4 {
    public static void main(String args[]){
        Solution sol = new Solution();
        String s = "abc";
        String t = "awnbghc";
    
        System.out.println(sol.isSubsequence(s,t));
        System.exit(0);
    }

}
