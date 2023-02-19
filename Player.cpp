#include <string>
#include "Player.h"
using namespace std;

Player::Player()
{
    money = 0;
    salary = 100;
    stuff = 0;
    day = 0;
    name = "Horatio";
}

int Player::getSalary() { return Player::salary; }
int Player::getDay() { return Player::day; }
int Player::getMoney() { return Player::money; }
int Player::getStuff() { return Player::stuff; }
string Player::getName(){ return Player::name; }
   
void Player::nextDay()
{
    Player::day++;
}

void Player::buyStuff()
{
    Player::money -= Player::salary;
    Player::stuff += Player::salary;
}

void Player::work()
{
    Player::money += Player::salary;
}

void Player::salaryChange(int changeAmount)
{
    Player::salary += changeAmount;
}




