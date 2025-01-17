class Solution {
    public int maxProfit(int[] prices) {
        int prev = 0;
        int lower = prices[0];
        int higher = 0;
        int[] profits = new int[prices.length]; 

        for (int i = 0; i < prices.length; i++) {
            int current = prices[i]; 
            if (current < prev && current < lower) { 
                lower = current;
                higher = 0;
            } else {
                higher = current;
            }
            profits[i] = higher - lower;
            prev = current;
        }

        int max = profits[0]; 

        for (int profit : profits) {
            max = Math.max(max, profit); 
        }
        return max;
    }
}

public class Questin_5 {
    public static void main(String args[]){
        Solution sol = new Solution();

        int[] prices = {5,3,7,1,6,4};
        System.out.println(sol.maxProfit(prices));
        
        System.exit(0);

    }
    
}
