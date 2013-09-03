#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <math.h>
#include <limits>
#include <functional>
#include <algorithm>

#include "quickfind.h"
#include "quickmerge.h"
#include "shift_search.h"

using namespace std;

// Bubble sort
void bsort(int* arr, int n) {
    void ascending(int*, int*);
    for (auto i = 0; i < n - 1; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            ascending(arr + i, arr + j);
        }
    }
}

// Bubble sort STL
template<typename RandomAccessIterator>
void bsort(RandomAccessIterator begin, RandomAccessIterator end) {
    void ascending(int*, int*);
    for (auto i = begin; i != end; ++i) {
        for (auto j = next(i, 1); j != end; ++j) {
            ascending(&(*i), &(*j));
        }
    }
}

// Swap the variable values by pointers
// in growing order
void ascending(int* l, int* r) {
    if (*l > *r) {
        int t = *l;
        *l = *r;
        *r = t;
    }
}

// Insertion sort acsending
void sort(vector<int>& vec) {
    // Последовательно проходим все элементы последовательности
    // ?????????? j = 0
    for (auto j = 1; j < vec.size(); ++j) {
        // Фиксируем элемент, который нужно вставить в отсортированную подпоследовательность
        int key = vec[j];

        // Спускаемся по отсортированной подпоследовательности (для поиска позиции вставки и смещения вверх элементов со значениями, большими чем вставляемый элемент)
        int i = j - 1;

        // Находим позицию элемента в отсортированной подпоследовательности
        while (0 <= i && key < vec[i]) {
            vec[i + 1] = vec[i];
            --i;
        }

        // Вставляем элемент в найденную позицию в отсортированной подпоследовательности
        vec[i + 1] = key;
    }
}

// Insertion sort decsending
void rsort(vector<int>& vec) {
    for (auto j = 1; j < vec.size(); ++j) {
        int key = vec[j];
        int i = j - 1;

        while (0 <= i && vec[i] < key) {
            vec[i + 1] = vec[i];
            --i;
        }

        vec[i + 1] = key;
    }
}

// Находит в указанном подмассиве совпадение с ожидаемым остатком
// Если совпадение найдено - true, иначе - false
bool findPairDiv(vector<int>& arr, int left, int right, int expect) {
    // Если первый элемент меньше ожидаемого остатка, возвращаем false
    if (expect < arr[left]) return false;
    // Если последний элемент больше ожидаемого остатка, возвращаем false
    if (expect > arr[right - 1]) return false;
    // 1. Находим середину массива
    int middle = floor((left + right)/2);
    // 2. Если средний элемент совпадает с ожидаемым остатком, возвращаем true
    if (arr[middle] == expect) return true;
    // 3. Ищем в первом подмассиве элемент, совпадающий с ожидаемым остатком
    bool res = findPairDiv(arr, left, middle, expect);
    // 4. Если совпадение не найдено в первом подмассиве, ищем во втором
    if (!res) res = findPairDiv(arr, middle, right + 1, expect);
    return res;
}

// Определает, существуют ли в массиве два элемента,
// сумма которых равна указанному числу
bool findPair(vector<int>& arr, int left, int right, int sum) {
    // 1. Сортируем массив
    std::sort(arr.begin() + left, arr.begin() + right);
    // 2. Назначаем текущим левый элемент
    // 3. Сдвигаем левую границу массива на одну позицию вправо (исключаем текущий элемент из поиска)
    // 4. Выясняем, найдена ли пара, дающая сумму, методом "разделяй и властвуй"
    for (int i = left; i < right - 1; ++i) {
        // Будем искать совпадение с остатком от разницы между суммой и текущим элементом
        int expect = sum - arr[i];
        if (findPairDiv(arr, i + 1, right, expect))
            return true;
    }

    return false;
}

void findPairTest() {
    vector<int> vec = { 1, 2, 3, 4, 5, 6 };
    bool found = findPair(vec, 0, vec.size(), 10);
    cout << found << endl;
}

// Selection sort ascending
void ssort(int* A, int n) {
    for (auto i = 0; i < n - 1; ++i) {
        int* min; int* first;
        min = first = A + i;
        for (auto j = i + 1; j < n; ++j) {
            int* c;
            c = A + j;
            if (*c < *min) {
                min = c;
            }
        }

        if (*min < *first) {
            ascending(first, min);
        }
    }
}

// Merge algorithm. Merging two subarrays into one ordered array
void merge(vector<int>::iterator& p, vector<int>::iterator& q, vector<int>::iterator& r) {
    const auto infinity = numeric_limits<int>::max();
    vector<int> L;
    vector<int> R;
    // copy to L from p to q (excluding q!)
    copy(p, q, back_inserter(L));
    // copy to R from q to r (excluding r!)
    copy(q, r, back_inserter(R));
    // add markers (positive infinity) to end of L and R
    L.push_back(infinity);
    R.push_back(infinity);
    // create iterators to begin of L and R
    auto itL = L.begin();
    auto itR = R.begin();
    // merge - copy consequently the smallest elements from L or R
    for (auto k = p; k != r; ++k) {
        if (*itL <= *itR) {
            *k = *itL++;
        } else {
            *k = *itR++;
        }
    }
}

void merge(vector<int>& A, int p, int q, int r) {
    auto begin = A.begin();
    auto pit = begin + p;
    auto qit = begin + q;
    auto rit = begin + r;
    merge(pit, qit, rit);
}

void msort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = floor((p + r)/2);
        cout << ">>> " << p << ", " << q << ", " << r << endl;
        msort(A, p, q);
        msort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void mergeTest() {
    //vector<int> vec = { 7, 8, 4, 6, 1, 9, 3, 5, 2, 0 };
    vector<int> vec = { 5,2,4,7,1,3,2,6,1 };
    //vector<int> vec = { 4, 6, 7, 8,     1,     2, 3, 5, 9, 0 };
    int p = 0;
    int r = vec.size();
    int q = floor((p + r)/2);

    cout << "! " << q << " " << r << endl;

    //merge(vec, p, q, r);
    msort(vec, p, r);

    for (int i : vec) {
        cout << i << endl;
    }
}

template<typename RandomAccessIterator>
void print(RandomAccessIterator begin, RandomAccessIterator end) {
    for (auto it = begin; it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    shift_search_test();
    return 0;

    QuickMerge qmerge(10);
    qmerge.unite(1, 5);
    qmerge.unite(1, 9);
    cout << qmerge.connected(1, 2) << ", " << qmerge.connected(5, 9) << endl;
    return 0;

    QuickFind qfind(10);
    qfind.unite(1, 5);
    qfind.unite(1, 9);

    cout << qfind.connected(1, 2) << ", " << qfind.connected(5, 9) << endl;
    return 0;

    findPairTest();
    return 0;

    vector<int> v = { 8, 3, 5 };
    print(v.begin(), v.end());
    bsort(v.begin(), v.end());
    print(v.begin(), v.end());
    return 0;

    mergeTest();
    return 0;

    //int vec[] { 7, 8, 4, 6 };
    //ssort(vec, 4);

    //bsort(vec.begin(), vec.end());
    //for (int i : vec) {
     //   cout << i << endl;
    //}

    return 0;
    int arr[] { 7, 8, 4, 6 };

    bsort(arr, 4);

    for (int i : arr) {
        cout << i << endl;
    }

    return 0;

    list<int> lst { 1, 2, 3 };

    for (int item : lst) {
        cout << item << endl;
    }
    
    return 0;
}
