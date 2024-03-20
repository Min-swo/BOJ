#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int cnt[26];
    for(int i = 0; i < 26; i++)
        cnt[i] = 0;

    string word;
    getline(cin, word);
 
    for(int i = 0; i < word.length(); i++)
        cnt[word[i] - 97]++;

    for(int i = 0; i < 26; i++)
        cout << cnt[i] << " ";
    cout << "\n";
}