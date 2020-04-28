#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(string pat) {
    vector<int> lps (pat.size());
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        }
        else {
            if (len) {
                len = lps[len-1];
            }
            else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

void KMPsearch(string str, string pat) {
    if (!str.size() || !pat.size()) { return; }
    vector<int> lps { computeLPS(pat) };
    int i = 0, j = 0;
    while (i < str.size()) {
        if (str[i] == pat[j]) {
            ++i;
            ++j;
            if (j == pat.size()) {
                cout << "Found pattern at index " << i-j << endl;
                j = lps[j-1];
            }
        }
        else {
            if (j) {
                j = lps[j-1];
            }
            else {
                ++i;
            }
        }
    }
}

int main() {
    string str;
    string pat;
    cout << "KMP algorithm: search occurences of a pattern in a string in O(n) time" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "string:" << endl;
    cin >> str;
    cout << "pattern:" << endl;
    cin >> pat;
    KMPsearch(str, pat);
    return 0;
}

