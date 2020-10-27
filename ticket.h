#include<iostream>
#include<string>
#include<fstream>
#ifndef TICKET_H
#define TICKET_H

  class Ticket{
	public:
		//Constructor
		Ticket();
		
		//setters
		/*
		* Function: setDate
		* Pre-conditions: None
		* Post-conditions: Date variable is changed in Ticket object
		*/
		void setDate(const std::string date);

		/*
		* Function: setDetails
		* Pre-conditions: None
		* Post-conditions: Detail variable is changed in Ticket object
		*/
		void setDetails(const std::string detail);

		/*
		* Function: setExpense
		* Pre-conditions: None
		* Post-conditions: Expense variable is changed in Ticket object
		*/
		void setExpense(const float expense);

		//getters
		/*
		* Function: setDate
		* Pre-conditions: None
		* Post-conditions: returns string
		*/
		std::string getDate();

		/*
		* Function: setDate
		* Pre-conditions: None
		* Post-conditions: returns string
		*/
		std::string getDetails();

		/*
		* Function: setDate
		* Pre-conditions: None
		* Post-conditions: returns float
		*/
		float getExpense();

		//Input and Output
		void input(std::istream& ins);
		void output(std::ostream& outs)const;

	private:
		std::string date;
		std::string detail;
		float expense;
  };

  //overloaded i/o operators
  std::istream& operator >>(std::istream& ins, Ticket& h);
  std::ostream& operator <<(std::ostream& outs, const Ticket& h);

#endif
