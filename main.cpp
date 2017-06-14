#include <iostream>
#include <fstream>                                                          // for file sterams
#include <process.h>                                                        // for exit()

const int MAX = 1000;
int buff[MAX];

int main() {
    for (int i = 0; i < MAX; i++) {                                         // fill buffer with data
        buff[i] = i;
    }
    std::ofstream os;                                                       // create output stream

    os.open("a:edata.dat", std::ios::trunc | std::ios::binary);
    if(!os)
    {
        std::cerr << "Coud not open output file!";
        exit(1);
    }
    std::cout << "Writing...";                                              // Write buffer to file
    os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    if(!os)
    {
        std::cerr << "Could not write to file";
        exit(1);
    }
    os.close();                                                             // closing file

    for (int j = 0; j < MAX; j++) {
        buff[j] = 0;
    }

    std::ifstream is;                                                       // create input stream
    is.open("a:edata.dat", std::ios::binary);
    if(!is)
    {
        std::cerr << "Could not open input file :( ";
        exit(1);
    }
    std::cout << "Reading....";
    is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));              // reading file...

    if(!is)
    {
        std::cerr << "Could not read from file.... :( ";
        exit(1);
    }
    for (int k = 0; k < MAX; k++) {                                         // check data
        if (buff[k] != k)
        {
            std::cerr << "Data incorrect!";
            exit(1);
        }
    }
    std::cout << "Data is correct :)" << std::endl;

    std::cin.get();
    return 0;
}