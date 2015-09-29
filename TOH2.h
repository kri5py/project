void initialize (int disks, int peg_A[8], int peg_B[8], int peg_C[8]);
void get_number_of_disks(int *disks);
void print_status(int disks, int peg_A[8], int peg_B[8], int peg_C[8]);
void print_no_disk(char *choice_from);
int validate_move_from(char *choice_from, int peg_A[8], int peg_B[8], 
int
peg_C[8]);
int validate_move_to(int disks, char choice_from, char *choice_to, int
*index_from, int peg_A[8], int peg_B[8], int peg_C[8]);
void disk_on_top(int disks, int *top_of_stack_to, char choice_to, int
peg_A[8],
int peg_B[8], int peg_C[8]);
void move_disk(int disks, char choice_from, char choice_to, int
index_from, int peg_A[8], int peg_B[8], int peg_C[8]);
