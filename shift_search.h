#ifndef SHIFT_SEARCH_H
#define SHIFT_SEARCH_H

#include <vector>

using namespace std;

// Поиск в массиве без сдвига
int binary_search(const vector<int>& vec, int p, int q, int f);
// Поиск в массиве со сдвигом
int shift_search(const vector<int>& vec, int p, int q, int f);
// Запуск тектовой программы
int shift_search_test();

#endif // SHIFT_SEARCH_H
