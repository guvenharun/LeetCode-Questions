#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int findClosestNumber(int* nums, int numsSize) {
    int closest = nums[0];
    int i=1;
    for(i; i<numsSize;i++){
        if (abs(nums[i]) < abs(closest) || (abs(nums[i]) == abs(closest) && nums[i] > closest)) {
            closest = nums[i];
        }
    }

    return closest;
    
}
int main() {
    int nums[] = {-4,-2,1,4,8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int closestNumber = findClosestNumber(nums, numsSize);
    printf("%d", closestNumber);
    
    return 0;
}