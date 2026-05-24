#include <stdio.h>

int compress(char* chars, int charsSize) {
    int write_idx = 0;
    
    for (int i = 0; i < charsSize; i++) {
        int cnt = 1;
        
        while (i < charsSize - 1 && chars[i] == chars[i+1]) {
            cnt++;
            i++;
        }
        
        chars[write_idx] = chars[i];
        write_idx++;
        
        if (cnt > 1) {
            char cnt_str[10];
            sprintf(cnt_str, "%d", cnt);

            for (int j = 0; cnt_str[j] != '\0'; j++) {
                chars[write_idx] = cnt_str[j];
                write_idx++;
            }
        }
    }
    
    return write_idx; 
}