#include <bits/stdc++.h>
using namespace std;

string extractLayer(const vector<vector<char>>& matrix, int layerNum) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    string layer;

    // Top edge of the layer
    for (int j = layerNum; j < m - layerNum; ++j) {
        layer += matrix[layerNum][j];
    }
    // Right edge of the layer
    for (int i = layerNum + 1; i < n - layerNum; ++i) {
        layer += matrix[i][m - layerNum - 1];
    }
    // Bottom edge of the layer
    for (int j = m - layerNum - 2; j >= layerNum; --j) {
        layer += matrix[n - layerNum - 1][j];
    }
    // Left edge of the layer
    for (int i = n - layerNum - 2; i > layerNum; --i) {
        layer += matrix[i][layerNum];
    }

    return layer;
}

int countOccurrencesOf1543(const vector<vector<char>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    string target = "1543";
    int totalCount = 0;

    int numLayers = min(n, m) / 2;

    for (int layerNum = 0; layerNum < numLayers; ++layerNum) 
    {
        string layerString = extractLayer(matrix, layerNum);

        int l = layerString.length();
        for(int i=0;i<l;i++)
        {
            string temp="";
            temp += layerString[i%l];
            temp += layerString[(i+1)%l];
            temp += layerString[(i+2)%l];
            temp += layerString[(i+3)%l];

            if(temp==target) {totalCount++;}
        }
    }

    return totalCount;
}

int main() 
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<char>> matrix(n, vector<char>(m));
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {                
                matrix[i][j] = s[j];
            }
        }

        int result = countOccurrencesOf1543(matrix);
        cout << result << endl;
    }
}
