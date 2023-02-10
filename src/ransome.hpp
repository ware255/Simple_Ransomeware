#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

class rw{
private:
    std::string pass;
    std::string data;
    std::string filename;
    std::string p, buf;
    std::string::size_type strLen;

    int KEY;
public:
    rw();
    void xor_crypto(int, int);
    int encode();
    int decode(int);
    bool login();
};