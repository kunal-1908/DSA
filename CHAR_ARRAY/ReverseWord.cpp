#include<iostream>
using namespace std;

// Function to reverse individual words in the string
void reverseWords(string &s, int n) {
    int i = 0; // Start index of the word

    while (i < n) {
        int start = i; // Mark the start of a word

        // Move 'i' to the end of the word (until space or end of string)
        while (i < n && s[i] != ' ') {
            i++;
        }

        // Reverse the current word from 'start' to 'i-1'
        int end = i - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }

        // Move 'i' to the next word (skip the space)
        i++;
    }
}

int main() {
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);

    // Get the length of the string and reverse each word
    int length = s.length();
    reverseWords(s, length);

    cout << "Reversed words string: " << s << endl;

    return 0;
}
