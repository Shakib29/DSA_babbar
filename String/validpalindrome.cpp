#include <iostream>
#include <cctype> // for tolower()
#include <string> // for std::string
using namespace std;

bool checkalpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

bool palindrome(string str) {
    string temp = "";
    
    // Remove non-alphanumeric characters and convert to lowercase
    for (int j = 0; j < str.length(); j++) {
        if (checkalpha(str[j])) {
            temp.push_back(tolower(str[j]));
        }
    }

    // Check if the filtered string is a palindrome
    int s = 0;
    int e = temp.length() - 1;
    while (s <= e) {
        if (temp[s] != temp[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a String :" << endl;
    getline(cin, str); // Use getline to allow spaces and special characters

    if (palindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}


