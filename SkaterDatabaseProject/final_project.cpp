#include "cmpt_error.h"  
#include <iostream>        
#include <fstream>         
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Amanda Ngo
// St.# : 301433193
// Email: ahn9@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////


#include "menu.h"
using namespace std;

int main(){
    Database file_database("database.txt");
    Menu test_menu(file_database);
    test_menu.in_use();
}