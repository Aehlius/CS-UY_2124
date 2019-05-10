#include "std_lib_facilities.h"

int main()
{
    cout << "Enter a sequence of words and its concordance will be outputted:\n";

    vector<string> text;
    for(string word; cin>>word; )
        text.push_back(word);
    sort(text);

    string curr_word;
    string next_word;
    curr_word = text[0];
    string temp;
    int count = 0;
    for(string next_word : text)
        {
        if (curr_word == next_word)
            count++;
        else
            {
            cout << curr_word <<": "<< count <<"\n";
            count = 1;
            }
        temp = next_word;
        next_word = curr_word;
        curr_word = temp;
        }
    cout << curr_word<<"; " << count<< "\n";

    return 0;
}
