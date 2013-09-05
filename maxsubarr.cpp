#include <iostream>
#include <vector>

#include "maxsubarr.h"

using namespace std;

// Find
template<class Container>
FindMaxSubArrResult<typename Container::size_type, typename Container::value_type>
find_max_crossing_sub_arr(const Container& container,
                 typename Container::size_type low,
                 typename Container::size_type mid,
                 typename Container::size_type high)
{
    typedef typename Container::value_type V;
    typedef typename Container::size_type S;
    FindMaxSubArrResult<S, V> res;
    res.low = low;
    res.high = high;
    res.sum = low + high;
    return res;
}

//void find_max_sub_arr() {
//
//}

void find_max_sub_arr_test()
{
    vector<int> v = { -1, 2, 4, 7, -10 };
    auto res = find_max_sub_arr(v, 0, 2, 4);
    cout << res.low << ", " << res.high << ", " << res.sum << endl;
}
