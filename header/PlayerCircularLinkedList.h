#pragma once

#ifndef PLAYERCIRCULARLINKEDLIST_H

#define PLAYERCIRCULARLINKEDLIST_H
#include "header/Player.h"
#include "header/Node.h"
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

};

#endif