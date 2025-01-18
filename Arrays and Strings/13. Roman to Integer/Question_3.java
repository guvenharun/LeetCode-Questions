class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int[] romanValues = new int[26];
        
        romanValues ['I' - 'A'] = 1;
        romanValues ['V' - 'A'] = 5;
        romanValues ['X' - 'A'] = 10;
        romanValues ['L' - 'A'] = 50;
        romanValues ['C' - 'A'] = 100;
        romanValues ['D' - 'A'] = 500;
        romanValues ['M' - 'A'] = 1000;

        int prevValue = 0;

        for(int i=0; i< s.length() ;i++){
            int currentValue = romanValues[s.charAt(i)-'A'];

            if(prevValue < currentValue){
                sum += currentValue -2*prevValue;
            }else{
                sum+= currentValue;
            }
            prevValue = currentValue; 

        }
        return sum;
    }
}
public class Question_3 {
    public static void main(String[] args){
        Solution sol = new Solution();
        String s ="MCMXCIV";
        System.out.println(sol.romanToInt(s));
        System.exit(0);
    }
}
