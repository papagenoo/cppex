#ifndef MAXSUBARR_H
#define MAXSUBARR_H

template <class S, class V>
struct FindMaxSubArrResult {
    S low;
    S high;
    V sum;
};

template<class Container>
FindMaxSubArrResult<typename Container::size_type, typename Container::value_type> find_max_sub_arr(const Container& container,
                                               typename Container::size_type low,
                                               typename Container::size_type mid,
                                               typename Container::size_type high);

void find_max_sub_arr_test();

#endif // MAXSUBARR_H
