#include <iostream>

int lBinSearchGe (int l, int r, int* seq_, int params)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (seq_[m] >= params)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int lBinSearchGt (int l, int r, int* seq_, int params)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (seq_[m] > params)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int rBinSearchL (int l, int r, int* seq_, int params)
{
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (seq_[m] < params)
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }
    return l;
}


int main ()
{

    int lenSlab;
    int n;
    std::cin >> lenSlab;
    std::cin >> n;
    int* seq = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> seq[i];
    }

    int mid = lenSlab / 2;

    int iter = lBinSearchGe(0, n, seq, mid);

    if (seq[iter] == mid && lenSlab % 2 != 0)
    {
        std::cout << seq[iter];
    }
    else
    {
        int iterL = rBinSearchL(0, n, seq, mid);
        int iterGt = lBinSearchGt(0, n, seq, mid);
        if (iterGt >= n)
        {
            iterGt--;
        }
        for (int i = iterL; i <= iterGt; ++i)
        {
            std::cout << seq[i] << " ";
        }
    }

    return 0;
}
