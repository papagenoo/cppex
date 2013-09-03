#include <iostream>
#include "quickmerge.h"

QuickMerge::QuickMerge(int N)
{
    id.resize(N);
    sz.resize(N);
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}

bool QuickMerge::connected(int p, int q)
{
    return root(p) == root(q);
}

void QuickMerge::unite(int p, int q)
{
    int i = root(p);
    int j = root(q);
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int QuickMerge::root(int i)
{
    while (i != id[i]) i = id[i];
    return i;
}
