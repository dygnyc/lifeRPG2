#include <string>
using namespace std;

class Player
{

public:
    Player();

    void nextDay();
    void buyStuff();
    void work();  
    void salaryChange(int changeAmount);

    int getSalary();
    int getDay();
    int getMoney();
    int getStuff();

    string getName();

private:
    string name;
    int money, stuff, day;
    int salary;
};