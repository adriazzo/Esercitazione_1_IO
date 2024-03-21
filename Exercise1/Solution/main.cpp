#include <iostream>
#include <fstream>

using namespace std;

unsigned int sumFirstNSquare(unsigned int N)
{
    return N * (N + 1) * (2 * N + 1) / 6;
}

int main()
{

    string fileName = "data.csv"; // file name
    ifstream ifstr(fileName); // create istream object and open file

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    unsigned int val = 0;
    unsigned int sumSquare = 0;
    unsigned int countVal = 0;

    string header;
    ifstr >> header; // ignore header of the file

    while(ifstr >> val)
    {
        sumSquare += val * val;
        countVal++;
    }

    ifstr.close();

    unsigned int ss = sumFirstNSquare(countVal);

    if(ss != sumSquare)
    {
        cerr << "Something is wrong" << endl;
        return 2;
    }


    cout << "The sum of square of the first N = " << countVal << " values is: " << sumSquare <<
        ". This sum is equal to: N * (N + 1) * (2 * N + 1) / 6, i.e. " << ss << endl;

    return 0;
}
