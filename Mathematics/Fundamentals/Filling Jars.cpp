#include <bits/stdc++.h>
#include <math.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY operations
 */

unsigned long long solve(int n, vector<vector<unsigned long long>> operations) {
    unsigned long long sum = 0;
    for (auto op: operations)
        sum += op[2] * (1 + op[1] - op[0]);
    
    return floor(sum / (n * 1.));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<unsigned long long>> operations(m);

    for (int i = 0; i < m; i++) {
        operations[i].resize(3);

        string operations_row_temp_temp;
        getline(cin, operations_row_temp_temp);

        vector<string> operations_row_temp = split(rtrim(operations_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int operations_row_item = stoi(operations_row_temp[j]);

            operations[i][j] = operations_row_item;
        }
    }

    unsigned long long result = solve(n, operations);

    fout << result << "\n";

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
