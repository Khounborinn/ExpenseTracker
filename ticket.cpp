#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ticket.h"
using namespace std;

Ticket::Ticket()
{
  date = "xx/xx/xx";
  detail = "xxxx";
  expense = 0;
}

void Ticket::setDate(const std::string inputDate){
    date = inputDate;
}

void Ticket::setDetails(const std::string inputDetail){
    detail = inputDetail;
}

void Ticket::setExpense(const float inputExpense){
    expense = inputExpense;
}

std::string Ticket::getDate(){
    return date;
}

std::string Ticket::getDetails(){
    return detail;
}

float Ticket::getExpense(){
    return expense;
}

void Ticket::input(std::istream& ins)
{
  if (&ins == &cin)
  {
    cout << "Date of Expense:         ";
    getline(ins, date);
    cout << "Reason for Expense:      ";
    getline(ins, detail);
    cout << "Amount spent on Expense: ";
    ins >> expense;
  }
  else
  {
    while (ins.peek() == '\n' || ins.peek() == '\r')
    {
      ins.ignore();
    }
    getline(ins, date);
    getline(ins, detail);
    ins >> expense;
  }
}

void Ticket::output(std::ostream& outs)const
{
  if (&outs == &cout)
  {
    outs << "Date of Expense:         " << date << endl;
    outs << "Reason for Expense:      " << detail << endl;
    outs << "Amount spent on Expense: " << expense << endl;
  }
  else
  {
    outs << date << endl;
    outs << detail << endl;
    outs << expense << endl;
  }
}

std::istream& operator >>(std::istream& ins, Ticket& t)
{
  t.input(ins);
  return ins;
}

std::ostream& operator <<(std::ostream& outs, const Ticket& t)
{
  t.output(outs);
  return outs;
}
