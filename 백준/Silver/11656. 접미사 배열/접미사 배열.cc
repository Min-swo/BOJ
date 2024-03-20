#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	return a < b;
}

int main(void)
{
    char word[1001];
    scanf("%s", word);

    int len = 0;
    for(int i = 0; word[i] != '\0'; i++)
        len++;

    string* suffix = new string[len];
    for(int i = 0; i < len; i++)
        suffix[i] = word + i;

    sort(suffix, suffix + len, compare);

    for(int i = 0; i < len; i++)
        cout << suffix[i] << "\n";
}