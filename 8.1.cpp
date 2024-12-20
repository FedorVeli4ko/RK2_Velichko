#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

string binaryAddition(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result += to_string(sum % 2);
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "101101";
    string b = "110011";

    string andResult = "";
    for (size_t i = 0; i < a.length(); ++i) {
        andResult += (a[i] == '1' && b[i] == '1') ? '1' : '0';
    }
    cout << "Побитовое AND: " << andResult << endl;

    string sumResult = binaryAddition(a, b);
    cout << "Сумма: " << sumResult << endl;

    return 0;
}
