#include "Logger.h"

void pause() {
    this_thread::sleep_for(chrono::milliseconds(1500));
}

void pause(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void log(string s) {
    cout << s << endl;
    pause();
}

void log(string s, int ms) {
    cout << s << endl;
    pause(ms);
}

void redText() {
    printf("%c[%dm", 0x1B, 31);
}

void whiteText() {
    printf("%c[%dm", 0x1B, 37);
}
