#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ticket.h"
#ifndef LOGGER_H
#define LOGGER_H

  class Logger{
    public:
      //Constructor
      Logger();
      
      /*
      * Function: load
      * Pre-conditions: istream is connected to an open file
      * Post-conditions: Fills Logger object with Tickets
      */
      void load(std::ifstream& ins);

      /*
      * Function: add
      * Pre-conditions: None
      * Post-conditions: Ticket object is added to end of Logger vector
      */
      void add(const Ticket& tmp);

      /*
      * Function: remove
      * Pre-conditions: None
      * Post-conditions: removes Ticket object from Logger vector
      */
      void remove(const std::string removeDate, const std::string removeReason);

      /*
      * Function: display
      * Pre-conditions: None
      * Post-conditions: Displays all tickets to screen
      */
      void display(std::ostream& outs)const;

      /*
      * Function: find
      * Pre-conditions: None
      * Post-conditions: Displays Ticket object to screen
      */
      Ticket find(const std::string& findDate, const std::string findReason);

      /*
      * Function: display_Highest
      * Pre-conditions: None
      * Post-conditions: Displays Ticket with highest expense
      */
      void display_Highest();

      /*
      * Function: display_Average_Month
      * Pre-conditions: None
      * Post-conditions: Displays average expense for specific year and month
      */
      void display_Average_Month(const std::string month, const std::string year);

      /*
      * Function: save
      * Pre-conditions: None
      * Post-conditions: Outputs data into output file
      */
      void save(std::ostream& outs);

    private:
      std::vector<Ticket> logs;
  };
#endif