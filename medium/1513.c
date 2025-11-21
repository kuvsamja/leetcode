#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numSub(char* s) {
    int length = strlen(s);
    long long mod = 1000000007;
    long long num = 0;
    long long count = 0;
    for(int i = 0; i <= length; i++){
        if(s[i] == '1'){
            num++;
        } else if(s[i] == '0' || i == length){
            count += (num * (num + 1) / 2) % mod;
            num = 0;
        }
    }
    count %= mod;
    return count;

}