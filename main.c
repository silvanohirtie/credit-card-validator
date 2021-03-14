#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int getLength(number) {
  return (int) floor(log10(abs(number))) + 1;
}

string creditName(long creditCard) {
  int creditLength = (int) floor(log10(labs(creditCard))) + 1;
  int i = creditLength - 1;
  int sum = 0;
  int creditArray[creditLength];

  while (creditCard > 0) {
    int digit = creditCard % 10;
    creditCard /= 10;
    creditArray[i] = digit;
    i--;
  }
  int firstDigit = creditArray[0];
  int secondDigit = creditArray[1];
  if ((creditLength == 15 && firstDigit == 3 && secondDigit == 4) || (creditLength == 15 && firstDigit == 3 && secondDigit == 7)) {
    return "AMEX\n";
  } else if (creditLength == 13 && firstDigit == 4) {
    return "VISA\n";
  } else if (creditLength == 16) {
    if (firstDigit == 4) {
      return "VISA\n";
    } else if ((firstDigit == 5 && secondDigit == 1) || (firstDigit == 5 && secondDigit == 2) || (firstDigit == 5 && secondDigit == 3) || (firstDigit == 5 && secondDigit == 4) || (firstDigit == 5 && secondDigit == 5)) {
      return "MASTERCARD\n";
    } else {
      return "INVALID\n";
    }

  }
  return "INVALID\n";
}

bool validChecksum(long creditCard) {
  int creditLength = (int) floor(log10(labs(creditCard))) + 1;
  int creditArray[creditLength];

  int i = creditLength - 1;
  int sum = 0;

  while (creditCard > 0) {
    int digit = creditCard % 10;
    creditCard /= 10;
    creditArray[i] = digit;
    i--;
  }

  for (int x = 0; x < creditLength; x++) {}

  //Array length - 2, to start from the last but one digit
  for (int x = creditLength - 2; x >= 0; x -= 2) {
    int multipliedNumber = creditArray[x] * 2;

    if (getLength(multipliedNumber) > 1) {
      int digitsArray[2];

      int j = getLength(multipliedNumber) - 1;

      while (multipliedNumber > 0) {
        int digit = multipliedNumber % 10;
        multipliedNumber /= 10;
        digitsArray[j] = digit;
        j--;
      }

      sum += digitsArray[0] + digitsArray[1];

    } else {
      sum += multipliedNumber;

    }

  }
  //Array length - 1, to start from the last digit
  for (int x = creditLength - 1; x >= 0; x -= 2) {
    sum += creditArray[x];
  }
  int sumLength = getLength(sum);
  int k = sumLength - 1;
  int sumArray[sumLength];

  while (sum > 0) {
    int digit = sum % 10;
    sum /= 10;
    sumArray[k] = digit;
    k--;
  }

  if (sumArray[sumLength - 1] == 0) {
    return true;

  } else {
    return false;
  }
}



int main() {
  long creditCard;
  printf("Insert credit card number:\n");
  scanf("%ld",&creditCard);

  if (validChecksum(creditCard)) {
    printf("%s", creditName(creditCard));
  } else {
    printf("INVALID\n");
  }
}
