#include <vector>

using namespace std;

#ifndef QUICKMERGE_H
#define QUICKMERGE_H

class QuickMerge
{
public:
    QuickMerge(int N);
    bool connected(int p, int q);
    void unite(int p, int q);
private:
    vector<int> id;
    vector<int> sz;
    int root(int i);
};

#endif // QUICKMERGE_H
