//
// Created by manjaro on 21.01.22.
//

#ifndef SNIPPER_H
#define SNIPPER_H


#include <string>
#include <vector>
#include "SingleSNP.h"

class Snipper {

public:
    
    // ### SnipperFile ###

        // Create Snipper without file (for testing)
        Snipper();

        // output
        void outputSNP(std::string output_file);

        // Create Snipper with file
        Snipper(std::string filename);

    
    // ### SnipperAlgorithm ###

        // Start complete Algorithm
        void startAlgorithm();

        // Shuffle a SNP x times and returns the p-value
        double computeF_shuffling(int shuffles, int snp_idx, double reference_F);

        // Bonferroni computation
        double computeBonferroni(double p_value);

        // FDR computation
        int computeFDR(std::vector<double> p_values);

    
    // ### SnipperMain ###

        // rank SNP's
        void rankSNPs(std::vector<double> p_values);

        // Get ranked SNP
        int getSNPIndexByRank(int rank);

        // returns Y-Vector
        Classifics& getClassifics();

        // count SNP's
        int getSNPcount();

        // for Testing (count Genotypes over all SNP's)
        int getGenCount(Genotype gen);

        // Get a single SNP from the SNP-Vector-Array
        SingleSNP operator [](int idx) const;
    
        // compare two doubles
        static bool doubleCompare(double a, double b);

        // add a new SNP-Vector to the array
        Snipper & operator<<(SingleSNP const &s)
        {
            _snpstack.push_back(s);
            return *this;
        }

    //Getter for testing
    std::vector<double> getResultA_p_value();
    std::vector<double> getResultA_p_ref_F();
    std::vector<int> getResultA_p_SNP_id();
    std::vector<double> getResultB_p_value();
    std::vector<double> getResultB_p_ref_F();
    std::vector<int> getResultB_p_SNP_id();

private:

    std::vector<SingleSNP> _snpstack; // SNP-Stack
    Classifics _class;                // classifications
    
    std::vector<double> _resultA_p_value; // Exercise c)
    std::vector<double> _resultA_ref_F;
    std::vector<int>    _resultA_SNP_id;
    std::vector<double> _resultB_p_value; // Exercise d)
    std::vector<double> _resultB_ref_F; 
    std::vector<int>    _resultB_SNP_id;
    

};


#endif //SNIPPER_H
