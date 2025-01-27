#include <iostream>
#include <string>
#include "BigInt.h"
#define to_num(c) (c-'0')
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& b2) const{
    if (digits.size() != b2.digits.size()) return false; //simple command which returns false when teh size is different
    if (negative != b2.negative) return false;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] != b2.digits[i]){
            return false;
        }
    }
    return true;
}

bool BigInt::operator>(const BigInt& b2) const{
    if(!negative && b2.negative) return true; //positive > negative
    if(negative && !b2.negative) return false; // negative < positive
    
  
    if (digits.size() < b2.digits.size()) {
        return negative ? true : false;
    }
   if(digits.size() > b2.digits.size()){
        return negative ? false : true; // check if there are differences in digit size
    }

    for(int i = 0; i < digits.size(); i++){
        if (digits[i] > b2.digits[i]){
            return negative ? false : true; // check for differences when they have same # of digits
        }
    } 
    return false; // the two BigInts are equal!
}



BigInt BigInt::operator+(const BigInt& b2) const
{
    string r = "";
    int c  = 0;
    
    int x = digits.size()-1;
    int y = b2.digits.size()-1;

    while(x>= 0 || y>=0 || c){
        int digit1 = (x >= 0) ? digits[x] - '0' : 0;
        int digit2 = (y >= 0) ? b2.digits[y] - '0' : 0;
        
        int sum = digit1 + digit2 + c;
        r.insert(r.begin(), (sum % 10) + '0');
        c = sum / 10;
        
        x--;
        y--;
    }

    return BigInt(r);

}

bool BigInt::operator<(const BigInt& b2) const{
    // doing simple comparison wehther if each other number is positive or negative
    if(!negative && b2.negative) return false;
    if(negative &&!b2.negative) return true;
    // this is testing when the two numbers have the same size, so we're actually looking for differences in the digits
    if(digits.size() > b2.digits.size()) return negative ? true : false;
    if(digits.size() < b2.digits.size()) return negative ? false : true;

    // this is the final case, so when the numbers have the same number of digits (most complicated)
    for (int i = 0; i < digits.size(); i++){
        if (digits[i] > b2.digits[i]) return negative ? true : false;
    }

    // final case, the two numbers of equak
    return false;
}

BigInt BigInt::operator-(const BigInt &b2) const {
    if (this->negative && !b2.negative) return -((-*this) + b2);
    if(!this->negative && b2.negative) return *this + (-b2);
    if (this->negative && b2.negative) return (-b2) - (-*this);
    if (*this < b2) return  -(b2 - *this);

    
    string n1 = this->digits;
    string n2 = b2.digits;
    string r = "";

    while (n1.size() < n2.size()){
        n1.insert(n1.begin(), '0');
    }

    while (n2.size() < n1.size()){
        n2.insert(n2.begin(), '0');
    }

    int c = 0;
    for (int i = n1.size() -1; i >= 0; i--){
        int d = (n1[i] - '0') - (n2[i] - '0') - c;
        if (d < 0){
            d += 10;
            c = 1; // setting the carry to 1 when the subtraction is too large
        }else{
            c = 0;
        }
        r.insert(r.begin(), d + '0'); //finalizingi the result before loop

    }

    while(r.size() > 1 && r.front() == '0'){
        r.erase(r.begin());
    }
    return BigInt(r);

}

BigInt BigInt::operator-() const{
    BigInt result = *this;
    result.negative =!negative;
    return result;
}

bool BigInt::operator!=(const BigInt& b2) const
{
    return !(this->operator==(b2));
}

bool BigInt::operator<=(const BigInt& b2) const
{
    return !(this->operator>(b2));
}
