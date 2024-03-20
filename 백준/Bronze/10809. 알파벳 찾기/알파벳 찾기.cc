#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int pos[26];
    for(int i = 0; i < 26; i++)
        pos[i] = -1;

    string word;
    getline(cin, word);

    for(int i = 0; i < word.length(); i++)
    {
        if(pos[word[i] - 97] == -1)
            pos[word[i] - 97] = i;
    }

    for(int i = 0; i < 26; i++)
        cout << pos[i] << " ";
    cout << "\n"; 
}