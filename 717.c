#include <stdio.h>


int isOneBitCharacter(int* bits, int bitsSize) {
    int isOneBit;
    int i = 0;

    while(i < bitsSize) {

        if(bits[i] == 0 && i==bitsSize-1)
            return 1;
        

        if (bits[i] == 1)
            i++;
        
        i++;


    }

    return 0;

}


int main(){
    int bitsSize = 4;
    int bits[] = {1, 0, 0, 0};

    isOneBitCharacter(bits, bitsSize);



}