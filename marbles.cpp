#include <bits/stdc++.h>
using namespace std;

std::vector<int> max_instances(const std::vector<int>& arr) {

    // Step 1: Count the frequency of each unique element
    map<int, int> freq_;
    for (int num : arr) {
        freq_counter[num]++;
    }

    // Step 2: Sort unique elements in decreasing order based on their frequencies
    std::vector<int> unique_elements;
    for (const auto& pair : freq_counter) {
        unique_elements.push_back(pair.first);
    }
    std::sort(unique_elements.begin(), unique_elements.end(), 
    [&](int a, int b) { return freq_counter[a] > freq_counter[b]; });

    // Step 3: Iterate through the sorted unique elements
    std::vector<int> result;
    for (int element : unique_elements) {
        int count = freq_counter[element];
        while (count > 0) {
            result.push_back(element);
            freq_counter[element]--;
            count--;
        }
    }

    return result;
}

int main() 
{
    map<int,int> freq;
    vector<int> v = {200,200,300,300};
    set<int> numbers;

    for(int i=0;i<v.size();i++)
    {
        freq[v[i]]++;
        numbers.insert(v[i]);
    }

    for(auto)


    return 0;
}
