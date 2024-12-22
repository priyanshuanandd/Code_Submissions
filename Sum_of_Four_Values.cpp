#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to generate the first k terms of sequence with offset x
vector<int> generateSequence(int x, int k) {
    vector<int> sequence;
    for (int n = 1; n <= k; ++n) {
        sequence.push_back(n ^ x);
    }
    return sequence;
}

// Function to find common elements between two sequences
vector<int> findCommonSegment(const vector<int>& seq1, const vector<int>& seq2) {
    unordered_set<int> set1(seq1.begin(), seq1.end());
    vector<int> commonSegment;
    
    for (const int& num : seq2) {
        if (set1.find(num) != set1.end()) {
            commonSegment.push_back(num);
        }
    }
    return commonSegment;
}

int main() {
    
}
