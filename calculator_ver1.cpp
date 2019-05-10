#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";


class Token{
    public:
        char kind;      //if it's 8, double has a value
        double value;
    };

vector <Token> tokens;

class Token_stream{
    public:
        Token get();
        void putback(Token t);
        void ignore(char c);
    private:
        Token buffer;
        bool full{false};
    };


void Token_stream::putback(Token t){
    buffer = t;
    full = true;
    }

Token Token_stream::get(){
    if (full){
        full = false;
        return buffer;
    }
    char ch;
	cin >> ch;
	switch(ch){
    	case print:
    	case quit:
        case '(':
        case ')':
        case '+':
        case '-':
        case '/':
        case '*':
        case '%':
    		return Token{ch};
    	case '.':
    	case '0':
    	case '1':
    	case '2':
    	case '3':
    	case '4':
    	case '5':
    	case '6':
    	case '7':
    	case '8':
    	case '9':
    		cin.putback(ch);
    		double val;
    		cin >> val;
    		return Token{number, val};
        default:
            return Token{'i', double(ch)};
	}
    return Token{quit};
}


void Token_stream::ignore(char c)
    // c is token kind to look for
{
    // first check buffer:
    if(full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while(cin >> ch)
        if(ch == c) return;
}


Token_stream ts;


double expression();
double term();
double primary();
void calculate();


double expression(){
    double left = term();
    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double term(){
    double left = primary();
    Token t = ts.get();

    while(true) {
        switch (t.kind) {
        case '*':
        {
            left *= primary();
            t = ts.get();
            break;
        }
        case '/':
        {
            double term = primary();
            if (term == 0)
                error("divide by zero");
            left /= term;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
        {
            ts.putback(t);
            return left;
        }
        }
    }
}
double primary(){
	Token t = ts.get();
    switch (t.kind) {
    case number:
        return t.value;
    case '-':
        return -primary();
    case '+':
        return primary();
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case 'q':
        cout << t.value;
        exit(0);
    default:
        cout << "primary expected";
        exit(0);
    }
    return 0;
}

//int main(){
//    Token t = ts.get();
//    while(t.kind != 'q'){
//        cout << "kind " << t.kind << " and value " << t.value << "\n";
//        t = ts.get();
//    }
//}

void print_token(Token t){
cout << "token: " << t.kind
				<< " with val of " << t.value << '\n';
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while(t.kind == print) t = ts.get();
            if(t.kind == quit){
                cout << "Thank you for using the calculator! Have a great day\n";
                return;
            }
            ts.putback(t);
            cout << result << expression() << '\n';
        }
        catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }

}


int main(){
    cout << "This calculator is able to process operations +, -, *, /, %, ()\n";
    cout << "Type ';' to return the calculated value and 'q' to exit the program\n";
    calculate();
    return 0;
}