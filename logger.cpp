#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include "logger.h"
using namespace std;

Logger::Logger(){
    
}

void Logger::load(std::ifstream& ins){
    Ticket ticket;
    ins >> ticket;

    while (!ins.eof()){
        add(ticket);
        ins >> ticket;
    }
}

void Logger::add(const Ticket& tmp){
    logs.push_back(tmp);
    for (int i = 0; i < logs.size(); i++){
        for (int j = 1; j < logs.size(); j++){
            if (stoi(logs[j].getDate().substr(0, 2)) <= stoi(logs[i].getDate().substr(0, 2))
            && stoi(logs[j].getDate().substr(3, 2)) <= stoi(logs[i].getDate().substr(3, 2))
            && stoi(logs[j].getDate().substr(6, 2)) <= stoi(logs[i].getDate().substr(6, 2))){
                swap(logs[j], logs[i]);
            }
        }
    }
}

void Logger::remove(const std::string removeDate, const std::string removeReason){
    for (int i = 0; i < logs.size(); i++){
        if (logs[i].getDate() == removeDate && logs[i].getDetails() == removeReason){
            logs.erase(logs.begin() + i);
        }
    }
}

void Logger::display(std::ostream& outs)const{
    for (int i = 0; i < logs.size(); i++){
        outs << logs[i] << std::endl;
    }
}

Ticket Logger::find(const std::string& findDate, const std::string findReason){
    Ticket tmp;

    for (int i = 0; i < logs.size(); i++){
        if (logs[i].getDate() == findDate && logs[i].getDetails() == findReason){
            return logs[i];
        }
    }
    return tmp;
}

void Logger::display_Highest(){
    int maxElement = 0;
    float max = logs[0].getExpense();

    for (int i = 1; i < logs.size(); i++){
        if (max < logs[i].getExpense()){
            max = logs[i].getExpense();
            maxElement = i;
        }
    }

    std::cout << logs[maxElement] << std::endl;
}

void Logger::display_Average_Month(const std::string month, const std::string year){
    float sum = 0;
    int count = 0;
    string submonth, subyear;

    for (int i = 0; i < logs.size(); i++){
        submonth = logs[i].getDate().substr(0, 2);
        subyear = logs[i].getDate().substr(6, 2);
        if (submonth == month && subyear == year){
            sum += logs[i].getExpense();
            count++;
        }
    }

    std::cout << "$" << sum/count << std::endl;
}

void Logger::save(std::ostream& outs){
    for (int i = 0; i < logs.size(); i++){
        outs << logs[i] << std::endl;
    }
}