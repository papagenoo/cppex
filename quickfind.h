#include <vector>

using namespace std;

#ifndef QUICKFIND_H
#define QUICKFIND_H

class QuickFind
{
private:
    vector<int> id;

public:
    QuickFind(int N);
    bool connected(int p, int q);
    void unite(int p, int q);
};

#endif // QUICKFIND_H
