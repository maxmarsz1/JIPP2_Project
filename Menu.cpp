#include "Menu.h"
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Task.h"
#include "TaskList.h"

using namespace std;


Menu::Menu(){
    cout << "---------------------------------" << endl;
    cout << "ToDoList by Maksymilian Marszałek" << endl;
    cout << "---------------------------------" << endl;

    Menu::menu();
}

void Menu::menu(){
    while(1){
        string taskText, menuBuff, filename;
        ofstream out;
        int in;
        cout<<"1.Wypisz todo" << endl;
        cout<<"2.Dodaj todo" << endl;
        cout<<"3.Zapisz todos" << endl;
        cout<<"4.Wczytaj todos" << endl;
        cout<<"0.Zakończ" << endl;
        cout << ": ";
        getline(cin>>ws, menuBuff);
        try {
            in = stoi(menuBuff);
        } catch (...) {
            cout << "Error while reading cin" << endl;
            exit(420);
        }
        switch(in){
            case Menu::Display:
            cout << "--------------------------" << endl;
            cout << "Tasks:" << endl;
            for(auto&[key, value]: taskList.getTasks()){
                cout << key << "." << value << endl;
            }
            cout << "--------------------------" << endl;
            if(taskList.lastId != 0){
                Menu::menuTask();
            } else {
                continue;
            }
            continue;

            case Menu::Add:
            cout << "Nazwa todo: ";
            getline(cin>>ws, taskText);
            taskList.addTask(taskText);
            continue;

            case Menu::Save:
            cout << "Nazwa pliku: ";
            getline(cin>>ws, filename);
            try{
                taskList.save(filename);
            }
            catch (...){
                cout << "Todos nie mogły zostać zapisane" << endl;
            }
            continue;

            case Menu::Load:
            cout << "Nazwa pliku: ";
            getline(cin>>ws, filename);
            try{
                taskList.load(filename);
            }
            catch (...){
                cout << "Todos nie mogły zostać wczytane" << endl;
            }
            continue;

            case Menu::Exit:
            break;

            default:
            cout<<"Nieprawidłowy wybór"<< endl;
            continue;
        }
        break;
    }
}

void Menu::menuTask(){
    string buff;
    int selectionId;

    cout<< "Wybierz task: ";
    getline(cin>>ws ,buff);

    try{
        selectionId = stoi(buff);
        taskList.getTask(selectionId);
        selectedTaskId = selectionId;
    } catch (invalid_argument) {
        cout << "Nieprawidłowy wybór: " << buff << endl;
        return;
    } catch (out_of_range) {
        cout << "Task o podanym ID nieistnieje :( " << selectionId << endl;
        return;
    }

    while(1){
        Task* task = taskList.getTask(selectedTaskId);
        cout<<"Wybrane todo: id(" << selectedTaskId << ")" << endl;
        cout<< task << endl;
        cout<<"1.Przelacz todo" << endl;
        cout<<"2.Edytuj todo" << endl;
        cout<<"3.Usun todo" << endl;
        cout<<"4.Powrot" << endl;
        cout << ": ";

        string buff;
        getline(cin>>ws ,buff);

        try {
            selectionId = stoi(buff);
            switch(selectionId){
                case Menu::Toggle:
                task->toggleDone();
                continue;

                case Menu::Edit:
                cout << "Wpisz nowy tekst todo: ";
                getline(cin>>ws, buff);
                task->setText(buff);
                continue;

                case Menu::Remove:
                taskList.removeTask(selectedTaskId);
                break;

                case Menu::Back:
                break;
            }
        } catch (...) {
            cout << "Nieprawidłowy wybór." << endl;
        }
        selectedTaskId = -1;
        break;
    }
}
