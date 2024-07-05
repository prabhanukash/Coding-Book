#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
// Abstraction Example: Geometric Shapes

class Shape {
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual string getType() const = 0;
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(double radius) : radius(radius) {}

  double area() const override { return 3.14159 * radius * radius; }

  double perimeter() const override { return 2 * 3.14159 * radius; }

  string getType() const override { return "Circle"; }
};

class Rectangle : public Shape {
private:
  double length;
  double width;

public:
  Rectangle(double length, double width) : length(length), width(width) {}

  double area() const override { return length * width; }

  double perimeter() const override { return 2 * (length + width); }

  string getType() const override { return "Rectangle"; }
};

// Encapsulation Example: Bank Account

class BankAccount {
private:
  string accountNumber;
  double balance;

public:
  BankAccount(const string &accountNumber, double initialBalance)
      : accountNumber(accountNumber), balance(initialBalance) {}

  string getAccountNumber() const { return accountNumber; }

  double getBalance() const { return balance; }

  void deposit(double amount) { balance += amount; }

  bool withdraw(double amount) {
    if (amount > balance) {
      return false;
    }
    balance -= amount;
    return true;
  }
};

// Interface Example: Logging System

class Logger {
public:
  virtual void info(const string &message) = 0;
  virtual void debug(const string &message) = 0;
  virtual void error(const string &message) = 0;
};

class FileLogger : public Logger {
private:
  ofstream logFile;

public:
  FileLogger(const string &filename) : logFile(filename) {
    // Add timestamp to log file
    logFile << "Log started at: " << getCurrentTime() << endl;
  }

  void info(const string &message) override {
    logFile << "INFO: " << message << endl;
  }

  void debug(const string &message) override {
    logFile << "DEBUG: " << message << endl;
  }

  void error(const string &message) override {
    logFile << "ERROR: " << message << endl;
  }

private:
  string getCurrentTime() {
    time_t now = time(0);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return buffer;
  }
};

// Polymorphism Example: Using Shapes with Logging

int main() {
  // Abstraction and Polymorphism
  unique_ptr<Logger> logger = make_unique<FileLogger>("my_log.txt");

  unique_ptr<Shape> shape1 = make_unique<Circle>(5.0);
  unique_ptr<Shape> shape2 = make_unique<Rectangle>(4.0, 6.0);

  logger->info("Shape 1: " + shape1->getType());
  logger->info("Area: " + to_string(shape1->area()));
  logger->info("Perimeter: " + to_string(shape1->perimeter()));

  logger->info("Shape 2: " + shape2->getType());
  logger->info("Area: " + to_string(shape2->area()));
  logger->info("Perimeter: " + to_string(shape2->perimeter()));

  // Encapsulation
  BankAccount account("1234567890", 1000.0);
  logger->info("Account Number: " + account.getAccountNumber());
  logger->info("Initial Balance: " + to_string(account.getBalance()));

  account.deposit(500.0);
  logger->info("Balance after deposit: " + to_string(account.getBalance()));

  if (account.withdraw(200.0)) {
    logger->info("Withdrawal successful. New balance: " +
                 to_string(account.getBalance()));
  } else {
    logger->info("Insufficient funds.");
  }

  return 0;
}