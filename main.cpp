#include <iostream>

using namespace std;

class GameCharacter
{
private:
    string name;
    int gold;
    int maxGold;
    int level;

public:
    GameCharacter(string n, int g, int maxG, int lvl)
    {
        name = (n != "") ? n : "Player";
        maxGold = (maxG > 0) ? maxG : 1000;
        gold = (g >= 0 && g <= maxGold) ? g : 0;
        level = (lvl >= 1) ? lvl : 1;
    }

    bool earnGold(int amount)
    {
        if (amount <= 0)
            return false;
        if (gold + amount > maxGold)
            return false;
        gold += amount;
        return true;
    }

    bool spendGold(int amount)
    {
        if (amount <= 0)
            return false;
        if (amount > gold)
            return false;
        gold -= amount;
        return true;
    }

    bool levelUp()
    {
        level++;
        return true;
    }

    int getGold() const
    {
        return gold;
    }

    string getName() const
    {
        return name;
    }

    void showStatus() const
    {
        cout << "Name: " << name << endl;
        cout << "Gold: " << gold << endl;
        cout << "Level: " << level << endl;
    }
};

int main() {

    GameCharacter gc1("Hero", 500, 1000, 1);
    GameCharacter gc2("", -100, -50, 0); // invalid values

    gc1.earnGold(300);
    gc1.spendGold(200);
    gc1.spendGold(2000); // invalid

    gc1.levelUp();

    gc1.showStatus();
    gc2.showStatus();

    return 0;
}