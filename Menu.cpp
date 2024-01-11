#include "Menu.h"
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>
#include "Task.h"
#include "TaskList.h"

using namespace std;

Menu::Menu(){
    cout << "---------------------------------" << endl;
    cout << "ToDoList by Maksymilian Marszałek" << endl;
    cout << "---------------------------------" << endl;
    int in;
    string taskText;

    while(1){
        Menu::menu();
        
    }
}


void Menu::menu(){
    while(1){
        cout<<"1.Wypisz todo" << endl;
        cout<<"2.Dodaj todo" << endl;
        cout<<"0.Zakończ" << endl;
        cout << ": ";
        if (cin >> in){
            switch(in){
                case Menu::Display:
                while(1){
                    cout << "--------------------------" << endl;
                    cout << "Tasks:" << endl;
                    for(auto&[key, value]: taskList.getTasks()){
                        cout << key << "." << value->getText() << " | zrobiony: "<< (value->isDone() ? "tak" : "nie")<< endl;
                    }
                    cout << "--------------------------" << endl;
                    
                }
                break;;

                case Menu::Add:
                cout << "Nazwa todo: ";
                getline(cin>>ws, taskText);
                taskList.addTask(taskText);
                break;;

                case Menu::Exit:
                exit(0);

                default:
                cout<<"Nieprawidłowy wybór"<< endl;
            }
        }
    }
}

void Menu::menuTasks(){
    while(1){
        cout<<"1.Przelacz todo" << endl;
        cout<<"2.Edytuj todo" << endl;
        cout<<"3.Usun todo" << endl;
        cout<<"4.Powrot" << endl;

        string buff;
        int selectionId;
        getline(cin>>ws ,buff);

        try {
            selectionId = stoi(buff);
            switch(selectionId){
                case Menu::Toggle:

                break;;
                case Menu::Edit:

                break;;
                case Menu::Remove:

                break;;
                case Menu::Back:

                break;;
            }

        } catch (invalid_argument) {
            cout << "Nieprawidłowy wybór." << endl;
        }
            cout << "Task o podanym ID nie istnieje " << selectionId << endl;
    }
}