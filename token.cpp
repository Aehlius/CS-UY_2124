#include "std_lib_facilities.h"

class Token
    {
    public:
        char kind;      //if it's 8, double has a value
        double value;
    };

Token get_token();
vector <Token> tokens;


int main()
{
    Token t = get_token();
    while (t.kind != 'q')
        {
        tokens.push_back(t);
        t = get_token();
        }
    cout << "The following expression has been inputted: \n";
    for (Token tok: tokens)
        {
        if (tok.kind == '8')
            cout << "token is a numeric of value " << tok.value;
        else
            cout << "token is non-numeric of type " << tok.kind;
        }
    cout << "\n\n";
}

Token get_token()
    {
        char ch;
        cin >> ch;
        switch(ch)
            {

            case 'q' : case '(' : case ')' : case '+' : case '-' : case '*' : case '/' : case '%':
                return Token{ch};
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
            {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{'8', val};
            }
            }
    };