#include <iostream>
#include <string>

class BitString {
private:
    unsigned long m_high;
    unsigned long m_low;

public:
    BitString() : m_high(0), m_low(0) {}

    BitString(unsigned long high, unsigned long low) : m_high(high), m_low(low) {}

    BitString(int high, int low) : m_high(static_cast<unsigned long>(high)), m_low(static_cast<unsigned long>(low)) {}

    BitString(std::string str) : m_high(0), m_low(0) {
        for (int i = 0; i < 64 && i < str.length(); i++) {
            if (str[i] == '1') {
                if (i < 32) {
                    m_high |= (1UL << (31 - i));
                }
                else {
                    m_low |= (1UL << (63 - i));
                }
            }
        }
    }

    BitString operator&(const BitString& other) const {
        return BitString(m_high & other.m_high, m_low & other.m_low);
    }

    BitString operator|(const BitString& other) const {
        return BitString(m_high | other.m_high, m_low | other.m_low);
    }

    BitString operator^(const BitString& other) const {
        return BitString(m_high ^ other.m_high, m_low ^ other.m_low);
    }

    BitString operator~() const {
        return BitString(~m_high, ~m_low);
    }

    friend std::ostream& operator<<(std::ostream& os, const BitString& bs) {
        for (int i = 31; i >= 0; i--) {
            os << ((bs.m_high >> i) & 1);
        }
        for (int i = 63; i >= 32; i--) {
            os << ((bs.m_low >> i) & 1);
        }
        return os;
    }
};

int main() {
    BitString bs1(0x01234567, 0x89ABCDEF);
    BitString bs2(0xFEDCBA98, 0x76543210);

    std::cout << "bs1: " << bs1 << std::endl;
    std::cout << "bs2: " << bs2 << std::endl;
    std::cout << "bs1 & bs2: " << (bs1 & bs2) << std::endl;
    std::cout << "bs1 | bs2: " << (bs1 | bs2) << std::endl;
    std::cout << "bs1 ^ bs2: " << (bs1 ^ bs2) << std::endl;
    std::cout << "~bs1: " << ~bs1 << std::endl;

    BitString bs3("1010101010101010101010101010101010101010101010101010101010101010");
    std::cout << "bs3: " << bs3 << std::endl;

    return 0;
}