#include <iostream>
#include <fstream>
#include <valarray>
#include "SingleSNP.h"
#include "Snipper.h"
#include "console/console.h"


int main(int argc, char *argv[]) {

    //std::cout << "\n" << S.getClassifics().to2String();
    //std::cout << "\n Xi[0].computeF => " << S[0].computeF();
    //std::cout << "\n Xi[1].computeF => " << S[1].computeF();
    //std::cout << "\n Xi[2].computeF => " << S[2].computeF();
    //                  S.getClassifics().shuffle();
    //::cout << "\n" << S.getClassifics().to2String();

    //std::cout << "\n shuffle res:" << S.computeF_all(1000);

    //return 0;


    // correct arg-count?
    if (argc < 3) { console::Help("  Not enough arguments!  ");return 0; }
    if (argc > 3) { console::Help("  Too many arguments!  ");return 0; }

    // ## Argument Variables
    std::string arg_In  = argv[1];
    std::string arg_Out = argv[2];
    std::ifstream input(arg_In);
    std::ofstream output(arg_Out);

    // ## File Check
    if (!input) { console::Help("  Input file error!  "); input.close(); return 0; }
    if (!output) { console::Help("  Output file error!  "); input.close(); output.close();return 0; }
    input.close();output.close();

    // ## Input okay -> Start SNP computing

    console::ShowHeader(); // show header

    Timer t; // timestamp

    Snipper S(arg_In); // read file

    console::ShowInputs(arg_In,arg_Out,S); // show inputs

    double time1 = t.getMilliSecs(); // timestamp after file in

    S.startAlgorithm(); // algorithm

    S.outputSNP(arg_Out);

    double time2 = t.getMilliSecs(); // timestamp after finish algorithm

    // ## Results Output

    console::Result(" finished ... ",Timer::getFormatted(time2),Timer::getFormatted(time1),Timer::getFormatted(time2-time1));

    return 0;
}
