#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Поиск в массиве без сдвига
int binary_search(const vector<int>& vec, int p, int q, int f) {
    if (p > q) return -1;
    int mid = floor((p + q) / 2);
    if (vec[mid] == f) return mid;
    if (f <= vec[mid - 1]) return binary_search(vec, p, mid - 1, f);
    if (vec[mid + 1] <= f) return binary_search(vec, mid + 1, q, f);
    return -1;
}

// Поиск в массиве со сдвигом
int shift_search(const vector<int>& vec, int p, int q, int f) {
    if (p > q) return -1;
    int mid = floor((p + q) / 2);
    // Совпадение с центральной точкой
    if (vec[mid] == f)
        return mid;
    // Левый подмассив полностью отсортирован
    if (vec[p] <= vec[mid - 1]) {
        // Ищем в левом отсортированном подмассиве
        if (vec[p] <= f && f <= vec[mid - 1])
            return binary_search(vec, p, mid - 1, f);
        // Ищем в правом неотсортированном подмассиве
        else
            return shift_search(vec, mid + 1, q, f);
    // Правый подмассив полностью отсортирован
    } else {
        // Ищем в правом отсортированном подмассиве
        if (vec[mid + 1] <= f && f <= vec[q])
            return binary_search(vec, mid + 1, q, f);
        // Ищем в левом неотсортированном подмассиве
        else
            return shift_search(vec, p, mid - 1, f);
    }
}

int shift_search_test() {
    vector<int> vec1 = { 1, 2, 3, 4, 5 };
    int pos1 = binary_search(vec1, 0, 8, 3);
    cout << pos1 << endl; // outputs: 2

    vector<int> vec2 = { 6, 7, 8, 9, 1, 2, 3, 4, 5 };
    int pos2 = shift_search(vec2, 0, 8, 8);
    cout << pos2 << endl; // outputs: 2
    return 0;
}
