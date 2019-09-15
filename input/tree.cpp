#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <assert.h>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

void readTree(const string& input, Node* root) {
    std::regex nodeLine (R"(^(\d+)\:\s+(\d+)\s+(\d+)$)");
    ifstream in;
    in.open(input, ios::in);
    string line;
    if(in.is_open()) {
        while(getline(in, line)) {
            cout << line << endl;
            std::smatch m;
            if(std::regex_search(line, m, nodeLine)) {
                //cout << "m.size=" << m.size() << endl;
                assert(4 == m.size() || 3 == m.size());
                cout << m[1] << " " << m[2];
                if(4 == m.size())
                    cout << " " << m[3];
                cout << endl;
            }
        }
        in.close();
    }
}

int main() {
    Node* root = new Node();
    readTree("input.txt", root);
}

