/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* arr = malloc(2 * sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        int comp = target - nums[i];
        for(int j = i+1; j < numsSize; j++){
            if(nums[j] == comp) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    return arr;
}


int main(){
    int numsSize = 3;
    int nums[] = {1, 2, 3};
    int target = 5;
    int returnSize = 2 * sizeof(int);


    return 0;
}