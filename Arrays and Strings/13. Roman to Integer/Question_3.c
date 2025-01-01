#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int sum = 0;
    int roman_values[26] = {0};

    roman_values['I' - 'A'] = 1;
    roman_values['V' - 'A'] = 5;
    roman_values['X' - 'A'] = 10;
    roman_values['L' - 'A'] = 50;
    roman_values['C' - 'A'] = 100;
    roman_values['D' - 'A'] = 500;
    roman_values['M' - 'A'] = 1000;

    int prev_value = 0;

    for(int i = 0; i< strlen(s); i++){
        int current_value = roman_values[s[i] - 'A'];

        if (prev_value < current_value){
            sum += current_value - 2*prev_value;
        }
        else{
            sum += current_value;
        } 
        prev_value = current_value;
    }
    return sum;

}
int main() {
    char s[] = "MCMXCIV";
    printf("%d",romanToInt(s));
    return 0;
}