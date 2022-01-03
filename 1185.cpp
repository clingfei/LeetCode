#include <string>

using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int num = 0;
        if (year == 1972) num = 365;
        else if (year > 1972) num = (year - 1972) / 4 * (365 * 4 + 1) + ((year - 1972) % 4) * 365 + 365;
        if ((year - 1972) % 4 != 0) num++;

        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 || (year % 100 !=0 && year % 4 == 0))
            months[1] = 29;
        for (int i = 0; i < month - 1; i++) 
            num += months[i];
        num += day;
        switch ((num + 4) % 7) {
            case 0: return "Sunday";
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            default: return "Saturday";
        }    
    }
};
