#include <iostream>

using namespace std;

class CircularInt {
    
    int start, end;
    int curHour;
    
    public:
    
    CircularInt(int start, int end);
    CircularInt(int start, int end, int curHour);
    int getStart();
    int getEnd();
    int getCurHour();
    int setCurHour(int hour);
    friend ostream& operator<<(ostream& os, const CircularInt& circ);  
    CircularInt& operator+= (int add);
    CircularInt& operator++ (int);
    int operator- ();
    // friend CircularInt& operator- (int baseHourn, CircularInt& circ);
    int operator+ (CircularInt& circ);
    CircularInt& operator*= (int mult);
    int operator/ (int div);
};

CircularInt& operator- (int baseHourn, CircularInt& circ);
