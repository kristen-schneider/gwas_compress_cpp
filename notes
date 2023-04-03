//#include <iostream>
//#include <string>
//#include "boost/iostreams/filtering_stream.hpp"
//#include "boost/iostreams/copy.hpp"
//#include "boost/iostreams/filter/gzip.hpp"
//#include "../lib/boost_1_78_0/libs/iostreams/src/zlib.cpp"
//#include "../lib/boost_1_78_0/libs/iostreams/src/gzip.cpp"
//#include "gzipWrapper.h"
//
//using namespace std;
//using namespace boost::iostreams;
//
//
//string gzipCompress(string s) {
////    cout << endl << s << " " << s.size() << endl;
//    string compressedString;
//    {
//        filtering_ostream compressingStream;
//        compressingStream.push(gzip_compressor(gzip_params(gzip::best_compression)));
//        compressingStream.push(boost::iostreams::back_inserter(compressedString));
//        compressingStream << s;
//        close(compressingStream);
//    }
////    cout << compressedString << " " << compressedString.size() << endl;
//
//    // return compressed string without header
//    return compressedString.substr(10);
//}
//
//string gzipDecompress(string compressedData){
//    string decompressedString;
//    {
//        filtering_ostream decompressingStream;
//        decompressingStream.push(gzip_decompressor());
//        decompressingStream.push(boost::iostreams::back_inserter(decompressedString));
//        decompressingStream << compressedData;
//        close(decompressingStream);
//    }
//
//    return decompressedString;
//}
//
//string returnGzipHeader(){
//    // return gzip header (same for all input streams)
//    string compressedString;
//    {
//        filtering_ostream compressingStream;
//        compressingStream.push(gzip_compressor(gzip_params(gzip::best_compression)));
//        compressingStream.push(boost::iostreams::back_inserter(compressedString));
//        compressingStream << "";
//        close(compressingStream);
//    }
//    return compressedString.substr(0,10);
//}
//
