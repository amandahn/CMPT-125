#include "database.h"

// CURRENT ISSUES
// If time, create edit options

class Menu{
    private:
        Database records;
    public:
        Menu(const Database& input) : records(input){}

        void in_use(){
            bool use = true;
            cout << "WELCOME TO THE SKATERS DATABASE\n";
            line_break();
            while(use){
                cout << "MAIN MENU\n";
                line_break();
                cout << "\nTo add a record, enter ADD\n";
                cout << "To search for a record, enter SEARCH\n";
                cout << "To delete a record, enter DELETE\n";
                cout << "To view a list of records, enter LIST\n";
                cout << "To leave, enter LEAVE.\n";
                string user_input;
                string upper;
                getline(cin, user_input);
                for(int i=0 ; i<user_input.size(); i++){
                    upper += toupper(user_input[i]);
                    if(i == user_input.size() -1){
                        user_input = upper;
                    }
                }
                if(user_input == "LEAVE"){
                    leave("database.txt");
                    cout << "\nEXITING DATABASE\n";
                    use = false;
                }
                if(user_input == "ADD"){
                    cout << "\nEntering record adding interface...\n";
                    line_break();
                    add_skater();
                }
                if(user_input == "SEARCH"){
                    cout << "\nEntering record search menu...\n";
                    line_break();
                    search();
                }
                if(user_input == "DELETE"){
                    cout << "\nEntering record delete menu...\n";
                    line_break();
                    delete_skater();
                }
                if(user_input == "LIST"){
                    cout << "\nEntering record listing menu...\n";
                    line_break();
                    listing();
                }
            }
        }

        void line_break(){
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\n";
        }

