#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define MAX 100000
#define MAX_STR "100000"

int N, M;
string input;

string originPokemons[MAX + 1];
map<string, int> pokemonMaps[26];

bool isStringDigit(string s) {
    for (int i = 0; i < int(s.size()); i++) {
        if (isdigit(s[i])) {
            return true;
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> originPokemons[i];
        pokemonMaps[originPokemons[i][0] - 65].insert({originPokemons[i], i});
    }

    for (int i = 0; i < M; i++) {
        cin >> input;
        if (isStringDigit(input)) {
            cout << originPokemons[stoi(input)] << "\n";
        } else {
            cout << pokemonMaps[input[0] - 65][input] << "\n";
        }
    }
}