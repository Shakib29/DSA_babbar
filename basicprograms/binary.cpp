#include <iostream>
using namespace std;

class of {
public:
    int cal(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n & 1) {  // Check if the least significant bit is 1
                count++;
            }
            n = n >> 1; // Right shift the number by 1 bit
        }
        return count;
    }
};

int main() {
    of obj;
    uint32_t n;
    cout << "Enter a number: ";
    cin >> n;
    int result = obj.cal(n);
    cout << "Number of 1 bits: " << result << endl;
    return 0;
}
