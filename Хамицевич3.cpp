#include <iostream> 
#include <string>

class Money {
private: std::string amount;

public: Money() : amount("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000") {}

      Money(std::string amt) : amount(amt) {}

      void setAmount(std::string amt) { amount = amt; }

      std::string getAmount() { return amount; }

      friend Money operator+(Money m1, Money m2) {
          std::string amt1 = m1.getAmount();
          std::string amt2 = m2.getAmount();

          std::string result = "";
          int carry = 0;

          for (int i = 99; i >= 0; i--) {
              int sum = carry + (amt1[i] - '0') + (amt2[i] - '0');
              carry = sum / 10;
              result = std::to_string(sum % 10) + result;
          }

          return Money(result);
      }

      friend std::ostream& operator<<(std::ostream& os, Money m) {
          std::string amt = m.getAmount();
          int i = 0;

          while (amt[i] == '0' && i < 99) {
              i++;
          }

          os << "$";

          for (; i < 100; i++) {
              if (i == 99) {
                  os << ".";
              }
              os << amt[i];
          }

          return os;
      }
};

int main() {
    Money m1("0000000000000000001678954321567895432156789543215678954321567895432156789543215678954321567895432156789543215678954321"); Money m2("0000000000000000000321548799842132154879984213215487998421321548799842132154879984213215487998421321548799842132154879984");

    std::cout << m1 + m2 << std::endl;

    return 0;
}