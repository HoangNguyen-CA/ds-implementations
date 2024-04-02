#include <bits/stdc++.h>

using namespace std;
class SegmentTree
{

private:
    vector<int> m_tree;
    int m_n;

public:
    SegmentTree(vector<int> x)
    {
        int n = x.size();
        m_n = n;

        m_tree.resize(n * 2);

        for (int i = 0; i < n; i++)
        {
            m_tree[i + n] = x[i];
        }

        for (int i = n - 1; i > 0; i--)
        {
            m_tree[i] = min(m_tree[i * 2], m_tree[i * 2 + 1]);
        }
    }

    int query(int a, int b)
    {
        a += m_n;
        b += m_n;

        // init value
        int res = m_tree[a];
        while (a <= b)
        {
            if (a % 2 == 1)
            {
                res = min(res, a);
                a++;
            }

            if (b % 2 == 0)
            {
                res = min(res, b);
                b--;
            }

            a /= 2;
            b /= 2;
        }

        return res;
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

    cout << s.query(5, 6) << '\n';

    s.print();
}