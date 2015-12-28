#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h> // usleep
#include <string.h> // strcmp

using namespace std;

RCSwitch initTx(int pin, int protocol, int repetition, int delay) {
    pinMode(pin, OUTPUT);
    RCSwitch mySwitch = RCSwitch();
    mySwitch.setRepeatTransmit(repetition);
    mySwitch.enableTransmit(pin);
    mySwitch.setProtocol(protocol);
    if (delay > 0) {
        mySwitch.setPulseLength(delay);
    }
    return mySwitch;
}

void tx(RCSwitch mySwitch, int code, int bit) {
    mySwitch.send(code, bit);
    //cout << "Send code " << code << endl;
}

void tx(RCSwitch mySwitch, char* sCodeWord) {
    mySwitch.send(sCodeWord);
    //cout << "Send code " << sCodeWord << endl;
}

int main(int argc, char *argv[]) {
    int c;
    int x = 1;
    int protocol = 1;
    int code = 12345;
    int bit = 24;
    int pin = 1;
    int delay = 0;
    int repetition = 20;
    bool run = true;
    char sCodeWord[128] = "111111111";
    opterr = 0;

    while ((c = getopt(argc, argv, "hp:c:b:r:d:")) != -1) {
        switch (c) {
            case 'h':
                run = false;
                cout << argv[0] << " [-c code] [-b bit] [-p protocol] [-r repetition] [-d delay]" << endl << endl;
                cout << "code: code to transmit eg.: " << code << endl;
                cout << "bit: length of the code to transmit or 0 for binary code, default: " << bit << endl;
                cout << "protocol: protocol used to transmit (1, 2 or 3), default: " << protocol << endl;
                cout << "delay: pulse length or 0 for using the default pulse length protocol." << endl;
                cout << "repetition: how many time the code is transmit, default: " << repetition << endl;
                cout << endl;

                break;
            case 'p': // protocol
                protocol = atoi(optarg);
                break;
            case 'c': // code
                strcpy(sCodeWord, optarg);
                code = atoi(optarg);
                break;
            case 'b': // bit
                bit = atoi(optarg);
                break;
            case 'd': // bit
                delay = atoi(optarg);
                break;
            case 'r': // bit
                repetition = atoi(optarg);
                break;
            case '?':
                if (optopt == 'p' || optopt == 'c' || optopt == 'b' || optopt == 'r' || optopt == 'd')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option -%c.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character \\x%x.\n", optopt);
                return 1;
            default:
                abort();
        }
    }
    if (run) {
        RCSwitch mySwitch = initTx(pin, protocol, repetition, delay);
        if (bit == 0) {
            tx(mySwitch, sCodeWord);
        } else {
            tx(mySwitch, code, bit);
        }
    }
    return 0;
}
