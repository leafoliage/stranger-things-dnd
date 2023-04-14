#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

void pause();

void pause(int ms);

void log(string s);

void log(string s, int ms);

void redText();

void whiteText();

void clearScreen();

template<typename ... Args>
std::string fstring(const std::string& format, Args ... args) {
    int size_s = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; 
    if( size_s <= 0 ){ throw runtime_error( "Format error." ); }
    auto size = static_cast<size_t>( size_s );
    unique_ptr<char[]> buf( new char[ size ] );
    snprintf( buf.get(), size, format.c_str(), args ... );
    return string( buf.get(), buf.get() + size - 1 );
}

template<typename ... Args>
void logf(const std::string& format, Args ... args) {
    cout << fstring(format, args ...) << endl;
    pause();
}

#endif // LOGGER_H_INCLUDED
