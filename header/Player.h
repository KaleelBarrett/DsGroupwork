#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    int playerNumber;
    std::string fName;
    std::string lName;
    int grandTotal;

public:
    Player();
    Player(int playerNumber, const std::string& fName, const std::string& lName);

    void setPlayerNumber(int playerNumber);
    int getPlayerNumber() const;

    void setFName(const std::string& fName);
    const std::string& getFName() const;

    void setLName(const std::string& lName);
    const std::string& getLName() const;

    void setGrandTotal(int grandTotal);
    int getGrandTotal() const;
};

#endif // PLAYER_H
