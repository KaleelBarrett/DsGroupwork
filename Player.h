#pragma once
#include <string>
#include <iostream>
//
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{

    private:
        int playerNumber;
        string fName;
        string lName;
        int grandTotal;
    
    public:

        Player(){
            playerNumber = 0;
            fName = " ";
            lName = " ";
            grandTotal = 0;
        }

        Player(int playerNumber, string fName, string lName){

            this->playerNumber = playerNumber;
            this->fName = fName;
            this->lName = lName;
            grandTotal = 0;
        }

        void SetPlayerNumber(int playerNumber){
            this->playerNumber = playerNumber;
        }

        int GetPlayerNumber(){
            return playerNumber;
        }

        void SetName(string fName){
            this->fName = fName;
        }

        string GetName(){
            return fName;
        }

        void SetScore(int grandTotal){
            this->grandTotal = grandTotal;
        }

        int GetScore(){
            return grandTotal;
        }
        
};

#endif