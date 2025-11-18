#include <iostream>
#include <string>

using namespace std;

bool palindrome(string word)
{
    cout << word[0] << " " << word[word.length() - 1] << endl; //for testing what is being compared
    if (word.length() < 1)
    {
        return true;
    }
    else
    {
        if(tolower(word[0]) != tolower(word[word.length()-1])) //if 1st letter doesn't equal the last
        {
            return false;
        }
        else //otherwise, iterate again for the next set of words!!!
        {
            return palindrome(word.substr(1, word.length() - 2));
        }
    }
}

int main()
{
    string w1 = "tacocat";
    string w2 = "hello";

    cout << boolalpha; //forces to print true/false!

    cout << palindrome(w1) << endl;
    cout << palindrome(w2) << endl;
}