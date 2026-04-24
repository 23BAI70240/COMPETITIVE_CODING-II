#include <bits/stdc++.h>
using namespace std;

vector<string> words;
int idx;
string result;
bool error;

void parse() {
    if (idx >= (int)words.size()) {
        error = true;
        return;
    }
    string w = words[idx++];
    if (w == "int") {
        result += "int";
    } else {
        // pair
        result += "pair<";
        parse();
        result += ",";
        parse();
        result += ">";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    string word;
    while (cin >> word) words.push_back(word);
    
    idx = 0;
    error = false;
    parse();
    
    if (error || idx != (int)words.size()) {
        cout << "Error occurred\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}