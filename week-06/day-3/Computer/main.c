#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer;
    computer.cpu_speed_GHz = 3.4;
    computer.ram_size_GB = 4;
    computer.bits = 64;
    Notebook notebook;
    notebook.cpu_speed_GHz = 4.5;
    notebook.ram_size_GB = 8;
    notebook.bits = 32;

    printf("The computer speed is: %.1f , its memory: %d and its bits: %d!\n", computer.cpu_speed_GHz,
           computer.ram_size_GB, computer.bits);
    printf("The notebook speed is: %.1f , its memory: %d and its bits: %d!\n", notebook.cpu_speed_GHz,
           notebook.ram_size_GB, notebook.bits);


    return 0;
}