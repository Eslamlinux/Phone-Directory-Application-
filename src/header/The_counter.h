class Count{
    public:
long long int Count_Data = 0; // count of data in the tree when loaded from file
long long int Count_changes = 0; // count of changes made during the session
long long int Count_saved = 0; // count of changes saved to the file
long long int Count_not_saved ; // count of changes not yet saved to the file
long long int Count_deleted = 0; // count of deletions made during the session
long long int Count_all_deleted ; // count of all deletions 
long long int Count_new_contact = 0; // count of deletions not yet saved to the file
long long int curentCount ; // current count of data in the tree


};

extern Count CountResult ;