#include <bits/stdc++.h>
#include <math.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'movingTiles' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER s1
 *  3. INTEGER s2
 *  4. INTEGER_ARRAY queries
 */

vector<long double> movingTiles(int l, int s1, int s2, vector<long int> queries) {

    vector<long double> out;
    int s_dif = abs(s1 - s2);
    for (auto q: queries) {
        long double res = (sqrt(2) * ((long double)l - sqrtl(q))) / s_dif;
        out.push_back(res);
    }

    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int l = stoi(first_multiple_input[0]);

    int s1 = stoi(first_multiple_input[1]);

    int s2 = stoi(first_multiple_input[2]);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<long int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        long int queries_item = stol(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<long double> result = movingTiles(l, s1, s2, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << fixed << setprecision(20) << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
