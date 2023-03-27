///================================ DCC Writer module ===================================================================================///
///=====================================================================================================================================///
/** The function in this library perform a structured output of the calculation results **/
///===================================================================================================================================///

/// Attached user defined C++ libraries:
///-------------------------------------
#include "Writer_Functions.h"
//#include "DCC_Writer/Writer_Functions.h"
///-------------------------------------

/// Local functions
bool WriterON(char* config, bool time_step_one); // Check the Structure Writer module status (On/Off) in the config.txt file

void DCC_Writer(std::vector<unsigned int> const  &sfaces_sequence, std::vector<unsigned int> const  &kface_sequence, macrocrack const &large_crack, vector <unsigned int> &State_sVector, double const &mu_f, double const &sigm_f, vector<vector<int>> const &RW_series_vector,  const string P_type) {

    int output_counter = 0; // special counter for output numeration
    vector<agglomeration> agglomerations_vector; // vector containing aglomarations as its objects - only for L type simulations (!)


    char* stype = const_cast<char*>(P_type.c_str()); // Processing type variable
    char P_simulation_type = *stype;

    /// Output special and ordinary face sequences to the output directory specified in config.txt
    DCC_sequences_Writer(sfaces_sequence, kface_sequence, output_counter);
    if (P_simulation_type == 'L') {
        Strips_distribution_Writer(output_counter); // strips distribution
        RWseries_Writer(RW_series_vector, output_counter); // vector of all strips

        /// agglomerations  output
        Agglomerations_Writer(output_counter, RW_series_vector, mu_f, sigm_f);

    } // end of if(P_simulation_type == 'L')
     return ;
}

/// * Related functions * ///
// 5
bool WriterON(char* config, bool time_step_one) {
    std::string line;
    ifstream inConf(config);
    bool isWriterON = 0;

    if (inConf) { // If the file was successfully open, then
        while(getline(inConf, line, '\n'))
// REPAIR            cout << line << endl;
            if (!line.compare("DCC_Writer SWITCHED ON"s)) {
                isWriterON = 1;
                if (time_step_one == 1) cout << "ON    | DCC_Writer"s << endl;
                return isWriterON;
            }
    } else cout << "WriterON() error: The file " << config << " cannot be read" << endl; // If something goes wrong

    if (time_step_one == 1) cout << "OFF   | DCC_Writer"s << endl;
    return isWriterON;
}