#include "quickfind.h"

QuickFind::QuickFind(int N)
{
    id.resize(N);
    for (int i = 0; i < N; ++i)
        id[i] = i;
}

bool QuickFind::connected(int p, int q)
{
    return id[p] == id[q];
}

void QuickFind::unite(int p, int q)
{
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < id.size(); ++i) {
        if (id[i] == pid) id[i] = qid;
    }
}
