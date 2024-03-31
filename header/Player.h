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

        void SetFName(string fName){
            this->fName = fName;
        }

        string GetFName(){
            return fName;
        }

        void SetLName(string lName){
            this->lName = lName;
        }

        string GetLName(){
            return lName;
        }

        void SetGrandTotal(int grandTotal){
            this->grandTotal = grandTotal;
        }

        int GetGrandTotal(){
            return grandTotal;
        }
        
};

#endif