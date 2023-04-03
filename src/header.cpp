#include <iostream>
#include <string>
#include <vector>
#include <zlib.h>
#include <fstream>
#include <sstream>
#include <map>

#include "header.h"
#include "compress.h"

using namespace std;

vector<string> header_first_half(
        string in_file){
    /* HEADER FIRST HALF
     * magic_number = 1
     * version_number = 1
     * delimiter = None
     * column_names_list = None
     * column_types_list = None
     * num_columns = None
     * gzip_header = None
     * zlib_header = None
     * bz2_header = None
     */
    vector<string> header;


    string magic_number = "1";
    string version_number = "1";
    char delimiter = 'None';
    string column_names_list = "";
    string column_types_list = "";
    string num_columns = "";
    string gzip_header = ""; //

    // open file
    ifstream file(in_file);
    // exit on error
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        exit(1);
    }

    // read first two lines of file
    string line_1;
    string line_2;
    getline(file, line_1);
    getline(file, line_2);

    // get delimiter
    delimiter = get_delimiter(line_1);
    header.push_back(to_string(delimiter));
    // get column names
    column_names_list = get_column_names(line_1, delimiter);
    header.push_back(column_names_list);
    // get column types
    column_types_list = get_column_types(line_2, delimiter);
    header.push_back(column_types_list);
    // get number of columns
    num_columns = to_string(count(column_names_list.begin(), column_names_list.end(), ',') + 1);
    header.push_back(num_columns);
    // get gzip header
    gzip_header = get_gzip_header();

    return header;
}

char get_delimiter(
        string line){
    char delimiter;
    // determine delimiter
    if(line.find('\t') != string::npos){
        delimiter = '\t';
    } else if(line.find(',') != string::npos){
        delimiter = ',';
    } else if(line.find(' ') != string::npos){
        delimiter = ' ';
    } else {
        cout << "Error: delimiter not found.\n"
                " Please use delimiters tab, comma, or space." << endl;
        exit(1);
    }
    return delimiter;
}

string get_column_names(
        string line,
        char delimiter){

    string column_names_str;
    // split line by delimiter and store in comma separated string
    stringstream ss(line);
    string item;
    while(getline(ss, item, delimiter)){
        column_names_str += item + ",";
    }
    // remove last comma
    column_names_str.pop_back();
    return column_names_str;
}

string get_column_types(
        string line,
        char delimiter) {

    string column_types_str;
    // split line by delimiter find data type and store in comma separated string
    stringstream ss(line);
    string item;
    while (getline(ss, item, delimiter)) {
        // check if item is int
        // check if item is float
        // else  item stays as string
        // if none of the above, throw error
        // search for '.' in item
        if (item.find('.') != string::npos) {
            column_types_str += "float,";
        } else {
            try {
            stoi(item);
            column_types_str += "int,";
            }
            catch (invalid_argument &e) {
                column_types_str += "string,";
            }
        }
    }
    // remove last comma
    column_types_str.pop_back();
    return column_types_str;
}

string get_gzip_header(){
    string gzip_header = "";
    int example_int = 1;
    string example_string = "1";
    char example_char = '1';

    // compress example_int with zlip_compress
    string compressed_int = zlib_compress(to_string(example_int));
    // compress example_string with zlip_compress
    string compressed_string = zlib_compress(example_string);
    // compress example_char with zlip_compress
    string compressed_char = zlib_compress(to_string(example_char));


    return gzip_header;
}

