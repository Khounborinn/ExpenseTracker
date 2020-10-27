#include<iostream>
#include<fstream>
#include "ticket.h"
#include "logger.h"
using namespace std;

int menu();

int main(){
    Ticket tmp;
    Logger logger;
    int choice;
    string date;
    string reason;
    string month;
    string year;
    ofstream outs;
    ifstream ins;
    ins.open("Expenses.txt");

    if(!ins.fail()){
	logger.load(ins);
	ins.close();
    }

    do{
	choice = menu();
	switch(choice){
	    case 1:
		cin>>tmp;
		logger.add(tmp);
		break;
	    case 2:
		logger.display(cout);
		break;
	    case 3:
		cout << "Name the date and reason of the ticket you want to remove.\n";
        cout << "Date (xx/xx/xx format): ";
		while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,date);
        cout << "Reason: ";
        while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,reason);
		logger.remove(date, reason);
		break;
	    case 4:
		cout<<"Name the ticket by date and reason you wish to view:\n";
        cout << "Date (xx/xx/xx format): ";
		while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,date);
        cout << "Reason: ";
        while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,reason);
		cout<<tmp;
		break;
	    case 5:
		logger.display_Highest();
		break;
	    case 6:
        cout << "Enter a month (ex: 01 for January) and year (ex: 10 for 2010) you wish to find the monthly average:\n";
        cout << "Month: ";
		while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,month);
        cout << "Year: ";
        while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,year);
		logger.display_Average_Month(month, year);
		break;
	    case 0:
		cout<<"Good-bye.\n";
		break;
	    default:
		cout<<"Not an option.\n";
		break;
	    } // bottom of the switch
	} while(choice != 0);
        // bottom of the while
    	outs.open("Expenses.txt");
	if(outs.fail())
	    cout<<"Unable to save data to file.\n";
	else
	    logger.save(outs);
	outs.close();
return 0;
} // bottom of the main

int menu(){
   int choice;
   cout<<"Managing Expenses.\nChoose from the selections below:\n";
   cout<<"1) Add a new expense.\n";
   cout<<"2) Display all expenses.\n";
   cout<<"3) Remove am expense from the logs.\n";
   cout<<"4) Find out information about a particular date and reason.\n";
   cout<<"5) Display ticket with greatest expense.\n";
   cout<<"6) Display the average income for tickets in a given month and year.\n";
   cout<<"0) Quit, saving all changes to the database.\n";
   cin>>choice;
   if(cin.peek() == '\n') cin.ignore();
   return choice;
}
