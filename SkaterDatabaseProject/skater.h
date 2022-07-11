#include "cmpt_error.h"  
#include <iostream>        
#include <fstream>         
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <ctime>  
#include <cassert>
#include <string>

using namespace std;

class Skater{
	private:
        string name;
		string discipline;
		string country;
		int medals;
	public:
		Skater() : name("name"), discipline("discipline"), country("country"), medals(0){}

		Skater(const string& n, const string& d, const string& c, const int t) 
			: name(n), discipline(d), country(c), medals(t){}
		
		string get_name(){
			return name;
		}

		string get_discipline(){
			return discipline;
		}

		string get_country(){
			return country;
		}

		int get_medals(){
			return medals;
		}
		
		void set_name(const string& set_n){
			name = set_n;
		}
		void set_discipline(const string& set_d){
			discipline = set_d;
		}
		void set_country(const string& set_c){
			country = set_c;
		}
		void set_medals(const int& set_m){
			medals = set_m;
		}
};
