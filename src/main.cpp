#include <cstdlib>
#include <simlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

void printHelp(){
    std::cout << "help" << std::endl;
}

void checkArgs(int argc, char *argv[]) {
    unsigned int d,c;
    int pos = 1;
    char *temp;


    while (pos < argc) {  //cycle through all arguments
        if (0 == strcmp(argv[pos], "-d")) {
            d = (int) strtol(argv[pos+1], &temp, 10);
            if (*temp != '\0') {
                exit(1);
            }
            if (d < 0 || d > 20) {  // check port range.
                exit(1);
            }
            pos +=2;

        } else if (0 == strcmp(argv[pos], "-c")) {

            c = (int) strtol(argv[pos+1], &temp, 10);
            if (*temp != '\0') {
                exit(1);
            }
            if (c < 0 || c > 20) {  // check port range.
                exit(1);
            }
            pos+=2;

        } else if (0 == strcmp(argv[pos], "-h")) {
            printHelp();
        } else {
            exit(2);
        }
    }
}


int main(int argc, char *argv[]) {

    checkArgs(argc, argv);

    return 0;
}
