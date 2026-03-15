#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    long long *arr;
    int size;
    int capacity;
    long long a;
    long long b;
} Fancy;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));
    obj->capacity = 100000;
    obj->arr = (long long*)malloc(sizeof(long long) * obj->capacity);
    obj->size = 0;
    obj->a = 1;
    obj->b = 0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (long long*)realloc(obj->arr, sizeof(long long) * obj->capacity);
    }

    long long val_diff = (val - obj->b) % MOD;
    if (val_diff < 0) val_diff += MOD;
    
    long long x = (val_diff * modInverse(obj->a)) % MOD;
    obj->arr[obj->size++] = x;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->b = (obj->b + inc) % MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->a = (obj->a * m) % MOD;
    obj->b = (obj->b * m) % MOD;
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx < 0 || idx >= obj->size) return -1;
    long long res = (obj->a * obj->arr[idx] + obj->b) % MOD;
    return (int)res;
}

void fancyFree(Fancy* obj) {
    free(obj->arr);
    free(obj);
}