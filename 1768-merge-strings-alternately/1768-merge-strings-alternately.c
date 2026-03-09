

char * mergeAlternately(char * word1, char * word2){
    long a = strlen(word1);
    long b = strlen(word2);
    long hieu = a-b;
    char * res = (char*) malloc((a+b+2) * sizeof(char));
    int i = 0, j = 0, k = 0;
    if (hieu >= 0) {
        while (j < a) {
            res[i] = word1[j];
            i++;
            j++;
            if (k == b) continue;
            res[i] = word2[k];
            i++;
            k++;
        }
    }
    if (hieu < 0) {
        while (k < b) {
            res[i] = word1[j];
            i++;
            j++;
            res[i] = word2[k];
            i++;
            k++;
            if (j == a) {
                break;
            }
        }
        while (k < b) {
            res[i] = word2[k];
            i++;
            k++;
        }
    }
    res[i] = '\0';
    return res;
    free(res);
}