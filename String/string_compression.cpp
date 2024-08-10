#include <iostream>
#include <vector>
#include <string>
using namespace std;

void compress(vector<char>& chars) {
    int i = 0;
    int n = chars.size();
    int ansIndex = 0;

    while (i < n) {
        int j = i + 1;
        while (j < n && chars[i] == chars[j]) {
            j++;
        }

        // Store the current character
        chars[ansIndex++] = chars[i];

        // Calculate the count of the current character
        int count = j - i;

        // If count is more than 1, convert it to string and store each digit
        if (count > 1) {
            string cnt = to_string(count);
            for (char ch : cnt) {
                chars[ansIndex++] = ch;
            }
        }

        // Move to the next different character
        i = j;
    }

    // Resize the vector to the new length
    chars.resize(ansIndex);
}

int main() {
    vector<char> chars;
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Convert string to vector of chars
    for (char c : input) {
        chars.push_back(c);
    }

    // Compress the characters
    compress(chars);

    // Print the compressed characters
    cout << "Compressed string: ";
    for (char c : chars) {
        cout << c;
    }
    cout << endl;

    return 0;
}
