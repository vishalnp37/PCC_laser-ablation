/// Author: Dr ELijah Borodin, 2023
/// Manchester
/// Library of specific functions related to the PCC Processing Design code for reading its .ini files

using namespace std; //Standard namespace

/// ================== # 1 # Initial configuration - reading and output ==================
std::vector<int> config_reader_main(std::string &source_path, std::string &source_dir, std::string &output_dir, std::string &main_type, std::ofstream &Out_logfile_stream) {
    std::vector<int> res;
    bool isSectionON = 0, isProcessingON = 0, isCharacterisationON = 0, isKineticON = 0, isMultiphysicsON = 0, isWriterON = 0;
    std::string isSection, isProcessing, isCharacterisation, isKinetic, isMultiphysics, isWriter;

    // ini files reader - external (MIT license) library
    mINI::INIFile file(source_path + "main.ini"s);
    mINI::INIStructure main_ini;
    file.read(main_ini);

// I
    if (main_ini.has("simulation_mode")) {
        auto& collection = main_ini["simulation_mode"];
        if (collection.has("mode"))
        {
            main_type = main_ini.get("simulation_mode").get("mode");
        } }
// II
    std::string problem_dimension;
    if (main_ini.has("general")) {
        auto& collection = main_ini["general"];
        if (collection.has("dim"))
            problem_dimension = main_ini.get("general").get("dim");
    }
    res.push_back(stoi(problem_dimension)); // res[0]

// III
    if (main_ini.has("modules")) {
        auto& collection = main_ini["modules"];
        if (collection.has("PCC_Section"))
            isSection = main_ini.get("modules").get("PCC_Section");
    }
    if (main_ini.has("modules")) {
        auto& collection = main_ini["modules"];
        if (collection.has("PCC_Processing"))
            isProcessing = main_ini.get("modules").get("PCC_Processing");
    }
    if (main_ini.has("modules")) {
        auto& collection = main_ini["modules"];
        if (collection.has("PCC_Characterisation"))
            isCharacterisation = main_ini.get("modules").get("PCC_Characterisation");
    }
    if (main_ini.has("modules")) {
        auto& collection = main_ini["modules"];
        if (collection.has("PCC_Multiphysics"))
            isMultiphysics = main_ini.get("modules").get("PCC_Multiphysics");
    }
    if (main_ini.has("modules")) {
        auto& collection = main_ini["modules"];
        if (collection.has("PCC_Kinetic"))
            isKinetic = main_ini.get("modules").get("PCC_Kinetic");
    }
    if (main_ini.has("modules")) {
        auto& collection = main_ini["modules"];
        if (collection.has("PCC_Writer"))
            isWriter = main_ini.get("modules").get("PCC_Writer");
    }
    // ON/OFF IDs
    if (isSection == "ON") { isSectionON = 1; res.push_back(1); } else res.push_back(0); // res[1] - Section
    if (isProcessing == "ON") { isProcessingON = 1; res.push_back(1); } else res.push_back(0); // res[2] - Processing
    if (isCharacterisation == "ON") { isCharacterisationON = 1; res.push_back(1); } else res.push_back(0); // res[3] - Characterisation
    if (isMultiphysics == "ON") { isMultiphysicsON = 1; res.push_back(1); } else res.push_back(0); // res[4] - Multiphysics
    if (isKinetic == "ON") { isKineticON = 1; res.push_back(1); } else res.push_back(0); // res[5] - Kinetic
    if (isWriter == "ON") { isWriterON = 1; res.push_back(1); } else res.push_back(0); // res[6] - Writer

    if (main_ini.has("general")) {
        auto& collection = main_ini["general"];
        if (collection.has("source_dir"))
            source_dir = main_ini.get("general").get("source_dir");
    }
    if (main_ini.has("general")) {
        auto& collection = main_ini["general"];
        if (collection.has("output_dir"))
            output_dir = main_ini.get("general").get("output_dir");
    }

/// Output to the screen/console
    cout << "The problem dimension that is the maximum value k_max of k-cells in the PCC\t\t|\t\t"s << "dim = " << res.at(0) << endl;
    cout << "Simulation type:\t"s << main_type << endl;
    cout << endl;
    cout << "Source directory:\t"s << source_dir << endl;
    cout << "Output directory:\t"s << output_dir << endl;
    cout << endl;
    if (isSectionON == 1) cout << "ON    | PCC_Section"s << endl;
    else cout << "OFF    | PCC_Section"s << endl;
    if (isProcessingON == 1) cout << "ON    | PCC_Processing"s << endl;
    else cout << "OFF    | PCC_Processing"s << endl;
    if (isCharacterisationON == 1) cout << "ON    | PCC_Characterisation"s << endl;
    else cout << "OFF    | PCC_Characterisation"s << endl;
    if (isMultiphysicsON == 1) cout << "ON    | PCC_Multiphysics"s << endl;
    else cout << "OFF    | PCC_Multiphysics"s << endl;
    if (isKineticON == 1) cout << "ON    | PCC_Kinetic"s << endl;
    else cout << "OFF    | PCC_Kinetic"s << endl;
    if (isWriterON == 1) cout << "ON    | PCC_Writer"s << endl;
    else cout << "OFF    | PCC_Writer"s << endl;
    cout << endl;

/// Output into .log file
    Out_logfile_stream << "The problem dimension that is the maximum value k_max of k-cells in the PCC:\t\t|\t\t"s << "dim = " << res.at(0) << endl;
    Out_logfile_stream << "Simulation type:\t"s << main_type << endl;
    Out_logfile_stream << endl;
    Out_logfile_stream << "Source directory:\t"s << source_dir << endl;
    Out_logfile_stream << "Output directory:\t"s << output_dir << endl;
    Out_logfile_stream << endl;
    if (isSectionON == 1) Out_logfile_stream << "ON    | PCC_Section"s << endl;
    else Out_logfile_stream << "OFF    | PCC_Section"s << endl;
    if (isProcessingON == 1) Out_logfile_stream << "ON    | PCC_Processing"s << endl;
    else Out_logfile_stream << "OFF    | PCC_Processing"s << endl;
    if (isCharacterisationON == 1) Out_logfile_stream << "ON    | PCC_Characterisation"s << endl;
    else Out_logfile_stream << "OFF    | PCC_Characterisation"s << endl;
    if (isMultiphysicsON == 1) Out_logfile_stream << "ON    | PCC_Multiphysics"s << endl;
    else Out_logfile_stream << "OFF    | PCC_Multiphysics"s << endl;
    if (isKineticON == 1) Out_logfile_stream << "ON    | PCC_Kinetic"s << endl;
    else Out_logfile_stream << "OFF    | PCC_Kinetic"s << endl;
    if (isWriterON == 1) Out_logfile_stream << "ON    | PCC_Writer"s << endl;
    else Out_logfile_stream << "OFF    | PCC_Writer"s << endl;
    Out_logfile_stream << endl;

    return res;
} /// END of config_reader_main function




