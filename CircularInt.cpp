#include <iostream>
#include "CircularInt.hpp"
#include <string>

using namespace std;

CircularInt::CircularInt(int start, int end){
    this->start = start;
    this->end = end;
    curHour = start;
}

CircularInt::CircularInt(int start, int end, int curHour){
    this->start = start;
    this->end = end;
    this->curHour = curHour;
}

int CircularInt::getStart(){
    return start;
}

int CircularInt::getEnd(){
    return end;
}

int CircularInt::getCurHour(){
    return curHour;
}

int CircularInt::setCurHour(int hour){
    curHour = hour;
}

ostream& operator<<(ostream& os, const CircularInt& circ)  
{  
    os << circ.curHour << endl;
    return os;  
}

CircularInt& CircularInt::operator+= (int add){ 
    curHour = (curHour + add) % end;
    if (curHour == 0) curHour = end;
    return *this;
}

CircularInt& CircularInt::operator++ (int){ 
    curHour = (curHour + 1) % end;
    if (curHour == 0) curHour = end;
    return *this;
}

int CircularInt::operator- (){ 
    int ans = (end - curHour) % end;
    if (ans == 0) ans = end;
    return ans;
}

CircularInt& operator- (int baseHour, CircularInt& circ){ 
    int curHour = circ.getCurHour();
    int end = circ.getEnd();
    int ans = baseHour - curHour;
    ans = ans % end;
    if (ans == 0) ans = end;
    circ.setCurHour(-ans);
    ans = -circ;
    circ.setCurHour(ans);
    return circ;
}

int CircularInt::operator+ (CircularInt& circ){
    return (curHour + circ.getCurHour()) % end;
}

CircularInt& CircularInt::operator*= (int mult){ 
    curHour = (curHour * mult) % end;
    if (curHour == 0) curHour = end;
    return *this;
}

int CircularInt::operator/ (int div){ 
    if(curHour % div != 0){
        string message = "There is no number x in {" + to_string(start) + "," 
                       + to_string(end) +"} such that x*" + to_string(div) + "=" + to_string(curHour);
        throw message;
    }
    else{
        int ans = (curHour / div) % end;
        if (ans == 0) ans = end;
        return ans;
    }
}


// int main(){
//     CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
// 	cout << hour;                     // 1
// 	hour += 4;  cout << hour;         // 5
// 	(hour += 2)++;  cout << hour;    // 8
// 	hour += 18;   cout << hour;      // 2   (18 hours after 8)
// 	cout << -hour;                // 10  (2 hours before midnight)
// // 	hour = 1 - hour; cout << hour;   // 11  (2 hours before 1)
//     hour++;
//     cout << hour+hour << endl;                // 10 (11 hours after 11)
//     hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
//     cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
    
// }
