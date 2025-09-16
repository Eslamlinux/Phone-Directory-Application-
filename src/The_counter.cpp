#include <header/The_counter.h>

Count CountResult ;

long long int curentCount = (CountResult.Count_Data - CountResult.Count_deleted) ; // current count of data in the tree
long long int Count_not_saved = CountResult.Count_deleted + CountResult.Count_new_contact ; // count of changes not yet saved to the file
long long int Count_saved = 0; // count of changes saved to the file
long long int Count_all_deleted = 0; // count of all deletions