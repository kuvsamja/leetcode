int findFinalValue(int* nums, int numsSize, int original) {
    int searching = 1;
    int found = 0;

    start: while(searching){
        for(int i = 0; i < numsSize; i++){
            if(nums[i] == original){
                found++;
                original *= 2;
                goto start;

            }
        }

        searching = 0;
    }

    return original;

}


int main(){
    int nums[] = {1, 2, 3, 3}


}