/// ================== # 2 # Initial configuration - reading and output ==================


void config_reader_processing(std::string &source_path, std::vector<vector<double>> &max_fractions_vectors, double &mu, double &sigma, std::vector<string> &ptype_vector, std::vector<double> &pindex_vector, std::ofstream &Out_logfile_stream) {
    // ini files reader - external (MIT license) library
    mINI::INIFile file(source_path + "processing.ini"s);
    mINI::INIStructure processing_ini;
    file.read(processing_ini);

// I: cell types and max fractions and processing modes
/// Polyhedrons
//processing_mode
    if (processing_ini.has("polyhedrons")) {
        auto& collection = processing_ini["polyhedrons"];
        if (collection.has("pp_mode"))
        {
            ptype_vector.at(3) = processing_ini.get("polyhedrons").get("pp_mode");
        } }

    if (processing_ini.has("polyhedrons")) {
        auto& collection = processing_ini["polyhedrons"];
        if (collection.has("pp_index"))
            pindex_vector.at(3) = stod(processing_ini.get("polyhedrons").get("pp_index"));
        // R(0) - R, S(1) - Smax, S(0) - Smin, I(x.x) - index mode
    }

    string ptypes_number_string;
    if (processing_ini.has("polyhedrons")) {
        auto& collection = processing_ini["polyhedrons"];
        if (collection.has("polyhedron_types_number"))
            ptypes_number_string = processing_ini.get("polyhedrons").get("polyhedron_types_number");
    }

// fractions
    string p1_max, p2_max, p3_max;
    if (processing_ini.has("polyhedrons")) {
        auto& collection = processing_ini["polyhedrons"];
        if (collection.has("pmax_fraction1"))
            p1_max = processing_ini.get("polyhedrons").get("pmax_fraction1");
    }
    if (stoi(ptypes_number_string) > 0) max_fractions_vectors.at(3).push_back(stod(p1_max)); // 3 - polyhedra

    if (processing_ini.has("polyhedrons")) {
        auto& collection = processing_ini["polyhedrons"];
        if (collection.has("pmax_fraction2"))
            p2_max = processing_ini.get("polyhedrons").get("pmax_fraction2");
    }
    if (stoi(ptypes_number_string) > 0) max_fractions_vectors.at(3).push_back(stod(p2_max)); // 3 - polyhedra

    if (processing_ini.has("polyhedrons")) {
        auto& collection = processing_ini["polyhedrons"];
        if (collection.has("pmax_fraction3"))
            p3_max = processing_ini.get("polyhedrons").get("pmax_fraction3");
    }
    if (stoi(ptypes_number_string) > 0) max_fractions_vectors.at(3).push_back(stod(p3_max)); // 3 - polyhedra

/// Faces
//processing_mode
    if (processing_ini.has("faces")) {
        auto& collection = processing_ini["faces"];
        if (collection.has("pf_mode"))
        {
            ptype_vector.at(2) = processing_ini.get("faces").get("pf_mode");
        } }

    if (processing_ini.has("faces")) {
        auto& collection = processing_ini["faces"];
        if (collection.has("pf_index"))
            pindex_vector.at(2) = stod(processing_ini.get("faces").get("pf_index"));
        // R(0) - R, S(1) - Smax, S(0) - Smin, I(x.x) - index mode
    }

    string ftypes_number_string;
    if (processing_ini.has("faces")) {
        auto& collection = processing_ini["faces"];
        if (collection.has("face_types_number"))
            ftypes_number_string = processing_ini.get("faces").get("face_types_number");
    }

// fractions
    string f1_max, f2_max, f3_max;
    if (processing_ini.has("faces")) {
        auto& collection = processing_ini["faces"];
        if (collection.has("fmax_fraction1"))
            f1_max = processing_ini.get("faces").get("fmax_fraction1");
    }
    if (stoi(ftypes_number_string) > 0) max_fractions_vectors.at(2).push_back(stod(f1_max)); // 2 - faces

    if (processing_ini.has("faces")) {
        auto& collection = processing_ini["faces"];
        if (collection.has("fmax_fraction2"))
            f2_max = processing_ini.get("faces").get("fmax_fraction2");
    }
    if (stoi(ftypes_number_string) > 0) max_fractions_vectors.at(2).push_back(stod(f2_max)); // 2 - faces

    if (processing_ini.has("faces")) {
        auto& collection = processing_ini["faces"];
        if (collection.has("fmax_fraction3"))
            f3_max = processing_ini.get("faces").get("fmax_fraction3");
    }
    if (stoi(ftypes_number_string) > 0) max_fractions_vectors.at(2).push_back(stod(f3_max)); // 2 - faces

/// Edges
//processing_mode
    if (processing_ini.has("edges")) {
        auto& collection = processing_ini["edges"];
        if (collection.has("pe_mode"))
        {
            ptype_vector.at(1) = processing_ini.get("edges").get("pe_mode");
        } }

    if (processing_ini.has("edges")) {
        auto& collection = processing_ini["edges"];
        if (collection.has("pe_index"))
            pindex_vector.at(1) = stod(processing_ini.get("edges").get("pe_index"));
        // R(0) - R, S(1) - Smax, S(0) - Smin, I(x.x) - index mode
    }

    string etypes_number_string;
    if (processing_ini.has("edges")) {
        auto& collection = processing_ini["edges"];
        if (collection.has("edge_types_number"))
            etypes_number_string = processing_ini.get("edges").get("edge_types_number");
    }

// fractions
    string e1_max, e2_max, e3_max;
    if (processing_ini.has("edges")) {
        auto& collection = processing_ini["edges"];
        if (collection.has("emax_fraction1"))
            e1_max = processing_ini.get("edges").get("emax_fraction1");
    }
    if (stoi(etypes_number_string) > 0) max_fractions_vectors.at(1).push_back(stod(e1_max)); // 1 - edges

    if (processing_ini.has("edges")) {
        auto& collection = processing_ini["edges"];
        if (collection.has("emax_fraction2"))
            e2_max = processing_ini.get("edges").get("emax_fraction2");
    }
    if (stoi(etypes_number_string) > 0) max_fractions_vectors.at(1).push_back(stod(e2_max)); // 1 - edges

    if (processing_ini.has("edges")) {
        auto& collection = processing_ini["edges"];
        if (collection.has("emax_fraction3"))
            e3_max = processing_ini.get("edges").get("emax_fraction3");
    }
    if (stoi(etypes_number_string) > 0) max_fractions_vectors.at(1).push_back(stod(e3_max)); // 1 - edges

/// Nodes
//processing_mode
    if (processing_ini.has("nodes")) {
        auto& collection = processing_ini["nodes"];
        if (collection.has("pn_mode"))
        {
            ptype_vector.at(0) = processing_ini.get("nodes").get("pn_mode");
        } }

    if (processing_ini.has("nodes")) {
        auto& collection = processing_ini["nodes"];
        if (collection.has("pn_index"))
            pindex_vector.at(0) = stod(processing_ini.get("nodes").get("pn_index"));
        // R(0) - R, S(1) - Smax, S(0) - Smin, I(x.x) - index mode
    }

    string ntypes_number_string;
    if (processing_ini.has("nodes")) {
        auto& collection = processing_ini["nodes"];
        if (collection.has("node_types_number"))
            ntypes_number_string = processing_ini.get("nodes").get("node_types_number");
    }

// fractions
    string n1_max, n2_max, n3_max;
    if (processing_ini.has("nodes")) {
        auto& collection = processing_ini["nodes"];
        if (collection.has("nmax_fraction1"))
            n1_max = processing_ini.get("nodes").get("nmax_fraction1");
    }
    if (stoi(ntypes_number_string) > 0) max_fractions_vectors.at(0).push_back(stod(n1_max)); // 0 - nodes

    if (processing_ini.has("nodes")) {
        auto& collection = processing_ini["nodes"];
        if (collection.has("nmax_fraction2"))
            n2_max = processing_ini.get("nodes").get("nmax_fraction2");
    }
    if (stoi(ntypes_number_string) > 0) max_fractions_vectors.at(0).push_back(stod(n2_max)); // 0 - nodes

    if (processing_ini.has("nodes")) {
        auto& collection = processing_ini["nodes"];
        if (collection.has("nmax_fraction3"))
            n3_max = processing_ini.get("nodes").get("nmax_fraction3");
    }
    if (stoi(ntypes_number_string) > 0) max_fractions_vectors.at(0).push_back(stod(n3_max)); // 0 - nodes

// III: distribution
    if (processing_ini.has("distribution")) {
        auto& collection = processing_ini["distribution"];
        if (collection.has("mu"))
            mu = stod(processing_ini.get("distribution").get("mu"));
    }
    if (processing_ini.has("distribution")) {
        auto& collection = processing_ini["distribution"];
        if (collection.has("sigma"))
            sigma = stod(processing_ini.get("distribution").get("sigma"));
    }

vector<double> max_fractions_output(3, 0); // temporary vector serving as an output template for max fractions
/// Output to the screen/console
    cout<< "______________________________________________________________________________________" << endl;
    cout << "The Processing module simulation type and initial parameters:\t\t" << endl;
    cout << endl;
    cout << "Processing p_type:\t"s << ptype_vector.at(3) << "\twith p_index:\t"s << pindex_vector.at(3) << endl;
    if (ptype_vector.at(3) == "L") cout << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    cout << "Number of polyhedron types:\t"s << ptypes_number_string << endl;
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[3].size() > 0 && max_fractions_vectors[3][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[3][i];
    cout << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    cout << endl;
    cout << "Processing f_type:\t"s << ptype_vector.at(2) << "\twith f_index:\t"s << pindex_vector.at(2) << endl;
    if (ptype_vector.at(2) == "L") cout << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    cout << "Number of face types:\t"s << ftypes_number_string << endl;
// refill 0s
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[2].size() > 0 && max_fractions_vectors[2][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[2][i];
    cout << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    cout << endl;
    cout << "Processing e_type:\t"s << ptype_vector.at(1) << "\twith e_index:\t"s << pindex_vector.at(1) << endl;
    if (ptype_vector.at(1) == "L") cout << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    cout << "Number of edge types:\t"s << etypes_number_string << endl;
// refill 0s
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[1].size() > 0 && max_fractions_vectors[1][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[1][i];
    cout << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    cout << endl;
    cout << "Processing n_type:\t"s << ptype_vector.at(0) << "\twith n_index:\t"s << pindex_vector.at(0) << endl;
    if (ptype_vector.at(0) == "L") cout << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    cout << "Number of node types:\t"s << ntypes_number_string << endl;
// refill 0s
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[0].size() > 0 && max_fractions_vectors[0][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[0][i];
    cout << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    cout<< "______________________________________________________________________________________" << endl;

/// Output into .log file
    Out_logfile_stream<< "______________________________________________________________________________________" << endl;
    Out_logfile_stream << "The Processing module simulation type and initial parameters:\t\t" << endl;
    Out_logfile_stream << endl;
    Out_logfile_stream << "Processing p_type:\t"s << ptype_vector.at(3) << "\twith p_index:\t"s << pindex_vector.at(3) << endl;
    if (ptype_vector.at(3) == "L") cout << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    Out_logfile_stream << "Number of polyhedron types:\t"s << ptypes_number_string << endl;
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[3].size() > 0 && max_fractions_vectors[3][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[3][i];
    Out_logfile_stream << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    Out_logfile_stream << endl;
    Out_logfile_stream << "Processing f_type:\t"s << ptype_vector.at(2) << "\twith f_index:\t"s << pindex_vector.at(2) << endl;
    if (ptype_vector.at(2) == "L") Out_logfile_stream << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    Out_logfile_stream << "Number of face types:\t"s << ftypes_number_string << endl;
// refill 0s
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[2].size() > 0 && max_fractions_vectors[2][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[2][i];
    Out_logfile_stream << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    Out_logfile_stream << endl;
    Out_logfile_stream << "Processing e_type:\t"s << ptype_vector.at(1) << "\twith e_index:\t"s << pindex_vector.at(1) << endl;
    if (ptype_vector.at(1) == "L") Out_logfile_stream << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    Out_logfile_stream << "Number of edge types:\t"s << etypes_number_string << endl;
// refill 0s
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[1].size() > 0 && max_fractions_vectors[1][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[1][i];
    Out_logfile_stream << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    Out_logfile_stream << endl;
    Out_logfile_stream << "Processing n_type:\t"s << ptype_vector.at(0) << "\twith n_index:\t"s << pindex_vector.at(0) << endl;
    if (ptype_vector.at(0) == "L") Out_logfile_stream << "mu = \t"s << mu << " and " << "sigma = \t"s << sigma << endl;
    Out_logfile_stream << "Number of node types:\t"s << ntypes_number_string << endl;
// refill 0s
    std::fill(max_fractions_output.begin(), max_fractions_output.end(),0);
    for (int i = 0; i < 3; ++i)
        if (max_fractions_vectors[0].size() > 0 && max_fractions_vectors[0][i] > 0) max_fractions_output.at(i) = max_fractions_vectors[0][i];
    Out_logfile_stream << "Their maximum fractions:\t"s << max_fractions_output.at(0) << "\t\t" << max_fractions_output.at(1) << "\t\t"<< max_fractions_output.at(2) << "\t\t" << endl;
    Out_logfile_stream<< "______________________________________________________________________________________" << endl;

    return;
} /// END of config_reader_processing function