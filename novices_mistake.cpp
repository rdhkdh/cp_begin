#include <iostream>
#include <string>
using namespace std;

// Function to calculate the correct number of apples left
int calculateCorrectAnswer(int n, int a, int b) {
    return n * a - b;
}

// Function to calculate K1o0n's result by treating n as a string
string k1o0nResult(string n, int a, int b) {
    string s = "";
    for (int i = 0; i < a; ++i) {
        s += n;
    }
    if (b >= s.length()) {
        return "";
    } else {
        return s.substr(0, s.length() - b);
    }
}

int main() {
    int n;
    cin >> n;
    string n_str = to_string(n);
    int count = 0;

    for (int a = 1; a <= 10000; ++a) {
        for (int b = 1; b <= min(10000, n * a); ++b) {
            int correct_answer = calculateCorrectAnswer(n, a, b);
            string k1o0n_res = k1o0nResult(n_str, a, b);

            if (!k1o0n_res.empty() && stoi(k1o0n_res) == correct_answer) {
                ++count;
            }
        }
    }

    cout <<count << endl;

    return 0;
}
