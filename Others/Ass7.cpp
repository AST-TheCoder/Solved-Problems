#include <iostream>
using namespace std;

// a.
class Month {
private:
  static string monthNames[12];
  int number;

public:
  // constructors
  Month(int n) { number = n; }
  Month(const Month &obj) { number = obj.number; }
  ~Month() { cout << "Destruction" << endl; } // destructor
  // mutators
  void setNum(int n) { number = n; }
  // accessors
  int getNum() { return number; }

  Month operator+(int x) {
    number = (this->number + x) % 12;
    return Month(number); // The remainder
  }

  Month operator-(int x) {
    number = (this->number - x + 12) % 12;
    return Month(number);
  }

  friend ostream &operator<<(ostream &out, const Month &rhs) {
    out << rhs.monthNames[rhs.number];
    return out;
  }

  // coversion operators
  operator string() { return monthNames[number]; }

  operator int() { return number; }

  friend void changeSeason(Month &m) { m.number = (m.number + 6) % 12; }
};

string Month::monthNames[12] ={ "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

class GreenLeaves {
private:
  int number;
  string *months =
      new string[6]{"March", "April", "May", "June", "July", "August"};

public:
  GreenLeaves(int n) { number = n; }
  // copy constructor
  GreenLeaves(const GreenLeaves &obj) {
    months = obj.months;
    number = obj.number;
  }
  // destructor
  ~GreenLeaves() { cout << "Deleting" << endl; }
  // move constructor
  GreenLeaves(GreenLeaves &&temp) {
    months = temp.months;
    temp.months = nullptr;
  }
  friend ostream &operator<<(ostream &out, const GreenLeaves &rhs) {
    out << rhs.months[rhs.number];
    return out;
  }
};

int main() {
  // testing mutators, accessors, changeSeason, and conversion operators
  Month January = Month(0);
  cout << January.getNum() << endl;

  Month Jan_2021 = Month(January);
  cout << Jan_2021.getNum() << endl;
  January + 5;

  int month_num = January;
  cout<<month_num<<endl;


  string month = January;
  cout<<month<<endl;
  January - 2;
  cout << January << endl;
  January + 5;
  cout << January.getNum() << endl;
  January.setNum(0);
  cout << January.getNum() << endl;
  changeSeason(January);
  cout << January << endl;
  string monthLabel = string(January);
  cout << monthLabel << endl;
  int numero = int(January);
  cout << numero << endl;


  // testing copy consructor, move constructor, and << operator
  GreenLeaves April = GreenLeaves(1);
  cout << April << endl;
  GreenLeaves April2 = April;
  cout << April2 << endl;
  GreenLeaves May = GreenLeaves(2);
  GreenLeaves May_holder = GreenLeaves(May);
  cout << May_holder << endl;}