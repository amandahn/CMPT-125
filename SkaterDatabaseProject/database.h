#include "skater.h"

bool by_name(Skater& a, Skater& b){
	return a.get_name() <= b.get_name();
}

bool by_discipline(Skater& a, Skater& b){
	if(a.get_discipline() == b.get_discipline()){
		return by_name(a,b);
	}
	else{
		return a.get_discipline() < b.get_discipline();
	}
}

bool by_country(Skater& a, Skater& b){
	if(a.get_country() == b.get_country()){
		return by_name(a,b);
	}
	else{
		return a.get_country() < b.get_country();
	}
}

bool by_medal(Skater& a, Skater& b){
	if(a.get_medals() == b.get_medals()){
		return by_name(a,b);
	}
	else{
		return a.get_medals() < b.get_medals();
	}
}


class Database{
	private:
        int total;
		int capacity;
        Skater* skaters;
	public:
		Database() : total(0), capacity(10), skaters(new Skater[10]){}

		Database(int i) : total(i), capacity(i+10), skaters(new Skater[i+10]){
			if (i < 0){
				cmpt::error("ERROR: negative size not permitted.\n");
			}
		}

		Database(const string& fname){
			ifstream fin_count;
			total = 0;
			fin_count.open(fname);
			string l;
			while (getline(fin_count, l)){
				total++;
			}
			fin_count.close();
			capacity = total + 10;
			skaters = new Skater[capacity];

			ifstream fin;
			fin.open(fname);
			string line;
			int i = 0;
			while (getline(fin, line)){
				string n = line.substr(0, line.find(","));
				line.erase(0, line.find(",")+1);
				string g = line.substr(0, line.find(","));
				line.erase(0, line.find(",")+1);
				string c = line.substr(0, line.find(","));
				line.erase(0, line.find(",")+1);
				string t = line.substr(0, line.find(","));
				int tot = stoi(t);
				Skater curr(n, g, c, tot);
				skaters[i] = curr;
				i++;
			}
			fin.close();
		}

		int get_total(){
			return total;
		}

		void set_total(const int& i){
			total = i;
		}
		
		Skater* get_skaters(){
			return skaters;
		}

		Skater get_skater(int& i){
			if(i < 0 || i >= total){
				cmpt::error("ERROR: index out of range.");
			}
			return skaters[i];
		}

		void write_data(int i){
			if(i < 0){
				cmpt::error("ERROR: negative index invalid.\n");
			}
			if(i >= total){
				cmpt::error("ERROR: index too large.\n");
			}
			cout << "NAME: " << skaters[i].get_name() << " | DISCIPLINE: " 
				<< skaters[i].get_discipline() << " | COUNTRY: " 
				<< skaters[i].get_country() << " | MEDALS: " << skaters[i].get_medals() << "\n";
		}

		void get_skater_name(const string& name){
			bool found = false;
			for(int i=0; i<total; i++){
				if(skaters[i].get_name() == name){
					found = true;
					write_data(i);
				}
			}
			if(found == false){
				cout << "Skater not found, please try again.\n";
			}
		}

		void get_skater_namesubstr(const string& name_sub){
			bool found = false;
			for(int i=0; i<total; i++){
				if(skaters[i].get_name().find(name_sub) != string::npos){
					found = true;
					write_data(i);
				}
			}
			if(found == false){
				cout << "Skater(s) not found, please try again.\n";
			}
		}

		void get_skater_medals(const int& medal){
			bool found = false;
			for(int i=0; i<total; i++){
				if(skaters[i].get_medals() == medal){
					write_data(i);
				}
			}
			if(found == false){
				cout << "Skater not found, please try again.\n";
			}
		}

		void get_skater_range(int& first, int& last){
			if(total == 0){
				cmpt::error("ERROR: no values to delete.\n");
			}
			if(first < 0){
				cmpt::error("ERROR: no values to delete.\n");
			}
			if(first == last){
				cmpt::error("ERROR: trying to remove one index. Use remove_skater() instead.\n");
			}

			if(first > last){
				cmpt::error("ERROR: first index cannot be greater than last.\n");
			}

			if(last >= total){
				cmpt::error("ERROR: last index too large.\n");
			}

			bool found = false;

			for(int i=0; i<total; i++){
				if(i >= first && i <= last){
					found = true;
					write_data(i);
				}
			}

			if(found == false){
				cout << "Skater not found, please try again.\n";
			}
		}

