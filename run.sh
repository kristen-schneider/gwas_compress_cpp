cd /home/krsc0813/gwas_compress_cpp/

# compile
g++ \
    src/compress_main.cpp \
    src/header.cpp \
    -I inc/ \
    -lz \
    -o compress 

# execute

