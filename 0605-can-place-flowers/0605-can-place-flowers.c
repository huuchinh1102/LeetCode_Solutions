bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int current_adjacement = 0;
    int flower_possible = 0;
    int a;
    int indexdau = 0;
    int indexcuoi = flowerbedSize-1;
    int cnt = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            cnt++;
        }
    }
    if (cnt == flowerbedSize) flower_possible = (cnt+1)/2;
    else {
        for (indexdau = 0; indexdau < flowerbedSize; indexdau++) {
            if (flowerbed[indexdau] != 0) {
                break;
            }
        }
        for (indexcuoi = flowerbedSize-1; indexcuoi >= 0; indexcuoi--) {
            if (flowerbed[indexcuoi] != 0) {
                break;
            }
        }
        a += indexdau/2;
        a += (flowerbedSize-indexcuoi-1)/2;
        flower_possible += a;
        a = 0;        
    for (int i = indexdau; i <= indexcuoi; i++) {
        if (flowerbed[i] == 0) {
            current_adjacement++;
        }
        else {
            a = (current_adjacement-1)/2;
            current_adjacement = 0;
            flower_possible += a;
        }
        }
    }
        
    if (flower_possible >= n) {
        return true;
    }
    else return false;
}