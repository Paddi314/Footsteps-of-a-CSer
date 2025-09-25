#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

char Hex_num[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

class HEX {
    char m_num[10]; // Can store up to 10 hexadecimal digits
public:
    HEX(); // Constructor, initializes to all '0'
    HEX(unsigned n); // Converts unsigned decimal to hexadecimal
    unsigned GetBit(int i); // Gets decimal value of digit at position i
    operator unsigned(); // Converts hexadecimal to unsigned decimal
    int length(); // Gets length of hexadecimal number
    HEX operator+(const HEX& n); // Addition
    HEX operator-(const HEX& n); // Subtraction (requires minuend >= subtrahend)
    HEX operator*(const HEX& n); // Multiplication
    HEX operator/(const HEX& n); // Division (returns quotient)
    HEX operator%(const HEX& n); // Modulo (returns remainder)
    HEX& operator++(); // Prefix increment
    HEX operator++(int); // Postfix increment
    friend istream& operator>>(istream& i, HEX& n); // Input hexadecimal number
    friend ostream& operator<<(ostream& o, const HEX& n); // Output hexadecimal number
};

// Implementation of HEX methods

// Constructor: initialize to all '0'
HEX::HEX() {
    for (int i = 0; i < 10; i++) {
        m_num[i] = '0';
    }
}

// Convert unsigned decimal to hexadecimal
HEX::HEX(unsigned n) {
    // Initialize with '0'
    for (int i = 0; i < 10; i++) {
        m_num[i] = '0';
    }
    
    // Convert decimal to hexadecimal
    int index = 9;
    while (n > 0 && index >= 0) {
        int remainder = n % 16;
        m_num[index] = Hex_num[remainder];
        n /= 16;
        index--;
    }
}

// Get decimal value of digit at position i
unsigned HEX::GetBit(int i) {
    if (i < 0 || i >= 10) {
        return 0;
    }
    
    char digit = m_num[i];
    if (digit >= '0' && digit <= '9') {
        return digit - '0';
    } else if (digit >= 'A' && digit <= 'F') {
        return digit - 'A' + 10;
    } else {
        return 0;
    }
}

// Convert hexadecimal to unsigned decimal
HEX::operator unsigned() {
    unsigned result = 0;
    int len = length();
    
    for (int i = 10 - len; i < 10; i++) {
        result = result * 16 + GetBit(i);
    }
    
    return result;
}

// Get length of hexadecimal number
int HEX::length() {
    int len = 0;
    for (int i = 0; i < 10; i++) {
        if (m_num[i] != '0') {
            len = 10 - i;
            break;
        }
    }
    if (len == 0) {
        len = 1; // If all digits are '0', return length 1
    }
    return len;
}

// Addition
HEX HEX::operator+(const HEX& n) {
    unsigned dec1 = (unsigned)(*this);
    unsigned dec2 = (unsigned)(const_cast<HEX&>(n));
    unsigned sum = dec1 + dec2;
    return HEX(sum);
}

// Subtraction
HEX HEX::operator-(const HEX& n) {
    unsigned dec1 = (unsigned)(*this);
    unsigned dec2 = (unsigned)(const_cast<HEX&>(n));
    
    // Ensure minuend >= subtrahend
    if (dec1 < dec2) {
        return HEX(0);
    }
    
    unsigned diff = dec1 - dec2;
    return HEX(diff);
}

// Multiplication
HEX HEX::operator*(const HEX& n) {
    unsigned dec1 = (unsigned)(*this);
    unsigned dec2 = (unsigned)(const_cast<HEX&>(n));
    unsigned product = dec1 * dec2;
    return HEX(product);
}

// Division
HEX HEX::operator/(const HEX& n) {
    unsigned dec1 = (unsigned)(*this);
    unsigned dec2 = (unsigned)(const_cast<HEX&>(n));
    
    // Avoid division by zero
    if (dec2 == 0) {
        return HEX(0);
    }
    
    unsigned quotient = dec1 / dec2;
    return HEX(quotient);
}

// Modulo
HEX HEX::operator%(const HEX& n) {
    unsigned dec1 = (unsigned)(*this);
    unsigned dec2 = (unsigned)(const_cast<HEX&>(n));
    
    // Avoid modulo by zero
    if (dec2 == 0) {
        return HEX(0);
    }
    
    unsigned remainder = dec1 % dec2;
    return HEX(remainder);
}

// Prefix increment
HEX& HEX::operator++() {
    unsigned value = (unsigned)(*this);
    value++;
    *this = HEX(value);
    return *this;
}

// Postfix increment
HEX HEX::operator++(int) {
    HEX temp = *this;
    unsigned value = (unsigned)(*this);
    value++;
    *this = HEX(value);
    return temp;
}

// Input hexadecimal number
istream& operator>>(istream& i, HEX& n) {
    cout << "Please input a Hex number(>=0,<=FFFF,Hex characters: 0-9 or A-F):" << endl;
    string input;
    i >> input;
    
    // Convert to uppercase
    for (char &c : input) {
        c = toupper(c);
    }
    
    // Validate input
    for (char c : input) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            cerr << "Invalid hexadecimal digit: " << c << endl;
            i.setstate(ios::failbit);
            return i;
        }
    }
    
    // Initialize to all '0'
    for (int j = 0; j < 10; j++) {
        n.m_num[j] = '0';
    }
    
    // Copy input to m_num from right to left
    int len = input.length();
    int start = 10 - len;
    for (int j = 0; j < len && j < 10; j++) {
        n.m_num[start + j] = input[j];
    }
    
    return i;
}

// Output hexadecimal number
ostream& operator<<(ostream& o, const HEX& n) {
    bool leadingZero = true;
    for (int i = 0; i < 10; i++) {
        if (leadingZero && n.m_num[i] != '0') {
            leadingZero = false;
        }
        
        if (!leadingZero) {
            o << n.m_num[i];
        }
    }
    
    // If all digits are zero, output a single zero
    if (leadingZero) {
        o << '0';
    }
    
    return o;
}

int main() {
    HEX n1, n2, n3;
    char repeat('Y');
    do {
        n1 = 0; n2 = 0; n3 = 0;
        cin >> n1 >> n2;
        
        n3 = n1 + n2;
        cout << n1 << '+' << n2 << '=' << n3 << endl;
        
        n3 = n1 - n2;
        cout << n1 << '-' << n2 << '=' << n3 << endl;
        
        n3 = n1 * n2;
        cout << n1 << '*' << n2 << '=' << n3 << endl;
        
        n3 = n1 / n2;
        cout << n1 << '/' << n2 << '=' << n3 << endl;
        
        n3 = n1 % n2;
        cout << n1 << '%' << n2 << '=' << n3 << endl;
        
        cout << "Repeat?(Y/N)";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    
    cout << "Press any key to continue..." << endl;
    return 0;
}