/* anichkay */

#ifndef STATE_H
#define STATE_H

/*
 * STATE module interface
 * Structure and operations for state/country data
 * with file I/O support
 */

#define MAX_STR    100
#define MAX_STATES 20

/* Country/State record */
typedef struct {
        char    name[MAX_STR];       /* country name */
        char    capital[MAX_STR];    /* capital city */
        char    language[MAX_STR];   /* official language */
        long    population;          /* population */
        double  area;                /* territory area, km^2 */
        char    currency[MAX_STR];   /* currency */
        char    government[MAX_STR]; /* government type */
        char    head[MAX_STR];       /* head of state */
        char    continent[MAX_STR];  /* part of the world */
} State;

/* Read states from pipe-delimited text file */
int read_states(const char *filename,
                State *states,
                int max_size);

/* Write states to pipe-delimited text file */
int write_states(const char *filename,
                 State *states,
                 int count);

/* Input states from keyboard */
void input_states(State *states,
                  int *count,
                  int max_size);

/* Print single state */
void print_state(const State *s);

/* Print all states */
void print_all_states(State *states,
                      int count);

/* Filter and print European states with pop > min_pop */
int filter_europe(State *states,
                  int count,
                  long min_pop,
                  State *result);

#endif
