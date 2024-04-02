#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

class SegmentTree
{
public:
    vector<int> m_tree;
    int m_n;

    SegmentTree(vector<int> x)
    {
        int n = x.size();
        m_n = n;
        m_tree.resize(2 * n);

        for (int i = 0; i < n; i++)
        {
            m_tree[n + i] = x[i];
        }

        for (int i = n - 1; i > 0; i--)
        {
            m_tree[i] = m_tree[i * 2] + m_tree[i * 2 + 1];
            ;
        }

        m_tree[0] = -1;
    }

    int sum(int a, int b)
    {
        int n = m_tree.size() / 2;
        a += n;
        b += n;
        int s = 0;
        while (a <= b)
        {
            if (a % 2 == 1)
                s += m_tree[a++];
            if (b % 2 == 0)
                s += m_tree[b--];
            a /= 2;
            b /= 2;
        }
        return s;
    }

    void add(int i, int x)
    {
        int a = i + m_n;
        while (a > 0)
        {
            m_tree[a] += x;
            a /= 2;
        }
    }

    void print()
    {
        for (int i = 0; i < m_tree.size(); i++)
        {
            cout << m_tree[i] << ' ';
        }
        cout << '\n';
    }
};

int main()
{

    SegmentTree s = SegmentTree(vector<int>{5, 8, 6, 3, 2, 7, 2, 6});

    cout << s.sum(0, 5) << '\n';

    s.print();

    s.add(2, 2);

    s.print();

    cout << add(1, 2) << '\n';
}

/*
trace for sum(0,1)


*/