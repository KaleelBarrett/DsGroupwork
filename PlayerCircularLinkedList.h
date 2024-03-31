#pragma once

#ifndef PLAYERCIRCULARLINKEDLIST_H
#define PLAYERCIRCULARLINKEDLIST_H
#include"Player.h"
#include"Node.h"
class PlayerList{

    private:
        Node* head;
        Node* tail;

    public:

        PlayerList(){
            head = NULL;
            tail = NULL;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        void insert(Player data){

            Node* temp = new Node(data);

            if(isEmpty()){
                head = temp;
                tail = temp;
                tail->setNextNode(head);
            }
            else{
                tail->setNextNode(temp);
                tail = temp;
                tail->setNextNode(head);
            }

        }

        void addToGrandTotal(int index, int value){
            if(index < 1 || index > numPlayers()){
                throw std::out_of_range("Index out of range");
            }

            Player& player = getPlayer(index);
            player.SetScore(value);
        }

        Player& getPlayer(int index){
            if(index < 1 || index > numPlayers()){
                throw std::out_of_range("Index out of range");
            }

            Node* current = head;
            for(int i = 1; i < index; i++){
                current = current->getNextNode();
            }

            return current->getData();
        }

        int numPlayers(){
            if(isEmpty()){
                return 0;
            }

            Node* current = head;
            int count = 1;
            while(current->getNextNode() != head){
                current = current->getNextNode();
                count++;
            }

            return count;
        }

};

#endif