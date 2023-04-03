#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <bitset>
#include <cmath>

#include "header.h"
//#include "compress.h"

using namespace std;

int main(int argc, char* argv[]) {
    // COMPRESSION STEPS

    // 0. read config options
    string in_file = argv[1];
    int block_size = stoi(argv[2]);
    string out_file = argv[3];
    cout << "Compressing \n..." << in_file << " to \n..." << out_file << endl;

    // 1. get first half of header
    vector<string> header;
    header = header_first_half(in_file);


    // 2. get blocks
    // 3. compress blocks AND get second half of header
    // 4. combine first and second half of header --> compress header
    // 5. write compressed header to file
    // 6. write compressed blocks to file

    return 0;
}
