#include <string>
using namespace std;

class BigInt
{
    bool negative;
    string digits;

    public:
    // constructors
    BigInt();
    BigInt(int);
    BigInt(string);

    // member functions
    string to_string() const;

    bool operator==(const BigInt&) const;
    bool operator>(const BigInt&) const;
    // Add the other comparison operators later

    BigInt BigInt::operator+(const BigInt& b2) const;

};