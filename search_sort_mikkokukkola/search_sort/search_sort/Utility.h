#ifndef _UTILITY_H_
#define _UTILITY_H_
//Checks if users input is integer and between min and max.
//Returns inputted integer.
enum Error_code {
	success, fail, range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error
};
#endif //ifndef _UTILITY_H_
