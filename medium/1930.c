int countPalindromicSubsequence(char* s) {
    int length = strlen(s);
    int letters[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int letters_out[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int count = 0;

    for(int i = 0; i < length; i++){
        letters[s[i] - 97] = 1;
    }

    for(int i = 0; i < 26; i++){
        if(!letters[i])
            continue;
        int j;
        for(j = 0; j < length; j++){
            if(s[j] == i + 'a')
                break;
        }

        int k;
        for(k = length - 1; k >= 0; k--){
            if(s[k] == i + 'a')
                break;
        }

        if(!(j + 1 < k))
            continue;

        int letters_in[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        
        for(int l = j+1; l < k; l++) {
                if(letters_in[s[l] - 97])
                    continue;
                letters_in[s[l] - 97] = 1;
                
                count++;

        }
    }


    return count;
}