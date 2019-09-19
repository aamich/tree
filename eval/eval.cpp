#include <iostream>
#include <string>

using namespace std;

int eval(const string& expr) {
    string tok;
    for(int i=0; i < expr.size(); ++i) {
        if(expr[i] != ' ')
            tok += expr[i];
    }
    for(int i=0; i < tok.size(); ++i) {
        if(tok[i] == '+')
            return eval(tok.substr(0, i)) + eval(tok.substr(i+1, tok.size()-i-1));
        else if(tok[i] == '-')
            return eval(tok.substr(0, i)) - eval(tok.substr(i+1, tok.size()-i-1));
    }
    for(int i=0; i < tok.size(); ++i) {
        if(tok[i] == '*')
            return eval(tok.substr(0, i)) * eval(tok.substr(i+1, tok.size()-i-1));
        else if(tok[i] == '/')
            return (float)eval(tok.substr(0, i)) / (float)eval(tok.substr(i+1, tok.size()-i-1));
    }
    return stoi(tok);
}

int main() {
    string input="3*4+5*6*7";
    cout << input << "=" << eval(input) << endl;
    string input2="3*4/3+5*6*7/7";
    cout << input2 << "=" << eval(input2) << endl;
    // can't calculate "5*6*7/6/7", how to fix?
    string input3="5*6*7/7/6";
    cout << input3 << "=" << eval(input3) << endl;
}
