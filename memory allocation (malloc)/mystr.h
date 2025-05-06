//want soething like python strings but mutable
//writing in pseudopython
/*s = "abc";
s[1] = 'z'; //make s be 'azc'
s.append('d')*/
//want to initialize the string. 
//want to be able to change a character at an index
// want to be able to append

// #block is [a b \'0']
//capacity is teh size of the block
// sz = 2
#if !defined(MYSTR_H)
typedef struct mystr{
    char *block; 
    int sz; //keep track of the stting length
    int capacity; //keep track of the size of the block
}mystr;

#endif
