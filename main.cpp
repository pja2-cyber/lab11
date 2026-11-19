#include <iostream>
#include "dayOfyear.h"
#include <fstream>
#include <string>
#include <vector>

namespace Parkjooae2649017
{
    void readWriteDayOfYearDateFile(std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<dayOfYear> v;

        std::streambuf* origBuf{std::cout.rdbuf()};
        std::cout.rdbuf(nullptr);
        
        dayOfYear d;
        while (fin >> d)
        {
            v.push_back(d);
        }
        
        std::cout.rdbuf(origBuf);

        for (const auto& vi : v)
            fout << vi;
        
    }
}

int main()
{
    using namespace Parkjooae2649017;
   

    std::ifstream fin{ "dayOfYearDate.txt"};
    if (fin.fail())
    {
        std::cout << "Input file opening failed. \n";
        std::exit(1);
    }



    std::ofstream fout("out.txt");
    // std::string fileName;
    // std::cout << "Enter output file name: ";
    // std::cin >> fileName;
    // fileName = fileName + ".txt";
    // fout.open(fileName);

    //     dayOfYear d;
    // std::streambuf* origBuf{std::cout.rdbuf()};
    // std::cout.rdbuf(nullptr);
    // fin >> d;
    // std::cout.rdbuf(origBuf);

    if (fout.fail())
    {
        std::cout << "OUtput file opening failed. \n";
        std::exit(1);
    }
 
    readWriteDayOfYearDateFile(fin, fout);

    fin.close();
    fout.close();

    return 0;
}