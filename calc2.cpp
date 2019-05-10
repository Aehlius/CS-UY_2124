

int main()
    {
    int lval;
    int rval;
    char op;
    int res;
    for (char; op; cin>>op)
        {
        if (op!='x')
            cin >> rval;
        if (!cin)
            error("empty");
        cin >> lval >> op >> rval;
        switch(op)
            {
            case '+':
                lval = lval + rval;
                break;
            case '-':
                lval = lval - rval;
                break;
            case '*':
                lval = lval * rval;
                break;
            case '/':
                lval = lval / rval;
                break;
            default:
                cout << lval;
            }
        }
    cout << res << "\n";

    }