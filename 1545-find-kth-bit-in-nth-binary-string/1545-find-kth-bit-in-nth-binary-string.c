char findKthBit(int n, int k) {
    // Trường hợp cơ sở: Nếu n = 1, chuỗi chỉ là "0"
    if (n == 1) {
        return '0';
    }
    
    // Tính độ dài của chuỗi ở bước n (thực tế chúng ta chỉ cần tìm điểm giữa)
    // Điểm giữa của chuỗi S_n nằm ở vị trí 2^(n-1)
    int mid = 1 << (n - 1);
    
    // Nếu k nằm đúng ngay điểm giữa, bit đó luôn luôn là '1' (theo quy luật S_i = S_{i-1} + "1" + ...)
    if (k == mid) {
        return '1';
    } 
    // Nếu k nằm ở nửa đầu, bit này hoàn toàn giống với bit thứ k trong S_{n-1}
    else if (k < mid) {
        return findKthBit(n - 1, k);
    } 
    // Nếu k nằm ở nửa sau, nó là vị trí đối xứng của S_{n-1}, nhưng bị đảo ngược (invert)
    else {
        // Vị trí đối xứng của k trong nửa đầu là (độ dài chuỗi S_n + 1) - k
        // Độ dài của S_n là (2^n - 1), nên vị trí đối xứng là (2^n) - k
        int lengthOfSn_plus_1 = 1 << n;
        char mirroredBit = findKthBit(n - 1, lengthOfSn_plus_1 - k);
        
        // Trả về bit đã được đảo ngược (0 thành 1, 1 thành 0)
        return mirroredBit == '0' ? '1' : '0';
    }
}