struct KMP {
    void buildNextArray(const char* pattern, int* nextArray, size_t len) {
        nextArray[0] = -1;
        if(len > 2) {
            for(int i = 2; i < len; i++) {
                if(pattern[i - 1] == pattern[nextArray[i - 1]]) nextArray[i] = nextArray[i - 1] + 1;
                else if(pattern[i - 1] == pattern[0])   nextArray[i] = 1;
            }
        }
    }
    int search(const char* text, int tLen, const char* pattern, int pLen) {
        int next[pLen] = {0};
        int i = 0, j = 0;
        buildNextArray(pattern, next, pLen);
        while(i < tLen && j < pLen) {
            if(j == -1 || text[i] == pattern[j]) {
                i++, j++;
            }else {
                j = next[j];
            }
        }
        if(j == pLen)   return i - j;
        else    return -1;
    }
};