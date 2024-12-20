#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Функция для побитового AND
string binaryAND(const string& a, const string& b) {
    string result = "";
    size_t len = max(a.length(), b.length());
    for (size_t i = 0; i < len; ++i) {
        char bitA = (i < a.length()) ? a[a.length() - 1 - i] : '0';
        char bitB = (i < b.length()) ? b[b.length() - 1 - i] : '0';
        result += ((bitA == '1') && (bitB == '1')) ? '1' : '0';
    }
    reverse(result.begin(), result.end());
    return result;
}


// Функция для двоичного сложения
string binaryAddition(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (sum % 2) + '0';
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}


int main() {
    string a = "101101";
    string b = "110011";

    string andResult = binaryAND(a, b);
    cout << "Побитовое AND: " << andResult << endl;

    string sumResult = binaryAddition(a, b);
    cout << "Сумма: " << sumResult << endl;

    return 0;
}