        void add_skater(){
            string add_input;
            string n;
            string d;
            string c;
            int m;
            bool adding = true;
            while(adding){
                bool get_name = true;
                while(get_name){
                    bool name_exists = false;
                    cout << "Enter skater name:\n";
                    string upper_n;
                    getline(cin, n);
                    for(int i=0 ; i<n.size(); i++){
                        upper_n += toupper(n[i]);
                        if(i == n.size()-1){
                            n = upper_n;
                        }
                    }
                    for(int i=0; i<records.get_total(); i++){
                        if(records.get_skater(i).get_name() == n){
                            cout << "Skater already exists in data.\n";
                            cout << "To edit skater information, please use the EDIT function.\n";
                            name_exists = true;
                            break;
                        }
                    }
                    if(name_exists == false){
                        bool not_string = false;
                        for(int i=0; i<n.size(); i++){
                            if(isalpha(n[i]) == false && n[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                        }
                        if(not_string == false){
                            get_name = false;
                        }
                    }
                }

                bool get_discipline = true;
                while(get_discipline){
                    cout << "Enter skater discipline:\n";
                    string upper_d;
                    getline(cin, d);
                    for(int i=0 ; i<d.size(); i++){
                        upper_d += toupper(d[i]);
                        if(i == d.size()- 1){
                            d = upper_d;
                        }
                    }
                    bool not_string = false;
                    for(int i=0; i<d.size(); i++){
                        if(isalpha(d[i]) == false){
                            cout << "Please input a valid string.\n";
                            not_string = true;
                            break;
                        }
                    }
                    if(not_string == false){
                        get_discipline = false;
                    }
                }

                bool get_country = true;
                while(get_country){
                    cout << "Enter skater country:\n";
                    string upper_c;
                    getline(cin, c);
                    for(int i=0 ; i<c.size(); i++){
                        upper_c += toupper(c[i]);
                        if(i == c.size()-1){
                            c = upper_c;
                        }
                    }
                    bool not_string = false;
                    for(int i=0; i<c.size(); i++){
                        if(isalpha(c[i]) == false){
                            cout << "Please input a valid string.\n";
                            not_string = true;
                            break;
                        }
                    }
                    if(not_string == false){
                        get_country = false;
                    }
                }

                string temp;
                bool get_medals = true;
                while(get_medals){
                    cout << "Enter skater medal count:\n";
                    string temp_upper;
                    getline(cin, temp);
                    for(int i=0 ; i<temp.size(); i++){
                        temp_upper += toupper(temp[i]);
                        if(i == temp.size()-1){
                            temp = temp_upper;
                        }
                    }
                    bool not_int = false;
                    for(int i=0; i<temp.size(); i++){
                        if(isdigit(temp[i]) == false){
                            cout << "Please input a valid integer.\n";
                            not_int = true;
                            break;
                        }
                    }
                    if(not_int == false){
                        m = stoi(temp);
                        if(m < 0){
                            cout << "Medal count invalid.\n";
                            continue;
                        }
                        get_medals = false;
                    }
                }
    
                Skater new_skater(n, d, c, m);
                records.append_skater(new_skater);
                cout << "NEW RECORD ADDED: ";
                records.write_data(records.get_total() - 1);
                cout << "\n";
                cout << "Returning to main menu...\n";
                line_break();
                adding = false; 
            }
        }

        void search(){
            string search_input;
            bool searching = true;;
            cout << "To search by name, enter NAME\n";
            cout << "To search by name substring, enter SUBSTRING\n";
            cout << "To search by index, enter INDEX\n";
            cout << "To search by index range, enter RANGE\n";
            cout << "To search by discipline, enter DISCIPLINE\n";
            cout << "To search by country, enter COUNTRY\n";
            cout << "To return to the main menu, enter any other input.\n";
            string search_upper;
            getline(cin, search_input);
            for(int i=0 ; i<search_input.size(); i++){
                search_upper += toupper(search_input[i]);
                if(i == search_input.size() -1){
                    search_input = search_upper;
                }
            }
            while(searching){
                if(search_input == "NAME"){
                    string name_input;
                    line_break();
                    bool get_name = true;
                    while(get_name){
                        cout << "Enter the skater name you would like to find:\n";
                        string name_upper;
                        getline(cin, name_input);
                        for(int i=0 ; i<name_input.size(); i++){
                            name_upper += toupper(name_input[i]);
                            if(i == name_input.size()-1){
                                name_input = name_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<name_input.size(); i++){
                            if(isalpha(name_input[i]) == false && name_input[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == name_input.size()-1){
                                if(not_string == false){
                                    get_name = false;
                                }
                            }
                        }
                    }
                records.get_skater_name(name_input);
                line_break();
                searching = false;
                }
                if(search_input == "SUBSTRING"){
                    string substr_input;
                    line_break();
                    bool get_substr = true;
                    while(get_substr){
                        cout << "Enter the substring you would like to find\n";
                        string substr_upper;
                        getline(cin,substr_input);
                        for(int i=0 ; i<substr_input.size(); i++){
                            substr_upper += toupper(substr_input[i]);
                            if(i == substr_input.size()-1){
                                substr_input = substr_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<substr_input.size(); i++){
                            if(isalpha(substr_input[i]) == false && substr_input[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == substr_input.size()-1){
                                if(not_string == false){
                                    get_substr = false;
                                }
                            }
                        }
                    }
                    records.get_skater_namesubstr(substr_input);
                    line_break();
                    searching = false;
                }
                if(search_input == "INDEX"){
                    string index_input;
                    bool not_int = true;
                    line_break();
                    while(not_int){
                        cout << "Enter the index value you would like to find\n";
                        getline(cin,index_input);
                        for(int i=0; i<index_input.size(); i++){
                            if(isdigit(index_input[i]) == false){
                                cout << "Please input a valid integer.\n";
                                not_int = true;
                                break;
                            }
                            if(i == index_input.size()-1){
                                not_int = false;
                            }
                        }
                    }
                    int index = stoi(index_input);
                    records.write_data(index);
                    line_break();
                    searching = false;
                }
                if(search_input == "RANGE"){
                    string medals_input1;
                    string medals_input2;
                    bool get_int1 = true;
                    while(get_int1){
                        cout << "Enter the first index value you would like to find\n";
                        getline(cin,medals_input1);
                        for(int i=0; i<medals_input1.size(); i++){
                            if(isdigit(medals_input1[i]) == false){
                                cout << "Please input a valid integer.\n";
                                get_int1 = true;
                                break;
                            }
                            if(i == medals_input1.size()-1){
                                get_int1 = false;
                            }
                        }
                    }
                    int index_1 = stoi(medals_input1);
                    bool get_int2 = true;
                    while(get_int2){
                        cout << "Enter the second index value you would like to find\n";
                        getline(cin,medals_input2);
                        for(int i=0; i<medals_input2.size(); i++){
                            if(isdigit(medals_input2[i]) == false){
                                cout << "Please input a valid integer.\n";
                                get_int2 = true;
                                break;
                            }
                            if(i == medals_input2.size()-1){
                                get_int2 = false;
                            }
                        }
                    }
                    int index_2 = stoi(medals_input2);
                    records.get_skater_range(index_1,index_2);
                    line_break();
                    searching = false;
                }
                if(search_input == "DISCIPLINE"){
                    string discipline_input;
                    line_break();
                    bool get_discipline = true;
                    while(get_discipline){
                        cout << "Enter the discipline you would like to find\n";
                        string discipline_upper;
                        getline(cin,discipline_input);
                        for(int i=0 ; i<discipline_input.size(); i++){
                            discipline_upper += toupper(discipline_input[i]);
                            if(i == discipline_input.size()-1){
                                discipline_input = discipline_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<discipline_input.size(); i++){
                            if(isalpha(discipline_input[i]) == false && discipline_input[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == discipline_input.size()-1){
                                if(not_string == false){
                                    get_discipline = false;
                                }
                            }
                        }
                    }
                    records.get_skater_discipline(discipline_input);
                    line_break();
                    searching = false;
                }
                if(search_input == "COUNTRY"){
                    string country_input;
                    line_break();
                    bool get_country = true;
                    while(get_country){
                        cout << "Enter the country you would like to find\n";
                        string country_upper;
                        getline(cin,country_input);
                        for(int i=0 ; i<country_input.size(); i++){
                            country_upper += toupper(country_input[i]);
                            if(i == country_input.size()-1){
                                country_input = country_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<country_input.size(); i++){
                            if(isalpha(country_input[i]) == false && country_input[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == country_input.size()-1){
                                if(not_string == false){
                                    get_country = false;
                                }
                            }
                        }
                    }
                    records.get_skater_country(country_input);
                    searching = false;
                }
                else{
                    cout << "\nReturning to main menu...\n";
                    searching = false;
                    line_break();
                }
            }
        }

        void delete_skater(){
            string delete_input;
            cout << "To delete by name, enter NAME\n";
            cout << "To delete by name substring, enter SUBSTRING\n";
            cout << "To delete by index, enter INDEX\n";
            cout << "To delete by index range, enter RANGE\n";
            cout << "To delete by discipline, enter DISCIPLINE\n";
            cout << "To delete by country, enter COUNTRY\n";
            cout << "To return to the main menu, enter any other input.\n";
            string delete_upper;
            getline(cin, delete_input);
            for(int i=0 ; i<delete_input.size(); i++){
                delete_upper += toupper(delete_input[i]);
                if(i == delete_input.size()-1){
                    delete_input = delete_upper;
                }
            }
            if(delete_input == "NAME"){
                bool deleting = true;
                while(deleting){
                    string to_delete;
                    string confirm;
                    line_break();
                    bool get_input = true;
                    while(get_input){
                        cout << "Enter the name you'd like to remove\n";
                        string to_delete_upper;
                        getline(cin,to_delete);
                        for(int i=0 ; i<to_delete.size(); i++){
                            to_delete_upper += toupper(to_delete[i]);
                            if(i == to_delete.size()-1){
                                to_delete = to_delete_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<to_delete.size(); i++){
                            if(isalpha(to_delete[i]) == false && to_delete[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == to_delete.size()-1){
                                if(not_string == false){
                                    get_input = false;
                                }
                            }
                        }
                    }
                    cout << "YOU WANT TO DELETE:\n";
                    records.get_skater_name(to_delete);
                    cout << "Are you sure you would like to delete this record? (Y/N)\n";
                    cout << "If skater was not found, enter N to re-enter data.\n";
                    string confirm_upper;
                    getline(cin, confirm);
                    for(int i=0 ; i<confirm.size(); i++){
                        confirm_upper += toupper(confirm[i]);
                        if(i == confirm.size()-1){
                            confirm = confirm_upper;
                        }
                    }
                    if(confirm == "Y"){
                        records.remove_skater_name(to_delete);
                        cout << "Deleted skater " << to_delete << "\n";
                        cout << "\n";
                        cout << "Returning to main menu...\n";
                        line_break();
                        deleting = false;
                    }
                    else{
                        cout << "Confirmation failed.\n";
                        continue;
                    }
                }
                
            }
            if(delete_input == "SUBSTRING"){
                bool deleting = true;
                while(deleting){
                   string to_delete;
                    string confirm;
                    line_break();
                    bool get_input = true;
                    while(get_input){
                        cout << "Enter the substring you'd like to remove\n";
                        string to_delete_upper;
                        getline(cin,to_delete);
                        for(int i=0 ; i<to_delete.size(); i++){
                            to_delete_upper += toupper(to_delete[i]);
                            if(i == to_delete.size()-1){
                                to_delete = to_delete_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<to_delete.size(); i++){
                            if(isalpha(to_delete[i]) == false && to_delete[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == to_delete.size()-1){
                                if(not_string == false){
                                    get_input = false;
                                }
                            }
                        }
                    }
                    cout << "YOU WANT TO DELETE RECORDS: \n";
                    records.get_skater_namesubstr(to_delete);
                    cout << "Are you sure you would like to delete these records? (Y/N)\n";
                    string confirm_upper;
                    getline(cin, confirm);
                    for(int i=0 ; i<confirm.size(); i++){
                        confirm_upper += toupper(confirm[i]);
                        if(i == confirm.size()-1){
                            confirm = confirm_upper;
                        }
                    }
                    if(confirm == "Y"){
                        records.remove_skater_namesubstr(to_delete);
                        cout << "Deleted skaters with substring " << to_delete << "\n";
                        cout << "\n";
                        cout << "Returning to main menu...\n";
                        line_break();
                        deleting = false;
                    }
                    else{
                        cout << "Confirmation failed.\n";
                        continue;
                    }
                }
            }

            if(delete_input == "INDEX"){
                bool deleting = true;
                while(deleting){
                    string to_delete;
                    string confirm;
                    line_break();
                    bool get_input = true;
                    while(get_input){
                        cout << "Enter the name you'd like to remove\n";
                        getline(cin,to_delete);
                        bool not_digit = false;
                        for(int i=0; i<to_delete.size(); i++){
                            if(isdigit(to_delete[i]) == false){
                                cout << "Please input a valid integer.\n";
                                not_digit = true;
                                break;
                            }
                            if(i == to_delete.size()-1){
                                if(not_digit == false){
                                    get_input = false;
                                }
                            }
                        }
                    }
                    int index = stoi(to_delete);
                    cout << "YOU WANT TO DELETE:\n"; 
                    records.write_data(index);
                    cout << "\nAre you sure you would like to delete this skater? (Y/N)\n";
                    string confirm_upper;
                    getline(cin, confirm);
                    for(int i=0 ; i<confirm.size(); i++){
                        confirm_upper += toupper(confirm[i]);
                        if(i == confirm.size()-1){
                            confirm = confirm_upper;
                        }
                    }
                    if(confirm == "Y"){
                        records.remove_skater(index);
                        cout << "Deleted skater at index " << to_delete << "\n";
                        cout << "\n";
                        cout << "Returning to main menu...\n";
                        line_break();
                        deleting = false;
                    }
                    else{
                        cout << "Confirmation failed.\n";
                        continue;
                    }
                }
            }

            if(delete_input == "RANGE"){
                bool deleting = true;
                while(deleting){
                    string to_delete1;
                    string to_delete2;
                    string confirm;
                    bool get_int1 = true;
                    while(get_int1){
                        cout << "Enter the first index value you would like to delete\n";
                        getline(cin,to_delete1);
                        for(int i=0; i<to_delete1.size(); i++){
                            if(isdigit(to_delete1[i]) == false){
                                cout << "Please input a valid integer.\n";
                                get_int1 = true;
                                break;
                            }
                            if(i == to_delete1.size()-1){
                                get_int1 = false;
                            }
                        }
                    }
                    bool get_int2 = true;
                    while(get_int2){
                        cout << "Enter the second index value you would like to delete\n";
                        getline(cin,to_delete2);
                        for(int i=0; i<to_delete2.size(); i++){
                            if(isdigit(to_delete2[i]) == false){
                                cout << "Please input a valid integer.\n";
                                get_int2 = true;
                                break;
                            }
                            if(i == to_delete2.size()-1){
                                get_int2 = false;
                            }
                        }
                    }
                    int index1 = stoi(to_delete1);
                    int index2 = stoi(to_delete2);
                    cout << "YOU WANT TO DELETE:\n";
                    records.get_skater_range(index1, index2);
                    cout << "\nAre you sure you would like to delete these skaters? (Y/N)\n";
                    string confirm_upper;
                    getline(cin, confirm);
                    for(int i=0 ; i<confirm.size(); i++){
                        confirm_upper += toupper(confirm[i]);
                        if(i == confirm.size()-1){
                            confirm = confirm_upper;
                        }
                    }
                    if(confirm == "Y"){
                        records.remove_skater_range(index1,index2);
                        cout << "Deleted skaters from index " << index1 << " to " 
                            << index2 << "\n";
                        cout << "\n";
                        cout << "Returning to main menu...\n";
                        line_break();
                        deleting = false;
                    }
                    else{
                        cout << "Confirmation failed.\n";
                        continue;
                    }
                }
            }
            if(delete_input == "DISCIPLINE"){
                bool deleting = true;
                while(deleting){
                    string to_delete;
                    string confirm;
                    line_break();
                    bool get_input = true;
                    while(get_input){
                        cout << "Enter the discipline you'd like to remove\n";
                        string to_delete_upper;
                        getline(cin,to_delete);
                        for(int i=0 ; i<to_delete.size(); i++){
                            to_delete_upper += toupper(to_delete[i]);
                            if(i == to_delete.size()-1){
                                to_delete = to_delete_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<to_delete.size(); i++){
                            if(isalpha(to_delete[i]) == false && to_delete[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == to_delete.size()-1){
                                if(not_string == false){
                                    get_input = false;
                                }
                            }
                        }
                    }
                    cout << "YOU WANT TO DELETE:\n";
                    records.get_skater_discipline(to_delete);
                    cout << "Are you sure you would like to delete these records? (Y/N)\n";
                    string confirm_upper;
                    getline(cin, confirm);
                    for(int i=0 ; i<confirm.size(); i++){
                        confirm_upper += toupper(confirm[i]);
                        if(i == confirm.size()-1){
                            confirm = confirm_upper;
                        }
                    }
                    if(confirm == "Y"){
                        records.remove_skater_discipline(to_delete);
                        cout << "Deleted discipline " << to_delete << "\n";
                        cout << "\n";
                        cout << "Returning to main menu...\n";
                        line_break();
                        deleting = false;
                    }
                    else{
                        cout << "Confirmation failed.\n";
                        continue;
                    }
                }
                
            }
            if(delete_input == "COUNTRY"){
                bool deleting = true;
                while(deleting){
                    string to_delete;
                    string confirm;
                    line_break();
                    bool get_input = true;
                    while(get_input){
                        cout << "Enter the country you'd like to remove\n";
                        string to_delete_upper;
                        getline(cin,to_delete);
                        for(int i=0 ; i<to_delete.size(); i++){
                            to_delete_upper += toupper(to_delete[i]);
                            if(i == to_delete.size()-1){
                                to_delete = to_delete_upper;
                            }
                        }
                        bool not_string = false;
                        for(int i=0; i<to_delete.size(); i++){
                            if(isalpha(to_delete[i]) == false && to_delete[i] != 32){
                                cout << "Please input a valid string.\n";
                                not_string = true;
                                break;
                            }
                            if(i == to_delete.size()-1){
                                if(not_string == false){
                                    get_input = false;
                                }
                            }
                        }
                    }
                    cout << "YOU WANT TO DELETE:\n";
                    records.get_skater_country(to_delete);
                    cout << "Are you sure you would like to delete these records? (Y/N)\n";
                    string confirm_upper;
                    getline(cin, confirm);
                    for(int i=0 ; i<confirm.size(); i++){
                        confirm_upper += toupper(confirm[i]);
                        if(i == confirm.size()-1){
                            confirm = confirm_upper;
                        }
                    }
                    if(confirm == "Y"){
                        records.remove_skater_country(to_delete);
                        cout << "Deleted country " << to_delete << "\n";
                        cout << "\n";
                        cout << "Returning to main menu...\n";
                        line_break();
                        deleting = false;
                    }
                    else{
                        cout << "Confirmation failed.\n";
                        continue;
                    }
                }    
            }
            else{
                cout << "Returning to main menu...\n";
                line_break();
            }
        }

        void listing(){
            string listing_input;
            cout << "To list in alphabetical order, enter ALPHABETICAL\n";
            cout << "To list in reverse alphabetical order, enter REVERSE ALPHABETICAL\n";
            cout << "To list in ascending discipline order, enter DISCIPLINE ASCENDING\n";
            cout << "To list in descending discipline  order, enter DISCIPLINE DESCENDING\n";
            cout << "To list in ascending country order, enter COUNTRY ASCENDING\n";
            cout << "To list in descending country order, enter COUNTRY DESCENDING\n";
            cout << "To list in ascending medal order, enter MEDALS ASCENDING\n";
            cout << "To list in descending medal order, enter MEDALS DESCENDING\n";
            cout << "To return to the main menu, enter any other input.\n";
            string listing_upper;
            getline(cin, listing_input);
            for(int i=0 ; i<listing_input.size(); i++){
                listing_upper += toupper(listing_input[i]);
                if(i == listing_input.size()-1){
                    listing_input = listing_upper;
                }
            }
            if(listing_input == "ALPHABETICAL"){
                records.sort_alpha_asc();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "REVERSE ALPHABETICAL"){
                records.sort_alpha_rev();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "DISCIPLINE ASCENDING"){
                records.sort_discipline_asc();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "DISCIPLINE DESCENDING"){
                records.sort_discipline_rev();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "COUNTRY ASCENDING"){
                records.sort_country_asc();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "COUNTRY DESCENDING"){
                records.sort_country_rev();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "MEDALS ASCENDING"){
                records.sort_medals_asc();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            if(listing_input == "MEDALS DESCENDING"){
                records.sort_medals_rev();
                 for(int i=0; i<records.get_total(); i++){
                    records.write_data(i);
                }
            }
            else{
                cout << "Returning to main menu...\n";
                line_break();
            }
        }

        void leave(const string& fname){
            ofstream fout;
            fout.open(fname);
            for(int i=0;i < records.get_total(); i++){
                Skater curr = records.get_skater(i);
                if(i == records.get_total() - 1){
                    fout << curr.get_name();
                    fout << ",";
                    fout << curr.get_discipline();
                    fout << ",";
                    fout << curr.get_country();
                    fout << ",";
                    fout << curr.get_medals();
                }
                else{
                    fout << curr.get_name();
                    fout << ",";
                    fout << curr.get_discipline();
                    fout << ",";
                    fout << curr.get_country();
                    fout << ",";
                    fout << curr.get_medals();
                    fout << "\n";
                }
            }
            fout.close();
        }

        ~Menu(){
            delete[] records.get_skaters();
        }
};
