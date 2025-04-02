
// Dependencies for Naive Solution - 127 ms runtime, 9.8 MB memory used on test cases.
// Smart solution - 0 ms runtime, 8.5 MB memory used on test cases.


// Run via: g++ LeetCode/9.Palindrome_Number.cpp -o main.exe, if in "LeetCode" folder.

#include <sstream>
#include <string.h>
#include <iostream>

using namespace std; 

class Solution {
public:
    bool Naive_isPalindrome(int x);
    bool Smart_isPalindomre(int x);

};

bool Solution::Naive_isPalindrome(int x) {
        // String to int video
        string palindrome;
        stringstream ss;
        bool val = true;

        ss << x;
        ss >> palindrome;
        
        int len = palindrome.length();
        string reversed = palindrome;

        for (int i = 0; i < len; i++) {
            char temp = palindrome[i];
            reversed[len - i - 1] = temp;
        }

        cout << "Normal: " << palindrome << " " << " Reversed: " << reversed << endl;
        int count = 0;

        for (int i = 0; i < len; i++) {
            if (palindrome[i] == reversed[i]) {
                count++;
            }
        }

        cout << "Number of matches: " << count << " Length of number: " << len << endl;

        if (count == len) {
            return true;
        }
        else {
            return false;
        }
    }

bool Solution::Smart_isPalindomre(int x) {
    // Instead of using properties of strings, we can use properties of ints to solve this
    // When dividing by 10 in a loop, 152 becomes 15, which then becomes 1.
    // At each iteration (152, 15, 1), we take the modulo of 10 for this number, which returns (2, 5, 1) for this case.
    // Note 1 5 2 and 2 5 1 are reversed, showing this line of logic efficiently reverses integers

    // negative cases always false due to '-' sign.
    if (x < 0) {
        return false;
    }

    int reversed = 0;
    int xcopy = x;

    while (xcopy > 0) {
        // ex 152:
        // 1. 2
        // 2. 20 + 5
        // 3. 250 + 1
        // 251 == 152
        reversed = (reversed * 10) + (xcopy % 10);
        xcopy /= 10;
    }

    return (reversed == x);

}

int main() {

    // Test Variable
    int x = 2552;


    Solution testers;
    bool valNaive = testers.Naive_isPalindrome(x);
    bool valSmart = testers.Smart_isPalindomre(x);

    cout << "Naive returns " << valNaive << "   Smart returns " << valSmart << endl;

    return 0;
}