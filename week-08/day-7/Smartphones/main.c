#include <stdio.h>
#include <string.h>


/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */
typedef enum {
    BIG,
    MEDIUM,
    SMALL,
} screen_size_e;

typedef struct {
    char name[20];
    int yera_of_relase;
    screen_size_e screen_size;

} smartphone_t;

char *get_oldes_phone(smartphone_t smartphones[]);

int get_screen_size_count(smartphone_t smartphones[], screen_size_e screen_size);

int price(smartphone_t smartphones[], char name[]);

int main()
{

    FILE *file;
    file = fopen("../phones.txt", "r");
    char buffer[20];
    smartphone_t smartphones[15];
    int counter = 0;
    int size = 0;

    while (fscanf(file, "%s %d %d", smartphones[counter].name, &smartphones[counter].yera_of_relase,
                  &size) != EOF) {
        if (size >= 15) {
            smartphones[counter].screen_size = BIG;
        } else if (size >= 12) {
            smartphones[counter].screen_size = MEDIUM;
        } else {
            smartphones[counter].screen_size = SMALL;
        }
        counter++;
    }
    fclose(file);

    get_oldes_phone(smartphones);
    printf("The %s is the oldest device in the database\n", get_oldes_phone(smartphones));
    printf("There are %d phones with BIG (>= 15 cm) screen size\n", get_screen_size_count(smartphones, BIG));
    printf("There are %d phones with SMALL (< 12 cm) screen size\n", get_screen_size_count(smartphones, SMALL));

    file = fopen("../prices.txt", "w");
    for (int i = 0; i < 14; ++i) {
        fprintf(file, "%s %d\n", smartphones[i].name, price(smartphones, smartphones[i].name));
    }
    fclose(file);
    file = fopen("../prices.txt", "a");
    fprintf(file, "%s %d\n", smartphones[14].name, price(smartphones, smartphones[14].name));
    fclose(file);

    return 0;
}

char *get_oldes_phone(smartphone_t smartphones[])
{
    int size = 15;
    char *name;
    int year = 3000;
    for (int i = 0; i < size; ++i) {
        if (year > smartphones[i].yera_of_relase) {
            year = smartphones[i].yera_of_relase;
            name = smartphones[i].name;
        }
    }
    return name;
}

int get_screen_size_count(smartphone_t smartphones[], screen_size_e screen_size)
{
    int size = 15;
    int counter = 0;
    for (int i = 0; i < 15; ++i) {
        if (smartphones[i].screen_size == screen_size) {
            counter++;
        }
    }
    return counter;
}

int price(smartphone_t smartphones[], char name[])
{
    int price = 300;
    for (int i = 0; i < 15; ++i) {
        if (smartphones[i].name == name) {
            if (smartphones[i].screen_size == MEDIUM) {
                price += 100;
            }
            if (smartphones[i].screen_size == BIG) {
                price += 300;
            }
            int year_passed = 2019 - smartphones[i].yera_of_relase;
            if (year_passed <= 5) {
                price = price - (year_passed * 50);
            } else {
                price -= 250;
            }
        }
    }
    return price;
}