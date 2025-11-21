#include <stdio.h>
#include <stdlib.h>


int kLengthApart(int* nums, int numsSize, int k) {
    int streak = 0;
    int start = 1;
    for(int i = 0; i < numsSize; i++){
        if(start){
            if(nums[i] == 1)
                start = 0;
            continue;
        }
        
        if(nums[i] == 0) {
            streak++;
        }
        if(nums[i] == 1 && i != 0) {
            if(streak < k) {
                return 0;
            }
            streak = 0;
        }

    }
    return 1;

}

int main() {
    int numsSize = 6;
    int nums[] = {1,0,0,1,0,1};
    int k = 2;

    printf("%d", kLengthApart(nums, numsSize, k));

    return 0;
}