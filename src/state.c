/* anichkay */

/*
 * STATE module implementation (server)
 * File I/O, input, filtering operations
 * for State structures
 */

#include <stdio.h>
#include <string.h>

#include "state.h"

int
read_states(const char *filename,
            State *states,
            int max_size)
{
        FILE *fp;
        int   count = 0;
        char  line[1024];

        fp = fopen(filename, "r");
        if (!fp) {
                printf("Error: cannot open file %s\n", filename);
                return 0;
        }

        while (fgets(line, sizeof(line), fp) && count < max_size) {
                line[strcspn(line, "\n")] = '\0';

                /* skip empty lines */
                if (line[0] == '\0')
                        continue;

                if (sscanf(line,
                           "%[^|]|%[^|]|%[^|]|%ld|%lf|%[^|]|%[^|]|%[^|]|%[^\n]",
                           states[count].name,
                           states[count].capital,
                           states[count].language,
                           &states[count].population,
                           &states[count].area,
                           states[count].currency,
                           states[count].government,
                           states[count].head,
                           states[count].continent) == 9) {
                        count++;
                }
        }

        fclose(fp);
        printf("Read %d states from %s\n", count, filename);
        return count;
}

int
write_states(const char *filename,
             State *states,
             int count)
{
        FILE *fp;
        int   i;

        fp = fopen(filename, "w");
        if (!fp) {
                printf("Error: cannot create file %s\n", filename);
                return 0;
        }

        for (i = 0; i < count; i++) {
                fprintf(fp,
                        "%s|%s|%s|%ld|%.1f|%s|%s|%s|%s\n",
                        states[i].name,
                        states[i].capital,
                        states[i].language,
                        states[i].population,
                        states[i].area,
                        states[i].currency,
                        states[i].government,
                        states[i].head,
                        states[i].continent);
        }

        fclose(fp);
        printf("Wrote %d states to %s\n", count, filename);
        return 1;
}

void
input_states(State *states,
             int *count,
             int max_size)
{
        int i;
        int n;

        printf("Enter number of states (max %d): ", max_size);
        scanf("%d", &n);
        getchar();

        if (n > max_size)
                n = max_size;
        if (n < 1)
                n = 1;

        for (i = 0; i < n; i++) {
                printf("\n--- State %d ---\n", i + 1);

                printf("Country name: ");
                fgets(states[i].name, MAX_STR, stdin);
                states[i].name[strcspn(states[i].name, "\n")] = '\0';

                printf("Capital: ");
                fgets(states[i].capital, MAX_STR, stdin);
                states[i].capital[strcspn(states[i].capital, "\n")] = '\0';

                printf("Official language: ");
                fgets(states[i].language, MAX_STR, stdin);
                states[i].language[strcspn(states[i].language, "\n")] = '\0';

                printf("Population: ");
                scanf("%ld", &states[i].population);
                getchar();

                printf("Area (km^2): ");
                scanf("%lf", &states[i].area);
                getchar();

                printf("Currency: ");
                fgets(states[i].currency, MAX_STR, stdin);
                states[i].currency[strcspn(states[i].currency, "\n")] = '\0';

                printf("Government type: ");
                fgets(states[i].government, MAX_STR, stdin);
                states[i].government[strcspn(states[i].government, "\n")] = '\0';

                printf("Head of state: ");
                fgets(states[i].head, MAX_STR, stdin);
                states[i].head[strcspn(states[i].head, "\n")] = '\0';

                printf("Continent/part of world: ");
                fgets(states[i].continent, MAX_STR, stdin);
                states[i].continent[strcspn(states[i].continent, "\n")] = '\0';
        }

        *count = n;
}

void
print_state(const State *s)
{
        printf("  %-12s %s\n", "Country:", s->name);
        printf("  %-12s %s\n", "Capital:", s->capital);
        printf("  %-12s %s\n", "Language:", s->language);
        printf("  %-12s %ld\n", "Population:", s->population);
        printf("  %-12s %.1f km^2\n", "Area:", s->area);
        printf("  %-12s %s\n", "Currency:", s->currency);
        printf("  %-12s %s\n", "Government:", s->government);
        printf("  %-12s %s\n", "Head:", s->head);
        printf("  %-12s %s\n", "Continent:", s->continent);
}

void
print_all_states(State *states,
                 int count)
{
        int i;

        printf("\n=== All states (%d) ===\n", count);
        for (i = 0; i < count; i++) {
                printf("\n[%d]\n", i + 1);
                print_state(&states[i]);
        }
}

int
filter_europe(State *states,
              int count,
              long min_pop,
              State *result)
{
        int i;
        int found = 0;

        for (i = 0; i < count; i++) {
                if (strcmp(states[i].continent, "Europe") == 0 &&
                    states[i].population > min_pop) {
                        result[found] = states[i];
                        found++;
                }
        }

        return found;
}
