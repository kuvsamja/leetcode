#include <stdlib.h>
#include <stdbool.h>

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    int cur = nums[0];
    bool* v = malloc(numsSize * sizeof(bool));
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++){
        v[i] = cur%5==0;
        if(i!=numsSize-1) cur = (cur*2 + nums[i+1])%5;
    }

    return v;
}