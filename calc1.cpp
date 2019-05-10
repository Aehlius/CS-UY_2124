#include "std_lib_facilities.h"

int main()
    {
    int lval;
    int rval;
    char op;
    int res;
    cin >> lval >> op >> rval;
    if (op == '+')
        res = lval + rval;
    else if (op == '-')
        res = lval - rval;
    cout << res << "\n";

    }