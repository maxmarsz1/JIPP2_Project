#include "Menu.h"
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Exceptions.h"
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
        string taskText, buff, filename;
        ofstream out;
        Task* task;
        int in;
        cout<<"\t\t"<<endl;
        cout<<"1.Wypisz todo" << endl;
        cout<<"2.Dodaj todo" << endl;
        cout<<"3.Zapisz todos" << endl;
        cout<<"4.Wczytaj todos" << endl;
        cout<<"0.Zakończ" << endl;
        cout << ": ";
        getline(cin>>ws, buff);
        try {
            in = stoi(buff);
        } catch (...) {
            cout << "\x1B[31mError while reading cin\033[0m" << endl;
            exit(420);
        }
        switch(in){
            case Menu::Display:
            cout << "--------------------------" << endl;
            cout << "Tasks:" << endl;
            for(auto&[key, value]: taskList.getTasks()){
                if(value->datetime->isPast() && !value->isDone())
                    cout << "\x1B[31m";
                
                cout << key << ".";
                value->print();
                if(value->datetime->isPast() && !value->isDone())
                    cout << "\033[0m";
                cout << endl;
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
            // taskList.addTask(taskText);
            task = new Task(taskText);
            cout << "Deadline data (dd.mm.rrrr): ";
            getline(cin>>ws, buff);
            try{
                task->datetime->setDate(buff);
                cout << "Deadline godzina (hh:mm): ";
                getline(cin>>ws, buff);
                task->datetime->setTime(buff);
                taskList.addTask(task);
            } catch (InvalidDateFormat e){
                cout << e.what() << endl;
            } catch (InvalidTimeFormat e){
                cout << e.what() << endl;
            }
            continue;

            case Menu::Save:
            cout << "Nazwa pliku: ";
            getline(cin>>ws, filename);
            try{
                taskList.save(filename);
            }
            catch (...){
                cout << "\x1B[31mmTodos nie mogły zostać zapisane\033[0" << endl;
            }
            continue;

            case Menu::Load:
            cout << "Nazwa pliku: ";
            getline(cin>>ws, filename);
            try{
                taskList.load(filename);
            }
            catch (...){
                cout << "\x1B[31mTodos nie mogły zostać wczytane\033[0m" << endl;
            }
            continue;

            case Menu::Exit:
            break;

            default:
            cout<<"\x1B[31mNieprawidłowy wybór\033[0m"<< endl;
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
        cout << "\x1B[31mNieprawidłowy wybór: \033[0m" << buff << endl;
        return;
    } catch (out_of_range) {
        cout << "\x1B[31mTask o podanym ID nieistnieje :( \033[0m" << selectionId << endl;
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
            cout << "\x1B[31mNieprawidłowy wybór.\033[0m" << endl;
        }
        selectedTaskId = -1;
        break;
    }
}
