#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

    // colors_map = defaultdict(int)
    // for item in b:
    //     colors_map[item] += 1

    // vacants_num = colors_map.get("_", 0)
    // if vacants_num != 0:
    //     colors_map.pop("_")

    // for color, occurrence in colors_map.items():
    //     if occurrence == 1:
    //         return "NO"

    // if vacants_num == 0:
    //     for i in range(1, n - 2):
    //         if b[i] != b[i - 1] and b[i] != b[i + 1]:
    //             return "NO"

    // return "YES"

string happyLadybugs(string b) {
    map<char, int> colors_map;
    for (auto ch: b) {
        if(colors_map.find(ch) != colors_map.end())
            colors_map[ch]++;
        else
            colors_map[ch] = 1;
    }
    int vacants_num = 0;
    if(colors_map.find('_') != colors_map.end()) {
        vacants_num = colors_map['_'];
        colors_map.erase('_');
    }

    for (auto p: colors_map)
        if(p.second == 1)
            return "NO";

    if (vacants_num == 0)
        for (int i = 1; i < b.size() - 2; i++)
            if (b[i] != b[i - 1] && b[i] != b[i + 1])
                return "NO";

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
