/*
 * This file is part of the VSS-Vision project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef SQLITE_H
#define SQLITE_H

#include <stdio.h>

#include "iostream"
#include "sstream"

#include <sqlite3.h>

using namespace std;

//! This class is responsible for create, read, update and delete common::Calibration 's and common::ExecConfiguration 's 
class SQLite{
protected:
    sqlite3 *db;

    string path_database;
    string password;

    stringstream query;

    int status_db;
    char *error_query;
    const char* data;

    //! Print the data result from query in database
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
public:
    
    //! Default constructor: SQLite sql("name db", "pswd")
    SQLite(string, string);

    //! This method open the connection with the database
    void open();

    //! This metohd close the connection with the database
    void close();

    void insert_calibration();
    void select_calibration(string s = "");
};

#endif // SQLITE_H
