//! struct minmaxstack
{
    v64 s, smin = {INT_MAX}, smax = {INT_MIN};

    void push(int a)
    {
        s.push_back(a);
        smax.push_back(::max(smax.back(), a));
        s.push_back(::min(smin.back(), a));
    }

    int pop()
    {
        smax.pop_back();
        smin.pop_back();
        int x = s.back();
        s.pop_back();
        return x;
    }
    int min()
    {
        return smin.back();
    }
    int max()
    {
        return smax.back();
    }
    bool empty()
    {
        return s.empty();
    }
};