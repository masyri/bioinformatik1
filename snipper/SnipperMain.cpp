//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"


/** returns a single SNP via []-Operator
 *
 * */
SingleSNP Snipper::operator[](int idx) const {
    return _snpstack[idx];
}


/** returns the Y-Vector of this class
 *
 * */
Classifics &Snipper::getClassifics() {
    return _class;
}


/** counts all SNP's in this class
 *
 * */
int Snipper::getSNPcount() {
    return _snpstack.size();
}


/** for Testing (count Genotypes over all SNP's)
 *
 * @gen     genotype
 * */
int Snipper::getGenCount(Genotype gen) {

    int cnt = 0;
    for ( SingleSNP snp : _snpstack ) {

        for (int i = 0 ; i < snp.getSize() ; i++) {
            if (snp[i] == gen) { cnt++; }
        }
    }

    return cnt;
}


/** Compare two doubles up to 2 digits
 *  
 * @a first value
 * @b second value
 * */
    bool Snipper::doubleCompare(double a, double b) {
    
    double cmp = abs(a - b);
        if (cmp < 0.001) {return true;} 
        return false;    
    
    }

// Getter
    std::vector<double> Snipper::getResultA_p_value(){ return _resultA_p_value;}
    std::vector<double> Snipper::getResultA_p_ref_F(){return _resultA_ref_F;}
    std::vector<int> Snipper::getResultA_p_SNP_id(){return _resultA_SNP_id;}
    std::vector<double> Snipper::getResultB_p_value(){ return _resultB_p_value;}
    std::vector<double> Snipper::getResultB_p_ref_F(){ return _resultB_ref_F;}
    std::vector<int> Snipper::getResultB_p_SNP_id(){ return _resultB_SNP_id;}