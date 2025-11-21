#include <stdio.h>
#include <stdlib.h>

int isInArray(int num, int* arr, int arr_size){
    for(int i = 0; i < arr_size; i++){
        if(arr[i] == num){
            return 1;
        }
    }
    return 0;
}

int* getIntervalArr(int* interval, int interval_size){
    // int interval_size = (interval[1] - interval[0] + 1);
    int* interval_arr = malloc(interval_size * sizeof(int));
    for(int i = interval[0]; i <= interval[1]; i++){
        interval_arr[i - interval[0]] = i;
    }
    return interval_arr;
}

int cmp(const void* a, const void* b){
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[1] - intervalB[1];
}

void sortBySecond(int** intervals_unsorted, int intervals_size){
    qsort(intervals_unsorted, intervals_size, sizeof(int*), cmp);
    
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    int containig_set_size = 100;
    int* containing_set = malloc(containig_set_size * sizeof(int));
    int current_element = 0;
    int repeats = 0;
    int overlap;
    sortBySecond(intervals, intervalsSize);
    for(int i = 0; i < intervalsSize; i++){
        if(current_element >= containig_set_size){
            containig_set_size *= 2;
            containing_set = realloc(containing_set, containig_set_size * sizeof(int));
        }

        repeats = 0;
        int* interval = intervals[i];

        int interval_size = (interval[1] - interval[0] + 1);
        overlap = 0;

        for(int j = 0; j < current_element; j++){
            if(interval[0] <= containing_set[j] && containing_set[j] <= interval[1]){
                overlap++;
            }
        }

        if(overlap == 0){
            int picked = 0;
            int count = 0;
            
            while(!picked){
                if(!isInArray(interval[1] - count, containing_set, current_element)){
                    containing_set[current_element] = interval[1] - count;
                    current_element++;
                    picked = 1;
                }
                count++;
            }

            picked = 0;
            count = 0;

            while(!picked){
                if(!isInArray(interval[1] - count, containing_set, current_element)){
                    containing_set[current_element] = interval[1] - count;
                    current_element++;
                    picked = 1;
                }
                count++;
            }
            // containing_set[current_element] = interval[1] - 1;
            // current_element++;
        }
        if(overlap == 1){
            int picked = 0;
            int count = 0;

            while(!picked){
                if(!isInArray(interval[1] - count, containing_set, current_element)){
                    containing_set[current_element] = interval[1] - count;
                    current_element++;
                    picked = 1;
                }
                count++;
            }
        }

    }

    return current_element;
}
