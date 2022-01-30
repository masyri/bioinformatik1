//
// Created by manjaro on 28.01.22.
//



#include <valarray>
#include <sstream>
#include <iostream>
#include "Statistics.h"
#include "console/Color.h"


/** Add a Set of Stats
 *
 * */
void Statistics::addStatsSet(double accuracy,double sensitivity,double specificity,double precision,double f1Score,double average,double standard_deviation) {

    stats_Accuracy.push_back(accuracy);
    stats_Sensitivity.push_back(sensitivity);
    stats_Specificity.push_back(specificity);
    stats_Precision.push_back(precision);
    stats_F1Score.push_back(f1Score);
    stats_Average.push_back(average);
    stats_Standard_deviation.push_back(standard_deviation);

}


/** Compute Accuracy
 *
 * @all     True/False Positive/Negative values
 * @return  accuracy in percent
 * */
 double Statistics::Accuracy(double TP, double TN, double FP, double FN) {
    double res = (TP + TN) / (TP + TN + FP + FN);
    if (res != res) {return 0;}
    return res * 100.0;
}


/** Compute Specificity
 *
 * @all     True/False Positive/Negative values
 * @return  specificity (in percent)
 * */
 double Statistics::Specificity(double TN, double FP) {
    double res = (TN) / (TN + FP);
    if (res != res) {return 0;}
    return res * 100.0;
};


/** Compute Sensitivity
 *
 * @all     True/False Positive/Negative values
 * @return  sensitivity (in percent)
 * */
 double Statistics::Sensitivity(double TP, double FN) {
    double res = (TP) / (TP + FN);
    if (res != res) {return 0;}
    return res * 100.0;
};


/** Compute Precision
 *
 * @all     True/False Positive/Negative values
 * @return  specificity (in percent)
 * */
 double Statistics::Precision(double TP, double FP) {
    double res = (TP) / (TP + FP);
    if (res != res) {return 0;}
    return res * 100.0;
};


/** Compute F1Score
 *
 * @precision  precision-value (in percent)
 * @sensivity  sensitivity-value (in percent)
 * @return     F1Score (in percent)
 * */
 double Statistics::F1Score(double precision, double sensivity) {
    double res = 2 * ( (precision * sensivity) / (precision + sensivity) );
    if (res != res) {return 0;}
    return res;
};


/** Compute Average
 *
 * @list       List of Values (in percent)
 * @return     average-Value (in percent)
 * */
 double Statistics::Average(std::vector<double> list) {
    double res = 0.0;
    for (double val : list) { res += val; }
    return res / list.size();
};


/** Compute Standard_deviation
 *
 * @Xi         List of Xi Values  (in Range 0.0 - 1.0)
 * @pXi        List of pXi Values (in Range 0.0 - 1.0)
 * @return     average-Value (in percent)
 * */
 double Statistics::Standard_deviation(std::vector<double> Xi,std::vector<double> pXi) {
    int count = Xi.size();
    double E_Xi = 0.0;
    double E_Xi2 = 0.0;

    // Calculation E[Xi]
    for (int i = 0 ; i < count ; i++) { E_Xi += Xi[i] * pXi[i]; }

    // Calculation E[Xi²]
    for (int i = 0 ; i < count ; i++) { E_Xi2 += pow(Xi[i],2) * pXi[i]; }

    // Calculation Var_Xi
    double Var_Xi = E_Xi2 - pow(E_Xi,2);

    // Calculation sigma
    double devi = sqrt(Var_Xi);

    return devi * 100.0;

}


/** Returns the average, min or max from a vector
 * 
 * @max_mix_avr   MAX , MIN or AVERAGE
 * @return        The expected value from the vector
 * */
double Statistics::getfromList(stat max_min_avr,std::vector<double> values) {
    if (values.size() == 0) {return 0;}
    double res = 0.0;
    double max = values[0];
    double min = values[0];
    double avr = 0.0;
    switch (max_min_avr)
    {
        case MAX     : for (double val : values) { if (val > max) {max = val;} } res = max; break;
        case MIN     : for (double val : values) { if (val < min) {min = val;} } res = min;break;
        case AVERAGE : res = 0.0; for (double val : values) { avr += val; } res = avr / values.size(); break;
        default: break;
    }
    return res;
}












/** Creates a single graph bar for diagrams from all values with min max and
 *  average ( for console output )
 *
 * */
std::vector<std::string> Statistics::barGraph(double max_value,std::vector<double> values, Color color) {
    std::vector<std::string> res;
    //if (values.size() == 0) {return res;}

    double min = getfromList(MIN,values);
    double max = getfromList(MAX,values);
    double avr_percent = getfromList(AVERAGE,values);

    std::stringstream min_bar("");
    //std::cout << "\n test bar: avr%: "<<avr_percent  <<" {";

    // 5%
    std::stringstream br("");
    if (max > 0.5 && max <= 0.5+10 ) {br << C::BRED << "__"; } else { br << "  ";}
    if (avr_percent >= 5.0  )   {  res.push_back(S::setStyle(color,Bold,White,br.str()));
    } else {  res.push_back(S::setStyle(Black,Bold,White,br.str())); }

    // 10%+

    for (int i = 0 ; i <= 11 ; i ++ ) { // first value in vector is 5%
        double percent = i * 10;
        //std::cout << " %:" <<(percent) << "->" << (avr_percent >= percent) << " ";

        std::stringstream bar("");

        // max
        if (max > percent && max <= percent+10 ) {bar << C::BRED << "__"; } else { bar << "  ";}

        // average
        if (avr_percent > percent   )   {  res.push_back(S::setStyle(color,Bold,White,bar.str()));
        } else {  res.push_back(S::setStyle(Black,Bold,White,bar.str()));
        }

   
    }
//    std::cout << "} ";
    return res;

}


// Getter
std::vector<double> Statistics::get_stats_Accuracy()            {return stats_Accuracy;             }
std::vector<double> Statistics::get_stats_Sensitivity()         {return stats_Sensitivity;          }
std::vector<double> Statistics::get_stats_Specificity()         {return stats_Specificity;          }
std::vector<double> Statistics::get_stats_Precision()           {return stats_Precision;            }
std::vector<double> Statistics::get_stats_F1Score()             {return stats_F1Score;              }
std::vector<double> Statistics::get_stats_Average()             {return stats_Average;              }
std::vector<double> Statistics::get_stats_Standard_deviation()  {return stats_Standard_deviation;   }