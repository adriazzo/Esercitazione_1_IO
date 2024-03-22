#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double shift(double N)  //Shifts the values from the interval [0,5] to [-1, 2]
{
    return 3*(N-1)/4 - 1;
}

int main()
{
    string InFileName = "data.csv";
    string OuFileName = "result.csv";

    ifstream ifstr(InFileName);

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    ofstream outFile(OuFileName);
    outFile << left << setw(5) << "#" << "N mean" << endl;

    double val = 0;
    double partial_sum = 0;
    unsigned int countVal = 1;
    double mean = 0;


    while(ifstr >> val) //Line by line takes the mapped value, evaluates the average and prints it in the output file
    {
        double mapped_val = shift(val);
        partial_sum += mapped_val;
        mean = partial_sum/countVal;
        outFile << left << setw(5) <<  countVal << setprecision(16) << scientific << mean << endl;
        countVal++;
    }

    ifstr.close();

    return 0;
}
