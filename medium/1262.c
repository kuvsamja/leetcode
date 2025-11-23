




int maxSumDivThree(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int mod = sum % 3;
    int smallest, smallest1, smallest2;
    if(mod == 1) {
        // 1 num % 3 == 1
        smallest = __INT_MAX__;
        for(int i = 0; i < numsSize; i++) {
            if(smallest > nums[i] && nums[i] % 3 == 1) {
                smallest = nums[i];
            }
        }
        // 2 num % 3 == 2
        smallest1 = __INT_MAX__;
        smallest2 = __INT_MAX__;
        for(int i = 0; i < numsSize; i++) {
            if(smallest1 > nums[i] && nums[i] % 3 == 2) {
                smallest2 = smallest1;
                smallest1 = nums[i];
            } else if(nums[i] < smallest2 && nums[i] % 3 == 2)
                smallest2 = nums[i];
        }
    }

    if(mod == 2) {
        // 1 num % 3 == 2
        smallest = __INT_MAX__;
        for(int i = 0; i < numsSize; i++) {
            if(smallest > nums[i] && nums[i] % 3 == 2) {
                smallest = nums[i];
            }
        }
        // 2 num % 3 == 1
        smallest1 = __INT_MAX__;
        smallest2 = __INT_MAX__;
        for(int i = 0; i < numsSize; i++) {
            if(smallest1 > nums[i] && nums[i] % 3 == 1) {
                smallest2 = smallest1;
                smallest1 = nums[i];
            } else if(nums[i] < smallest2 && nums[i] % 3 == 1)
                smallest2 = nums[i];
        }
        
    }

    if(smallest > (long long)smallest1 + smallest2) {
        smallest = smallest1 + smallest2;
    }
    if(mod == 0) {
        smallest = 0;
    }

    return sum - smallest;

}

int main() {

    return 0;
}