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
        in = 0;
        Menu::print();
        cout << ": ";
        if (cin >> in){
            switch(in){
                case Menu::Display:
                cout << "--------------------------" << endl;
                cout << "Tasks:" << endl;
                for(auto&[key, value]: *taskList.getTasks()){
                    cout << key << "." << value.getText() << " | zrobiony: "<< (value.isDone() ? "tak" : "nie")<< endl;
                }
                cout << "--------------------------" << endl;
                break;;

                case Menu::Add:
                cout << "Nazwa todo: ";
                getline(cin>>ws, taskText);
                // if(!cin){
                //     cin.clear();
                // }
                taskList.addTask(taskText);
                break;;

                case Menu::Remove:

                break;;
                case Menu::Exit:
                exit(0);

                default:
                cout<<"Nieprawidłowy wybór"<< endl;
            }
        } else {
            // cin.clear();
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    }
}

void Menu::print(){
    cout<<"1.Wypisz todo" << endl;
    cout<<"2.Dodaj todo" << endl;
    cout<<"3.Usun todo" << endl;
    cout<<"4.Zakończ" << endl;
}

