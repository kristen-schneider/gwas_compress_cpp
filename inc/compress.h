#ifndef GWAS_COMPRESS_CPP_COMPRESS_H
#define GWAS_COMPRESS_CPP_COMPRESS_H

#endif //GWAS_COMPRESS_CPP_COMPRESS_H

#include <iostream>
#include <string>
#include <vector>
#include <zlib.h>
#include <fstream>
#include <sstream>

using namespace std;

string zlib_compress(
        const string& str,
        int compressionlevel = Z_BEST_COMPRESSION);
