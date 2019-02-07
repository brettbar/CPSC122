int numbers[10] = { 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 }; // Valid
int matrix[5] = { 1, 2, 3, 4, 5, 6, 7 }; // Invalid, given definition is greater than index of 5
double radii[10] = { 3.2, 4.7 }; // Technically valid, all values after index 0 and 1 will be filled with default value of 0
int table[7] = { 2, , , 27, , 45, 39 }; // Invalid, blank index values can not be given
char codes[] = { ’A’, ’X’, ’1’, ’2’, ’s’ }; // Valid	
int blanks[]; // Valid