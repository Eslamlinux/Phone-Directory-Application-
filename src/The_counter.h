class Count{
    public:
long long int Count_Data = 0; // count of data in the tree when loaded from file
long long int Count_changes = 0; // count of changes made during the session
long long int curentCount = Count_Data + Count_changes ; // current count of data in the tree


};

extern Count CountResult ;