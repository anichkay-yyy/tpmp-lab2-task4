/* anichkay */

/*
 * State data client with file I/O
 * Reads country data from text file, filters European states
 * with population > 8 million, saves results to output file
 */

#include <stdio.h>
#include <string.h>

#include "state.h"

#define INPUT_FILE  "data/states.txt"
#define OUTPUT_FILE "data/result.txt"
#define MIN_POP     8000000

int
main(void)
{
        State states[MAX_STATES];
        State filtered[MAX_STATES];
        int   count = 0;
        int   fcount = 0;
        int   choice;

        printf("=== State Data Processor ===\n");
        printf("1. Read data from file (%s)\n", INPUT_FILE);
        printf("2. Input data from keyboard\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 2) {
                /* input from keyboard and save to file */
                input_states(states, &count, MAX_STATES);
                write_states(INPUT_FILE, states, count);
        } else {
                /* read from file */
                count = read_states(INPUT_FILE, states, MAX_STATES);
                if (count == 0) {
                        printf("No data loaded. Exiting.\n");
                        return 1;
                }
        }

        /* display all states */
        print_all_states(states, count);

        /* filter European states with population > 8 million */
        fcount = filter_europe(states, count, MIN_POP, filtered);

        printf("\n=== European states with population > %d ===\n",
               MIN_POP);

        if (fcount > 0) {
                print_all_states(filtered, fcount);

                /* save filtered results */
                write_states(OUTPUT_FILE, filtered, fcount);
        } else {
                printf("No matching states found.\n");
        }

        return 0;
}
