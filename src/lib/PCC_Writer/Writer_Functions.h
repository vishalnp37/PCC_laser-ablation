///================================ A part of the DCC Writer module ====================================================================///
///=====================================================================================================================================///
/** The library contains functions for the formatted output of various kind of data generated by other modules                         **/
///===================================================================================================================================///

/// # 1 # Sequences and Designs

void PCC_CellSequences_Writer(CellsDesign &new_cells_design, int &output_counter) {
// Offstreams
ofstream Out_scells_file; // Special cell sequences output

// File names and output directories
string seq_odir = output_dir + "s_cells_sequence.txt"s; // output directory
string des_odir = output_dir + "s_cells_design.txt"s; // output directory

/// Output to file Special and Ordinary faces order :: tess - means "numeration of Faces start with 1 instead of 0 like in the NEPER output"
    // (1) Random
    Out_scells_file.open(seq_odir, ios::trunc);

    if (Out_scells_file) {
    // special cell sequences
        if (new_cells_design.Get_n_sequence().size() > 0)
           for (auto rvit: new_cells_design.Get_n_sequence()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            Out_scells_file << endl;
        if (new_cells_design.Get_e_sequence().size() > 0)
            for (auto rvit: new_cells_design.Get_e_sequence()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            Out_scells_file << endl;
        if (new_cells_design.Get_f_sequence().size() > 0)
            for (auto rvit: new_cells_design.Get_f_sequence()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            Out_scells_file << endl;
        if (new_cells_design.Get_p_sequence().size() > 0)
            for (auto rvit: new_cells_design.Get_p_sequence()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            cout << "(" << output_counter++ << ")  " << "Random special k-cells for all k = {0,1,2,3} sequences has been successfully written in " << seq_odir << endl;
        Out_logfile_stream << "(" << output_counter << ")  " << "Random special k-cells for all k = {0,1,2,3} sequences has been successfully written in " << seq_odir << endl;
        Out_scells_file.close();
    } else cout << "Error: No such a directory for\t" << seq_odir << endl;

    Out_scells_file.open(des_odir, ios::trunc);
    if (Out_scells_file) {
       // design vectors
        if (new_cells_design.Get_n_design().size() > 0)
            for (auto rvit: new_cells_design.Get_n_design()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            Out_scells_file << endl;
        if (new_cells_design.Get_e_design().size() > 0)
            for (auto rvit: new_cells_design.Get_e_design()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            Out_scells_file << endl;
        if (new_cells_design.Get_f_design().size() > 0)
            for (auto rvit: new_cells_design.Get_f_design()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output
            Out_scells_file << endl;
        if (new_cells_design.Get_p_design().size() > 0)
            for (auto rvit: new_cells_design.Get_p_design()) Out_scells_file << rvit + 1 << " "; /// vit + 1 !!! for compatibility with the Neper output

        cout << "(" << output_counter++ << ")  " << "Random special k-cells for all k = {0,1,2,3} sequences has been successfully written in " << des_odir << endl;
        Out_logfile_stream << "(" << output_counter << ")  " << "Random special k-cells for all k = {0,1,2,3} sequences has been successfully written in " << des_odir << endl;
        cout << endl; Out_logfile_stream << endl;
        Out_scells_file.close();
    } else cout << "Error: No such a directory for\t" << des_odir << endl;


    return;
}

/// # 2 # Entropic writer

void PCC_Entropic_Writer(ProcessedComplex &pcc_processed, int &output_counter) {
// Offstreams
    ofstream Out_entropies_file, Out_jf_file, Out_df_file; // Configuration entropies output

// File names and output directories
    string entropies_odir = output_dir + "processing_face_entropies.txt"s; // / full / mean / skrew / parts
    string ffrac_odir = output_dir + "processing_j_fractions.txt"s; // output directory
    string dfrac_odir = output_dir + "processing_d_fractions.txt"s; // output directory

/// (1) Configuration etropies:  / full / mean / skrew /
    Out_entropies_file.open(entropies_odir, ios::trunc);

    if (Out_entropies_file) {
        // special cell sequences
            for (unsigned int i = 0; i < pcc_processed.e_entropy_full_vector.size(); ++i)
                Out_entropies_file << pcc_processed.face_process_seq.at(i).size()/ (double) CellNumbs.at(2 + (dim -3)) << " " << pcc_processed.e_entropy_full_vector.at(i) << " " << pcc_processed.e_entropy_mean_vector.at(i) << " " << pcc_processed.e_entropy_skrew_vector.at(i) << endl;
        cout << "(" << output_counter++ << ")  " << "Configuration edge entropies has been successfully written in " << entropies_odir << endl;
        Out_logfile_stream << "(" << output_counter << ")  " << "Configuration edge entropies has been successfully written in " << entropies_odir << endl;
        Out_entropies_file.close();
    } else cout << "Error: No such a directory for\t" << entropies_odir << endl;

/// (2) Edge fractions:  / j0 / j1 / j2 / j3 /
    Out_jf_file.open(ffrac_odir, ios::trunc);

    if (Out_jf_file) {
        // special cell sequences
            for (unsigned int i = 0; i < pcc_processed.je_fractions_vector.size(); ++i)
                Out_jf_file << pcc_processed.face_process_seq.at(i).size()/ (double) CellNumbs.at(2 + (dim -3)) << " " << pcc_processed.je_fractions_vector[i][0] << " " << pcc_processed.je_fractions_vector[i][1] << " " << pcc_processed.je_fractions_vector[i][2] << " " << pcc_processed.je_fractions_vector[i][3] << endl;
        cout << "(" << output_counter++ << ")  " << "Special edge fractions has been successfully written in    " << ffrac_odir << endl;
        Out_logfile_stream << "(" << output_counter << ")  " << "Special edge fractions has been successfully written in   " << ffrac_odir << endl;
        Out_jf_file.close();
    } else cout << "Error: No such a directory for\t" << ffrac_odir << endl;

    /// (3) d-fractions for edges:  / d1 / d2 / d3 /
    Out_df_file.open(dfrac_odir, ios::trunc);

    if (Out_df_file) {
        // special cell sequences
            for (unsigned int i = 0; i < pcc_processed.de_fractions_vector.size(); ++i)
                Out_df_file << pcc_processed.face_process_seq.at(i).size()/ (double) CellNumbs.at(2 + (dim -3)) << " " << pcc_processed.de_fractions_vector[i][0] << " " << pcc_processed.de_fractions_vector[i][1] << " " << pcc_processed.de_fractions_vector[i][2] << endl;
        cout << "(" << output_counter++ << ")  " << "Special edge degree fractions has been successfully written in    " << dfrac_odir << endl;
        Out_logfile_stream << "(" << output_counter << ")  " << "Special edge degree fractions has been successfully written in   " << dfrac_odir << endl;
        Out_df_file.close();
    } else cout << "Error: No such a directory for\t" << dfrac_odir << endl;

    return;
}

/// # 3 # Analytical distributions writer

void PCC_AnalyticalFractions_Writer(ProcessedComplex &pcc_processed, int &output_counter) {
// Offstreams
    ofstream OutJRFile, OutJCFile, OutJDRFile, OutJDCFile, OutCERFile, OutCECFile; // Analytical fractions output
    string antjsrand_odir = output_dir + "analytical_TJs_random.txt"s; // output directory
    string antjscryst_odir = output_dir + "analytical_TJs_crystalline.txt"s; // output directory
    string antjdsrand_odir = output_dir + "analytical_TJDs_random.txt"s; // output directory
    string antjdscryst_odir = output_dir + "analytical_TJDs_crystalline.txt"s; // output directory
    string anentropiesrand_odir = output_dir + "analytical_EdgeConfEntropy_random.txt"s; // output directory
    string anentropiescryst_odir = output_dir + "analytical_EdgeConfEntropy_crystalline.txt"s; // output directory

// j and jd fractions of edges
//random
    OutJRFile.open(antjsrand_odir, ios::trunc);
        for (unsigned int i = 0; i < pcc_processed.j_analytical_rand_vector.size(); ++i)
            OutJRFile << pcc_processed.j_analytical_rand_vector[i][0] << " " << pcc_processed.j_analytical_rand_vector[i][1] << "    " << pcc_processed.j_analytical_rand_vector[i][2] << "    " << pcc_processed.j_analytical_rand_vector[i][3] << "    " << pcc_processed.j_analytical_rand_vector[i][4] << endl;
    OutJRFile.close();
//crystalline
    OutJCFile.open(antjscryst_odir, ios::trunc);
    for (unsigned int i = 0; i < pcc_processed.j_analytical_cryst_vector.size(); ++i)
        OutJCFile << pcc_processed.j_analytical_cryst_vector[i][0] << " " << pcc_processed.j_analytical_cryst_vector[i][1] << "    " << pcc_processed.j_analytical_cryst_vector[i][2] << "    " << pcc_processed.j_analytical_cryst_vector[i][3] << "    " << pcc_processed.j_analytical_cryst_vector[i][4] << endl;
    OutJCFile.close();

//random
    OutJDRFile.open(antjdsrand_odir, ios::trunc);
    for (unsigned int i = 0; i < pcc_processed.d_analytical_rand_vector.size(); ++i)
        OutJDRFile << pcc_processed.d_analytical_rand_vector[i][0] << " " << pcc_processed.d_analytical_rand_vector[i][1] << "    " << pcc_processed.d_analytical_rand_vector[i][2] << "    " << pcc_processed.d_analytical_rand_vector[i][3] << endl;
    OutJDRFile.close();
//crystalline
    OutJDCFile.open(antjdscryst_odir, ios::trunc);
    for (unsigned int i = 0; i < pcc_processed.d_analytical_cryst_vector.size(); ++i)
        OutJDCFile << pcc_processed.d_analytical_cryst_vector[i][0] << " " << pcc_processed.d_analytical_cryst_vector[i][1] << "    " << pcc_processed.d_analytical_cryst_vector[i][2] << "    " << pcc_processed.d_analytical_cryst_vector[i][3] << endl;
    OutJDCFile.close();

    cout << "(" << output_counter++ << ")  " << "Analytical Special Edges and Special Edges Degree fractions has been successfully written in  " << antjsrand_odir << endl << antjscryst_odir << endl << antjdsrand_odir << endl << antjdscryst_odir << endl;
    Out_logfile_stream << "(" << output_counter << ")  " << "Analytical Special Edges and Special Edges Degree fractions has been successfully written in  " << antjsrand_odir << endl << antjscryst_odir << endl << antjdsrand_odir << endl << antjdscryst_odir << endl;

// configuration edge entropies vectors
    OutCERFile.open(anentropiesrand_odir, ios::trunc);
    for (unsigned int i = 0; i < pcc_processed.AnRandEntropies_vector.size(); ++i)
        OutCERFile << i/ (double) CellNumbs.at(2 + (dim - 3)) << " " << get<0>(pcc_processed.AnRandEntropies_vector[i]) + get<1>(pcc_processed.AnRandEntropies_vector[i])  << " " << get<0>(pcc_processed.AnRandEntropies_vector[i]) << " " << get<1>(pcc_processed.AnRandEntropies_vector[i]) << endl;
    OutCERFile.close();

    OutCECFile.open(anentropiescryst_odir, ios::trunc);
    for (unsigned int i = 0; i < pcc_processed.AnCrystEntropies_vector.size(); ++i)
        OutCECFile << i/ (double) CellNumbs.at(2 + (dim - 3))<< " " << get<0>(pcc_processed.AnCrystEntropies_vector[i]) + get<1>(pcc_processed.AnCrystEntropies_vector[i])  << " " << get<0>(pcc_processed.AnCrystEntropies_vector[i]) << " " << get<1>(pcc_processed.AnCrystEntropies_vector[i]) << endl;
    OutCECFile.close();

    cout << "(" << output_counter++ << ")  " << "Analytical Configuration Edge Entropies (random and crystallographic)) has been successfully written in " << anentropiesrand_odir << endl << anentropiescryst_odir << endl;
    Out_logfile_stream << "(" << output_counter << ")  " << "Analytical Configuration Edge Entropies (random and crystallographic)) has been successfully written in " << anentropiesrand_odir << endl << anentropiescryst_odir << endl;

} // END of PCC_AnalyticalFractions_Writer( )

/// * NEW HEAP * ///

/**
///
// LengthySpecialFaces
        OutOfaces_file.open(output_dir + "LengthySpecialFaces.txt"s, ios::trunc);
        if (OutOfaces_file) {
            for (auto smvit: special_cells_design.at(1))
                OutOfaces_file << smvit + 1 << endl; /// vit + 1 !!! for compatibility with the Neper output
            cout << "(" << output_counter++ << ")  " << "Lengthy random faces_sequence has been successfully written in "
                 << output_dir
                 << "LengthySpecialFaces.txt"s << endl;
            OutOfaces_file.close();
        } else cout << "Error: No such a directory for\t" << output_dir << "SmaxSpecialFaces.txt"s << endl;
///

    if(kinetic_faces_sequence.size() > 0) {
        /// output cracked_Face_sequence to file
        ofstream OutCFSfile; // Special Faces sequence output
        /// Output to file Cracked Faces order :: tess - means "numeration of Faces start with 1 instead of 0 like in the NEPER output"
        OutCFSfile.open(output_dir + "CrackedGrainBoundaries.txt"s, ios::trunc);
        if (OutCFSfile) {
//        OutSGBfile << "Global numbers (in DCC) of cracked grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
            for (auto vit: kinetic_faces_sequence)
                OutCFSfile << vit + 1 << endl; /// vit + 1 !!! for compatibility with the Neper output
//        { if (unsigned int numerator = 0; numerator < max_cFaces_fraction*CellNumbs.at(2)) OutCFSfile << vit + 1 << endl; ++numerator; }
            cout << "(" << output_counter++ << ")  " << "Kinetic generated special faces sequence has been successfully written in " << output_dir
                 << "CrackedGrainBoundaries.txt"s << endl;
            OutCFSfile.close();
        } else cout << "Error: No such a directory for\t" << output_dir << "CrackedGrainBoundaries.txt"s << endl;
    }

 int DCC_subcomplex_Writer(int plane_id, subcomplex &sub_plane, int half_plane_id, subcomplex &half_plane, std::vector<unsigned int> const &sfaces_sequence, std::vector<unsigned int> const &kface_sequence, macrocrack &large_crack, double const &external_vonMizes_stress) {
    ofstream Outplane_file, Outhalfplane_file, OutCommonGBs_file, OutInclusionGBs_file, OutKineticFaces_file, OutKineticFaceCoords_file;
    int output_counter = 0; // temporarily here

    /// Grains output
    Outplane_file.open(output_dir + "Subcomplex_Plane_grains.txt"s, ios::trunc);
    if (Outplane_file) { //        OutSGBfile << "Global numbers (in DCC) of special grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto rvit: sub_plane.Get_grains_sequence(plane_id))
            Outplane_file << rvit + 1 << endl;
        cout << "(" << output_counter++ << ")  " << "Subcomplex plain grain IDs has been successfully written in " << output_dir + "Subcomplex_Plane_grains**.txt"s << endl;
        Outplane_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << (char) plane_id + "Subcomplex_Plane_grains.txt"s << endl;

    /// Grain half-plane output
    Outhalfplane_file.open(output_dir + "Subcomplex_half_plane_grains.txt"s, ios::trunc);
    if (Outhalfplane_file) {
        for (auto rvit: half_plane.Get_grains_sequence(half_plane_id))
            Outhalfplane_file << rvit+1 << endl;
        cout << "(" << output_counter++ << ")  " << "Subcomplex half_plain grain IDs has been successfully written in " << output_dir + "Subcomplex_half_plane_grains**.txt"s << endl;
        Outhalfplane_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << "Subcomplex_half_plane_grains**.txt"s << endl;

 ///
    /// Common faces in half-plane output
    OutCommonGBs_file.open(output_dir + "Subcomplex_common_faces_hp.txt"s, ios::trunc);
    if (OutCommonGBs_file) {
        for (auto rvit: half_plane.Get_common_faces_sequence(half_plane_id))
            OutCommonGBs_file << rvit + 1 << endl;
        cout <<"("<<output_counter++<<")  "<< "Subcomplex half_plain grain IDs has been successfully written in " << output_dir + "Subcomplex_common_faces_hp**.txt"s << endl;
        OutCommonGBs_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << (char) half_plane_id + "Subcomplex_common_faces_hp.txt"s << endl;
///
    /// GBs with inclusions in plane
    OutInclusionGBs_file.open(output_dir + "rGO_inplane_faces.txt"s, ios::trunc);
    if (OutInclusionGBs_file) { //        OutSGBfile << "Global numbers (in DCC) of special grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto rvit: sub_plane.Get_sfaces_sequence(plane_id))
            //     if(std::find(sfaces_sequence.begin(), sfaces_sequence.end(), rvit) != sfaces_sequence.end())
            OutInclusionGBs_file << rvit + 1 << endl;
        cout << "(" << output_counter++ << ")  " << "GBs with inclusions in plane has been successfully written in " << output_dir + "rGO_inplane_faces**.txt"s << endl;
        OutInclusionGBs_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << (char) plane_id + "rGO_inplane_faces.txt"s << endl;

    /// kfaces sequence writer
    OutKineticFaces_file.open(output_dir + "kinetic_faces.txt"s, ios::trunc);
    if (OutKineticFaces_file) { //        OutSGBfile << "Global numbers (in DCC) of special grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto rvit: kface_sequence)
            //     if(std::find(sfaces_sequence.begin(), sfaces_sequence.end(), rvit) != sfaces_sequence.end())
            OutKineticFaces_file << rvit + 1 << endl;
        cout << "(" << output_counter++ << ")  " << "kfaces sequence has been successfully written in " << output_dir + "kinetic_faces.txt"s << endl;
        OutKineticFaces_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << (char) plane_id + "kinetic_faces.txt"s << endl;

    /// Fractured faces coordinates writer
    OutKineticFaceCoords_file.open(output_dir + "kinetic_faces_coordinates.txt"s, ios::trunc);
    if (OutKineticFaceCoords_file) { //        OutSGBfile << "Global numbers (in DCC) of special grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto  itr = kface_sequence.begin(); itr != kface_sequence.end(); ++itr)
            OutKineticFaceCoords_file << get<0>(face_coordinates_vector.at(distance(kface_sequence.begin(),itr))) << " " << get<1>(face_coordinates_vector.at(distance(kface_sequence.begin(),itr))) << " " << get<2>(face_coordinates_vector.at(distance(kface_sequence.begin(),itr))) << endl;
        cout << "(" << output_counter++ << ")  " << "Factured faces coordinates has been successfully written in " << output_dir + "kinetic_faces_coordinates.txt"s << endl;
        OutKineticFaceCoords_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << (char) plane_id + "kinetic_faces_coordinates.txt"s << endl;


    /// Energies statistics for cracks
    double crack_fraction = kface_sequence.size() / (double) CellNumbs.at(2);
    double sfaces_fraction = sfaces_sequence.size() / (double) CellNumbs.at(2);
//    OutCrackEnergies_file.open(output_dir + "Crack_energies.txt"s, ios::app);
    if (OutCrackEnergies_file) {
        cout << "(1) sfaces fraction" << "  " << "(2) Crack length ratio" << "  " << "(3) external vonMizes stress" << "  " << "(4) macro_crack.surface_energy" << "  " << "(5) macro_crack.bridging_energy" << "  " << "(6) multiple_cracking_energy" << "  " << "(7) crack_fraction" << endl;
        cout << sfaces_fraction << "  " << large_crack.Get_crack_length(0) << "  " << external_vonMizes_stress << "  " << large_crack.surface_energy << "  " << large_crack.bridging_energy << "  " << large_crack.Get_multiple_cracking_energy() << "  " << crack_fraction << endl;
        OutCrackEnergies_file << sfaces_fraction << "  " << large_crack.Get_crack_length(0) << "  " << external_vonMizes_stress << "  " << large_crack.surface_energy << "  " << large_crack.bridging_energy << "  " << large_crack.Get_multiple_cracking_energy() << "  " << crack_fraction << endl;
        cout << "(" << output_counter++ << ")  " << "Crack_energies has been successfully written in " << output_dir + "Crack_energies.txt"s << endl;
//        OutCrackEnergies_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << (char) plane_id + "Crack_energies.txt"s << endl;

    return 0;
}
**/

/*
int DCC_crack_Writer(int crack_id, macrocrack &large_crack, std::vector<unsigned int> &cfaces_sequence) {
    ofstream OutCrackedFaces_file, OutCrackedFaceCoordinates_file, OutMacrocrackStat_file;

    /// Faces output
    OutCrackedFaces_file.open(output_dir + (char) crack_id + "Cracked_faces.txt"s, ios::trunc);
    if (OutCrackedFaces_file) {
        for (auto rvit: cfaces_sequence)
            OutCrackedFaces_file << rvit << endl;
        cout <<"("<<output_counter++<<")  "<< "Subcomplex half_plain grain IDs has been successfully written in " << output_dir + "Cracked_faces**.txt"s << endl;
        OutCrackedFaces_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << "Cracked_faces**.txt"s << endl;

    /// Face coordinates of all fractured grains in a whole PCC
    OutCrackedFaceCoordinates_file.open(output_dir + (char) crack_id + "Cracked_face_coordinates.txt"s, ios::trunc);
    if (OutCrackedFaceCoordinates_file) { //        OutSGBfile << "Global numbers (in DCC) of special grain boundaries with the fraction " << special_faces_sequence.size()/ CellNumbs.at(2) << endl;
        for (auto rvit: cfaces_sequence)
            /// to do !!
            OutCrackedFaceCoordinates_file << get <0>(face_coordinates_vector.at(rvit)) <<" " << get <1>(face_coordinates_vector.at(rvit)) <<" " << get <2>(face_coordinates_vector.at(rvit)) << endl;
        cout <<"("<<output_counter++<<")  "<< "Cracked face  has been successfully written in " << output_dir + "Cracked_face_coordinates**.txt"s << endl;
        OutCrackedFaceCoordinates_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << "Cracked_face_coordinates**.txt"s << endl;

    /// Fracture statistics
    OutMacrocrackStat_file.open(output_dir + (char) crack_id + "Crack_fracture_stats.txt"s, ios::trunc);
    if (OutMacrocrackStat_file) {
        for (auto rvit: )
            OutMacrocrackStat_file << rvit << endl;
        cout <<"("<<output_counter++<<")  "<< "Subcomplex half_plain grain IDs has been successfully written in " << output_dir + "**Crack_fracture_stats.txt"s << endl;
        OutMacrocrackStat_file.close();
    } else cout << "Error: No such a directory for\t" << output_dir << "**Crack_fracture_stats.txt"s << endl;


    return 0;
}
 */

/**
/// For 'L' processing type
//--------------------------------------------------------------
void Strips_distribution_Writer(int &output_counter) { // strip distribution output
    ofstream OutStripsDistribution; // Strip distributions output
    /// Output to file Cracked Faces order :: tess - means "numeration of Faces start with 1 instead of 0 like in the NEPER output"
    OutStripsDistribution.open(output_dir + "P_StripsDistribution.txt"s, ios::trunc);
    if (OutStripsDistribution) {
        for (auto sdis : face_strip_distribution)
            OutStripsDistribution << sdis << endl;

        cout << "(" << output_counter++ << ")  " << " Special face strips distribution has been successfully written in " << output_dir
             << "P_StripsDistribution.txt"s << endl;
        cout << "The total sum of all the values in the distribution is equal to:  " << std::accumulate(face_strip_distribution.begin(), face_strip_distribution.end(),
                                                                                                        decltype(face_strip_distribution)::value_type(0)) << endl;

        OutStripsDistribution.close();
    } else cout << "Error: No such a directory for\t" << output_dir << "P_StripsDistribution.txt"s << endl;

    return;
}

void RWseries_Writer(vector<vector<int>> const &RW_series_vector, int &output_counter) {
    ofstream RWseriesOutput; // Strip distributions output
    /// Output to file Cracked Faces order :: tess - means "numeration of Faces start with 1 instead of 0 like in the NEPER output"
    RWseriesOutput.open(output_dir + "P_RWseries.txt"s, ios::trunc);
    if (RWseriesOutput) {
        for (auto RWsfv : RW_series_vector) {
            for (auto RWsf: RWsfv) {
                RWseriesOutput << RWsf << " ";
            }
            RWseriesOutput << endl;
        }
        cout << "(" << output_counter++ << ")  " << " Strips of special faces has been successfully written in " << output_dir <<
             "P_RWseries.txt"s << endl;

        RWseriesOutput.close();
    } else cout << "Error: No such a directory for\t" << output_dir << "P_RWseries.txt"s << endl;

    return;
}

void Agglomerations_Writer(int &output_counter, vector<vector<int>> const &RW_series_vector, double const &mu_f, double const &sigm_f) {
    /// vector containing agglomerations (DCC_Objects_class objects) as its elements
    vector<agglomeration> agglomerations_vector;
    agglomerations_vector.clear();

    ///Agglomerations: fraction and average value
    vector<unsigned int> a_State_Vector(CellNumbs.at(2),0);

    /// form preliminary State Vector of agglomerations
    for (auto RWsfv : RW_series_vector)
        for (auto RWsf: RWsfv)
            a_State_Vector.at(RWsf) += 1; // change element of the State Vector

    /// form a new Vector of agglomerations
    for (auto  a_vector_itr = a_State_Vector.begin(); a_vector_itr != a_State_Vector.end(); ++a_vector_itr)
    {
        if (*a_vector_itr > 1)
            // agglomeration(unsigned int AFace, int AglPower)
            agglomerations_vector.push_back( agglomeration(distance(a_State_Vector.begin(), a_vector_itr), *a_vector_itr) );

    } // end of for (auto  a_vector_itr = a_State_Vector.begin(); a_vector_itr != a_State_Vector.end(); ++a_vector_itr)
    a_State_Vector.clear();

    /// Agglomerations  output:
    OutAgglStatistics.open(output_dir + "Stat_Agglomerations.txt"s, ios::app);
    OutAvLengthsADistributions.open(output_dir + "AvLengths_Distr_Agglomerations.txt"s, ios::trunc);
    OutPowersADistributions.open(output_dir + "Powers_Distr_Agglomerations.txt"s, ios::trunc);

    if (OutAgglStatistics && OutAvLengthsADistributions && OutPowersADistributions) {
        /// Calculation of an average length of strips related to the agglomeration
        int AgglAvLength = 0, AgglAvPower = 0;

        /// 1. Agglomeration distributions
        for (auto aggl: agglomerations_vector) {
            AgglAvLength += aggl.GetAvLength(RW_series_vector); //int GetAvLength(vector<vector<int>> const &RW_series_vector)
            OutAvLengthsADistributions << aggl.GetAvLength() << endl; //file output

            AgglAvPower += aggl.GetAPower(RW_series_vector); //    int GetAPower(vector<vector<int>> const &RW_series_vector)
            OutPowersADistributions << aggl.GetAPower() << endl; //file output
        } // end of for (auto aggl: agglomerations_vector)

        /// 2. Agglomeration statistics
        AgglAvLength /= agglomerations_vector.size();
        AgglAvPower /= agglomerations_vector.size();

        /// output to the Stat_Agglomerations.txt file
        // (1) agglomerations fraction (2) mu_f (3) sigm_f (4) agglomeration average power (5) average length of strips related to the agglomeration
        OutAgglStatistics << (double) agglomerations_vector.size() / CellNumbs.at(2) << "   " << mu_f << "   " << sigm_f << "   " << AgglAvLength << "   " << AgglAvPower << endl;
        //                OutAgglomerations << (double) special_faces_sequence.size()/ CellNumbs.at(2) << "   " << mu_f << "   " << sigm_f << "   " << (double) 100.0* agglomerations_Vector.size()/ CellNumbs.at(2) << "   " << std::accumulate(agglomerations_Vector.begin(), agglomerations_Vector.end(), decltype(agglomerations_Vector)::value_type(0))/ agglomerations_Vector.size() << endl; //        cout << "(" << output_counter++ << ")  " << " Agglomerations has been successfully written in " << output_dir << "P_Agglomerations.txt"s << endl;

    } else cout << "Error: No such a directory for\t" << output_dir << "Stat_Agglomerations.txt or Powers_Distr_Agglomerations.txt or AvLengths_Distr_Agglomerations"s << endl;

    OutAgglStatistics.close();
    OutAvLengthsADistributions.close();
    OutPowersADistributions.close();

    return;
} // end of void Agglomerations_Writer(...);
** /


/// ==================================================================================

//void OfStreams_trancator() {return;}

//EntIndices(sfaces_sequence, CellNumbs, FES, Face_Entropy_Median, Face_Entropy_Skrew)
/*vector<int> EntIndices( std::vector<unsigned int> &s_faces_sequence, std::vector<unsigned int> const& CellNumbs, Eigen::SparseMatrix<double> const& FES, double &Face_Entropy_Median, double &Face_Entropy_Skrew)
{
    vector<int> TJsTypes(CellNumbs.at(1),0);
    map<unsigned int, unsigned int> res; // Here 100 is an arbitrary number of Edge types
    map<unsigned int, unsigned int>::iterator sit; // Special iterator for this map
    double J0 = 0, J1 = 0, J2 = 0, J3 = 0, Jall = 0, j0 = 0, j1 = 0, j2 = 0, j3 = 0;
    double Configurational_Face_Entropy = 0;
    Face_Entropy_Median = 0; Face_Entropy_Skrew = 0;

    TJsTypes = EdgesTypesCalc(CellNumbs, s_faces_sequence, FES);
//    for (auto sfe : TJsTypes) cout << sfe << "\t" ; cout << endl;

    J1 = std::count(TJsTypes.begin(), TJsTypes.end(), 1);
    J2 = std::count(TJsTypes.begin(), TJsTypes.end(), 2);
    J3 = std::count(TJsTypes.begin(), TJsTypes.end(), 3);
    J0 = CellNumbs.at(1) - J1 - J2 - J3;
    Jall = CellNumbs.at(1);
// Conversion from numbers to fractions
// (!) log2 means binary (or base-2) logarithm and we use "-" for fractions to make the value positive
    j0 = J0/Jall; j1 = J1/Jall; j2 = J2/Jall; j3 = J3/Jall;
    double j0s = j0, j1s = j1, j2s = j2, j3s = j3;
    /// using values with pow(10,-10) instead of 0s!
//    if (j0s == 0) j0s = pow(10,-30); if (j1s == 0) j1s = pow(10,-30); if (j2s == 0) j2s = pow(10,-30); if (j3s == 0) j3s = pow(10,-30); //Gives 0 in entropy!
    if (j0s != 0) j0s = j0* log2(j0); if (j1s != 0) j1s = j1* log2(j1); if (j2s != 0) j2s = j2* log2(j2); if (j3s != 0) j3s = j3* log2(j3); //Gives 0 in entropy!
    /// Configuration Entropy related with Faces
//    Configurational_Face_Entropy = - (j0s* log2(j0s) + j1s* log2(j1s) + j2s* log2(j2s) + j3s* log2(j3s));
    Configurational_Face_Entropy = - (j0s + j1s + j2s + j3s);

    /// Median part in the entropy decomposition
    j_types_fractions = {j0, j1, j2, j3}; /// using values with pow(10,-10) instead of 0s!
    if (j0s!=0 && j1s!=0 && j2s!=0 && j3s!=0) {
        Face_Entropy_Median = -(1.0 / j_types_fractions.size()) * log2(j0 * j1 * j2 * j3);
    } else Face_Entropy_Median = 0.0;

    /// Screw part (divergence from the uniform distribution -> S_max) in the entropy decomposition
    for (int j = 0; j < j_types_fractions.size(); j++)
        for (int i = 0; i < j; i++)
            if (j_types_fractions[i]!=0 && j_types_fractions[j]!=0) {
                Face_Entropy_Skrew +=
                        -(1.0 / j_types_fractions.size()) * (j_types_fractions[i] - j_types_fractions[j]) *
                        log2(j_types_fractions[i] / j_types_fractions[j]);
            } else Face_Entropy_Skrew += 0.0;

    /// Complexity/ Informativeness
    // Srand and Smax reading from files
    string input_filename_SstrRand = "Random_Entropy_100.txt"s, input_filename_SstrMAX = "Maximum_Entropy_100.txt"s;
    string input_RandomEntropy_dir = output_dir + input_filename_SstrRand, input_MAXEntropy_dir = output_dir + input_filename_SstrMAX;
    char* RandomEntropy_dir = const_cast<char*>(input_RandomEntropy_dir.c_str()); char* MAXEntropy_dir = const_cast<char*>(input_MAXEntropy_dir.c_str()); // From string to char for the passing folder path to a function
    // Format of the elements:: special Face fraction _ Conf entropy value _ Mean entropy value (log(p1*p2*..*pn))
    vector<vector<double>>  RandomEntropy = VectorVectors4Reader(RandomEntropy_dir);
    vector<vector<double>>  MAXEntropy = VectorVectors4Reader(MAXEntropy_dir);
    //for ( auto tpl : MAXEntropy) cout << tpl[0] << " " << tpl[1] << " " << tpl[2] << endl;

    /// Index of complexity:
    double RandomEntropy_p = 0, MAXEntropy_p = 0;
    vector<double> Delta_MAX;
    double sff =(double) s_faces_sequence.size()/ CellNumbs.at(2); // special face fraction
    for ( auto tpl : MAXEntropy)  Delta_MAX.push_back(abs(sff - tpl.at(0)));
    auto numb_Smax = std::min_element(std::begin(Delta_MAX), std::end(Delta_MAX)) - std::begin(Delta_MAX); // gives index of the max element
    Delta_MAX.clear();
    for ( auto tpl : RandomEntropy)  Delta_MAX.push_back(abs(sff - tpl.at(0)));
    auto numb_Srand = std::min_element(std::begin(Delta_MAX), std::end(Delta_MAX)) - std::begin(Delta_MAX); // gives index of the max element
    Delta_MAX.clear();
    /// Informativeness parameter
//REPAIR    cout << numb_Smax << " " << numb_Srand << endl;
//REPAIR    cout << Configurational_Face_Entropy << " " << RandomEntropy[numb_Srand][1] << " " << MAXEntropy[numb_Smax][1] << endl;
    informativeness =  ( Configurational_Face_Entropy - RandomEntropy[numb_Srand][1])/ ( MAXEntropy[numb_Smax][1] - RandomEntropy[numb_Srand][1]);
    if (informativeness > 1) informativeness = 1;
    /// ====== Data output =====================>
    /// Opening of the output streams
    string TJs_output_filename = "TJsLab_TJsTypes.txt"s, Entropy_output_filename = "TJsLab_ConTJsEntropy.txt"s,
            output_TJs_dir = output_dir + TJs_output_filename, output_Entropy_dir = output_dir + Entropy_output_filename;
    char* cTJs_dir = const_cast<char*>(output_TJs_dir.c_str()); char* cEntropy_dir = const_cast<char*>(output_Entropy_dir.c_str()); // From string to char for the passing folder path to a function

    ofstream OutTJsFile; OutTJsFile.open(cTJs_dir, ios::app);
    double special_faces_fraction =(double) s_faces_sequence.size()/ CellNumbs.at(2);
//    cout << Configurational_Face_Entropy << "\t" << Face_Entropy_Median << "\t"<< Face_Entropy_Median << endl;

    OutTJsFile << special_faces_fraction << "\t" << j0 << "\t" << j1 << "\t" << j2 << "\t" << j3 << Configurational_Face_Entropy << "\t" << Face_Entropy_Median << "\t\t" << Face_Entropy_Skrew << endl;
    OutTJsFile.close();

//    int b = 0;
//    for (unsigned int it : TJsTypes) res[b++] = it;

    return TJsTypes;
}

 */