		void get_skater_discipline(string& discipline){
			bool found = false;
			for(int i=0; i<total; i++){
                if(skaters[i].get_discipline() == discipline){
					found = true;
                    write_data(i);
                }
            }
			if(found == false){
				cout << "Discipline not found, please try again.\n";
			}
		}

		void get_skater_country(string& country){
			bool found = false;
			for(int i=0; i<total; i++){
                if (skaters[i].get_country() == country){
					found = true;
                    write_data(i);
                }
            }
			if(found == false){
				cout << "Country not found, please try again.\n";
			}
		}
	
		void append_skater(Skater& new_skater){
			if(capacity > total){
				total ++;
				skaters[total-1] = new_skater;

			}
			if(capacity <= total){
				capacity = capacity + 10;
				Skater* new_data = new Skater[capacity];
				for(int i=0; i<total; i++){
					new_data[i] = skaters[i];
				}
				new_data[total] = new_skater;
				total ++;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater(int remove){
			if(total == 0){
				cmpt::error("ERROR: no values to delete.\n");
			}
			if(remove >= total){
				cmpt::error("ERROR: index too large.\n");
			}
			else{
				bool found = false;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(i == remove){
						found = true;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove skater.\n";
				}
				total--;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater_range(int first, int last){
			if(total == 0){
				cmpt::error("ERROR: no values to delete.\n");
			}
			if(first < 0){
				cmpt::error("ERROR: no values to delete.\n");
			}
			if(first == last){
				cmpt::error("ERROR: trying to remove one index. Use remove_skater() instead.\n");
			}

			if(first > last){
				cmpt::error("ERROR: first index cannot be greater than last.\n");
			}

			if(last >= total){
				cmpt::error("ERROR: last index too large.\n");
			}
			else{
				bool found = false;
				int new_total = total;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(i >= first && i <= last){
						found = true;
						new_total--;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove one or more skaters.\n";
				}
				total = new_total;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater_name(string& name){
			if(total == 0){
				cout << "No values to remove.\n";
			}
			else{
				bool found = false;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(skaters[i].get_name() == name){
						found = true;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove skater.\n";
				}
				total--;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater_namesubstr(string& name_sub){
			if(total == 0){
				cout << "No values to remove.\n";
			}
			else{
				bool found = false;
				int new_total = total;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(skaters[i].get_name().find(name_sub) != string::npos){
						found = true;
						new_total--;;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove one or more skaters.\n";
				}
				total = new_total;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater_discipline(string& discipline){
			if(total == 0){
				cout << "No values to remove.\n";
			}
			else{
				bool found = false;
				int new_total = total;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(skaters[i].get_discipline() == discipline){
						found = true;
						new_total--;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove one or more skaters.\n";
				}
				total = new_total;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater_discipline(const string& discipline){
			if(total == 0){
				cout << "No values to remove.\n";
			}
			else{
				bool found = false;
				int new_total = total;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(skaters[i].get_discipline() == discipline){
						found = true;
						new_total--;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove one or more skaters.\n";
				}
				total = new_total;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void remove_skater_country(const string& country){
			if(total == 0){
				cout << "No values to remove.\n";
			}
			else{
				bool found = false;
				int new_total = total;
				Skater* new_data = new Skater[total+10];
				int j = 0;
				for(int i=0; i<total; i++){
					if(skaters[i].get_country() == country){
						found = true;
						new_total--;
					}
					else{
						new_data[j] = skaters[i];
						j++;
					}
				}
				if(found == false){
					cout << "Unable to remove one or more skaters.\n";
				}
				total = new_total;
				delete[] skaters;
				skaters = new_data;
			}
		}

		void sort_alpha_asc(){
			std::sort(skaters, skaters + total, by_name);
		}

		void sort_alpha_rev(){
			sort_alpha_asc();
			std::reverse(skaters, skaters + total);
		}

		void sort_discipline_asc(){
			std::sort(skaters, skaters + total, by_discipline);
		}

		void sort_discipline_rev(){
			sort_discipline_asc();
			std::reverse(skaters, skaters + total);
		}

		void sort_country_asc(){
			std::sort(skaters, skaters + total, by_country);
		}

		void sort_country_rev(){
			sort_country_asc();
			std::reverse(skaters, skaters + total);
		}

		void sort_medals_asc(){
			std::sort(skaters, skaters + total, by_medal);
		}

		void sort_medals_rev(){
			sort_medals_asc();
			std::reverse(skaters, skaters + total);
		}
};

/* Sorting information was taken from here:
https://publish.obsidian.md/cmpt125/The+STL+and+generic+programming */
