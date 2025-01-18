class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";

        StringBuilder result = new StringBuilder();
        int n = 0;
        int m = 0;

        while(true){
            if (m >= strs[0].length()) {
                break;
            }
            char current = strs[0].charAt(m);

            if(n < strs.length - 1){
                if(m>= strs[n+1].length() ||strs[n+1].charAt(m) != current || current ==  ' '){
       
                    break;
                }
                n++;
            }else{
                result.append(current);
                m++;
                n=0;
            }
        }
        
        return result.toString(); 
    }
}


public class Questin_6 {
    public static void main(String args[]){

        Solution sol = new Solution();
        String[] strs1 = {"flower", "flow", "flight"};
        String[] strs2 = {"dog", "racecar", "car"};

        System.out.println(sol.longestCommonPrefix(strs1));
        System.out.println(sol.longestCommonPrefix(strs2));

        System.exit(0);
    }   
}