cd /home/krsc0813/gwas_compress_cpp/

# compile
g++ \
    src/compress_main.cpp \
    src/header.cpp \
    -I inc/ \
    -I lib/zlib/ \
    -lz \
    -o compress 

# execute
./compress \
    /home/krsc0813/gwas_compress_cpp/data/small.tsv \
    10 \
    /home/krsc0813/gwas_compress_cpp/data/out.tsv
