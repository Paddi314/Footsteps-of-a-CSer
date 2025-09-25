#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Base class Sum
class Sum {
public:
    virtual void Show() = 0;
    virtual void Add(Sum* num) = 0;
};

// Number class - handles real numbers
class Number : public Sum {
private:
    double data;
public:
    Number(double d = 0.0) : data(d) {}
    
    void Show() {
        cout << data;
    }
    
    void Add(Sum* num) {
        Number* n = dynamic_cast<Number*>(num);
        if (n) {
            data += n->data;
        }
    }
    
    double GetData() const { return data; }
};

// Complex class - handles complex numbers
class Complex : public Sum {
private:
    double real, imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
    void Show() {
        cout << real << "+" << imag << "i";
    }
    
    void Add(Sum* num) {
        Complex* c = dynamic_cast<Complex*>(num);
        if (c) {
            real += c->real;
            imag += c->imag;
        }
    }
    
    double GetReal() const { return real; }
    double GetImag() const { return imag; }
};

// Fraction class - handles fractions
class Fraction : public Sum {
private:
    int num, den;  // numerator and denominator
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        Format();
    }
    
    // Format the fraction to reduce and handle negative values
    void Format() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        
        // Find GCD to reduce the fraction
        int a = abs(num);
        int b = abs(den);
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        // Reduce the fraction
        if (a > 0) {
            num /= a;
            den /= a;
        }
    }
    
    void Show() {
        cout << num << "/" << den;
    }
    
    void Add(Sum* num) {
        Fraction* f = dynamic_cast<Fraction*>(num);
        if (f) {
            this->num = this->num * f->den + f->num * this->den;
            this->den = this->den * f->den;
            Format();
        }
    }
    
    int GetNum() const { return num; }
    int GetDen() const { return den; }
};

// Huge_Int class - handles large integers
class Huge_Int : public Sum {
private:
    char sign;  // '+' or '-'
    unsigned data[110];  // Store digits in reverse order
    int length;  // Number of digits
    
public:
    Huge_Int(const char* str = "0") {
        // Set default values
        sign = '+';
        memset(data, 0, sizeof(data));
        length = 0;
        
        if (str) {
            // Parse the sign
            int startIdx = 0;
            if (str[0] == '+' || str[0] == '-') {
                sign = str[0];
                startIdx = 1;
            }
            
            // Parse digits (in reverse order for easier addition)
            length = strlen(str) - startIdx;
            for (int i = 0; i < length; i++) {
                data[i] = str[strlen(str) - 1 - i] - '0';
            }
            
            // Normalize by removing leading zeros
            while (length > 1 && data[length - 1] == 0) {
                length--;
            }
        }
    }
    
    void Show() {
        if (length == 0) {
            cout << "0";
            return;
        }
        
        if (sign == '-') {
            cout << "-";
        }
        
        for (int i = length - 1; i >= 0; i--) {
            cout << data[i];
        }
    }
    
    void Add(Sum* num) {
        Huge_Int* h = dynamic_cast<Huge_Int*>(num);
        if (h) {
            // If signs are different, this becomes subtraction
            if (sign != h->sign) {
                // Determine which number has larger absolute value
                int cmp = compareAbs(h);
                
                if (cmp == 0) {  // Equal absolute values
                    sign = '+';
                    length = 1;
                    data[0] = 0;
                } else if (cmp > 0) {  // |this| > |h|
                    subtractAbs(h);
                } else {  // |this| < |h|
                    Huge_Int temp = *h;
                    temp.subtractAbs(this);
                    *this = temp;
                    sign = h->sign;
                }
            } else {  // Same sign, simple addition
                addAbs(h);
            }
        }
    }
    
private:
    // Compare absolute values: returns 1 if |this| > |h|, 0 if equal, -1 if |this| < |h|
    int compareAbs(const Huge_Int* h) const {
        if (length > h->length) return 1;
        if (length < h->length) return -1;
        
        for (int i = length - 1; i >= 0; i--) {
            if (data[i] > h->data[i]) return 1;
            if (data[i] < h->data[i]) return -1;
        }
        
        return 0;
    }
    
    // Add absolute values
    void addAbs(const Huge_Int* h) {
        int carry = 0;
        int maxLength = max(length, h->length);
        
        for (int i = 0; i < maxLength || carry; i++) {
            if (i >= length) {
                data[length++] = 0;
            }
            
            data[i] += (i < h->length ? h->data[i] : 0) + carry;
            carry = data[i] / 10;
            data[i] %= 10;
        }
        
        // Check if we need to extend length
        while (length > 1 && data[length - 1] == 0) {
            length--;
        }
    }
    
    // Subtract absolute value of h from absolute value of this
    // Assumes |this| > |h|
    void subtractAbs(const Huge_Int* h) {
        int borrow = 0;
        
        for (int i = 0; i < length; i++) {
            int digit = data[i] - borrow - (i < h->length ? h->data[i] : 0);
            
            if (digit < 0) {
                digit += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            data[i] = digit;
        }
        
        // Remove leading zeros
        while (length > 1 && data[length - 1] == 0) {
            length--;
        }
    }
};

// Main function
int main() {
    Sum* ps1, * ps2;
    
    Number a(25.0), b(30.5);
    ps1 = &a; ps2 = &b;
    ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); ps1->Show(); cout << endl;
    
    Complex ca(1, 2), cb(3, 4);
    ps1 = &ca; ps2 = &cb;
    ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); ps1->Show(); cout << endl;
    
    Fraction fa(2, 3), fb(3, 4);
    ps1 = &fa; ps2 = &fb;
    ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); ps1->Show(); cout << endl;
    
    Huge_Int ha("+12345678901234567890"), hb("+99999999999999999999");
    ps1 = &ha; ps2 = &hb;
    ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); ps1->Show(); cout << endl;
    
    return 0;
}