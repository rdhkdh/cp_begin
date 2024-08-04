#include<bits/stdc++.h>
using namespace std;

// Function to get the pattern of counts of '0's and '1's in the string
vector<pair<char, int>> getPattern(const string& Z) {
    vector<pair<char, int>> pattern;
    char currentChar = Z[0];
    int count = 1;

    for (size_t i = 1; i < Z.size(); ++i) {
        if (Z[i] == currentChar) {
            count++;
        } else {
            pattern.emplace_back(currentChar, count);
            currentChar = Z[i];
            count = 1;
        }
    }

    // Add the last segment
    pattern.emplace_back(currentChar, count);

    return pattern;
}

// Function to determine if there exists a string T such that f(S, T, X) = f(S, T, Y)
bool isPossible(const string& S, const string& X, const string& Y) {
    vector<pair<char, int>> patternX = getPattern(X);
    vector<pair<char, int>> patternY = getPattern(Y);

    // Check if patterns are of the same length
    if (patternX.size() != patternY.size()) {
        return false;
    }

    // Compare the patterns
    for (size_t i = 0; i < patternX.size(); ++i) {
        if (patternX[i].first != patternY[i].first) {
            return false;
        }

        // If the current segment is '0', ensure both have the same count
        if (patternX[i].first == '0' && patternX[i].second != patternY[i].second) {
            return false;
        }
    }

    // Patterns match with respect to the conditions
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string S,X,Y;
        cin>>S>>X>>Y;

        if(S=="empty")
        {
            cout<<"Yes"<<endl;
            continue;
        }

        if (isPossible(S, X, Y)) 
        {
            cout << "Yes" << endl;
        } 
        else 
        {
            cout << "No" << endl;
        }

    }   
}
