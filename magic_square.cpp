#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int formingMagicSquare(vector<vector<int>> s) {
    int arr0[9] =   {4,9,2,3,5,7,8,1,6};
    int arr1[9] =   {2,7,6,9,5,1,4,3,8};
    int arr2[9] =   {6,1,8,7,5,3,2,9,4};
    int arr3[9] =   {2,9,4,7,5,3,6,1,8};
    int arr4[9] =   {6,7,2,1,5,9,8,3,4};
    int arr5[9] =   {8,1,6,3,5,7,4,9,2};
    int arr6[9] =   {8,3,4,1,5,9,6,7,2};
    int arr7[9] =   {4,3,8,9,5,1,2,7,6};
    int len = s.size();
    int ans[8] = {0}; 
    for (int i=0; i<len; i++)
    {
        for(int j=0; j<s[i].size(); j++)
        {
            int k = s[i][j];
            
            ans[0] += abs(k - arr0[((i*3)+j)]);
            ans[1] += abs(k - arr1[((i*3)+j)]);
            ans[2] += abs(k - arr2[((i*3)+j)]);
            ans[3] += abs(k - arr3[((i*3)+j)]);
            ans[4] += abs(k - arr4[((i*3)+j)]);
            ans[5] += abs(k - arr5[((i*3)+j)]);
            ans[6] += abs(k - arr7[((i*3)+j)]);
            ans[7] += abs(k - arr6[((i*3)+j)]);

        }
    }
    int min =ans[0];
    for(int i=0;i<8;i++)
        if(ans[i]<min)
            min = ans[i];
    return min;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
