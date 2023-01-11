///================================ A part of the DCC Subcomplex module =============================================================///
///=================================================================================================================================///
/** The library contains functions providing k-Cells IDs for a given subcomplex cut rules               **/
///================================================================================================================================///

/// The [parallelised] function output grain_ids from the plain cut (a,b,c,D)
vector<unsigned int> DCC_Plane_cut (double a_coeff, double b_coeff, double c_coeff, double D_coeff) {
/// The plane parameters: a_coeff*X + b_coeff*Y + c_coeff*Z = D
    vector<unsigned int> planecut_grains;

    // Obtaining Faces (coloumns) - Edges (rows) incidence matrix from file paths.at(5 + (dim - 3))
    SpMat ENS = SMatrixReader(paths.at(4 + (dim - 3)), (CellNumbs.at(0)), (CellNumbs.at(1))); //all Nodes-Edges
    //SpMat AES = SMatrixReader(paths.at(1 + (dim - 3)), (CellNumbs.at(1)), (CellNumbs.at(1))); //all Edges
    ///  Full symmetric AES matrix instead of triagonal
    //AES = 0.5 * (AES + SparseMatrix<double>(AES.transpose()));

    SpMat FES = SMatrixReader(paths.at(5 + (dim - 3)), CellNumbs.at(1), CellNumbs.at(2)); // Edges-Faces
    //SpMat AFS = SMatrixReader(paths.at(2 + (dim - 3)), (CellNumbs.at(2)), (CellNumbs.at(2))); //all Faces
    ///  Full symmetric AFS matrix instead of triagonal
    //AFS = 0.5 * (AFS + SparseMatrix<double>(AFS.transpose()));

    SpMat GFS = SMatrixReader(paths.at(6 + (dim - 3)), (CellNumbs.at(2)), (CellNumbs.at(3))); //all Faces-Grains
    SpMat AGS = SMatrixReader(paths.at(3 + (dim - 3)), (CellNumbs.at(3)), (CellNumbs.at(3))); //all Volumes
    ///  Full symmetric AGS matrix instead of triagonal
    AGS = 0.5 * (AGS + SparseMatrix<double>(AGS.transpose()));

    /// Vertex coordinates reader into triplet double vector
    string VCpath_string = input_folder + "voro_seeds"s;
    char* VCpath = const_cast<char*>(VCpath_string.c_str());
    //vector<Triplet<double>> vertex_coordinates = TripletsReader(VCpath);
    vector<tuple<double, double, double>> vertex_coordinates = TuplesReader(VCpath);

    vector<grain3D> grains_list; // vector of grains (class grain3D)
    // vertex_coordinates : coordinates of all vertices

#pragma omp parallel for // parallel execution by OpenMP
    for(unsigned int m = 0; m < CellNumbs.at(3); m++) {// each Grain
        grains_list.push_back(grain3D(m));
        grains_list.at(m).Set_node_ids(m,GFS, FES, ENS);
        grains_list.at(m).Set_node_coordinates(m, vertex_coordinates);
    } // end of for(unsigned int m = 0; m < CellNumbs.at(3); m++) - Grains

/// For each grain minmax_coord vector grain_coordinate_extremums of two tuples: gmincoord{xmin,ymin,zmin},gmaxcoord{xmax,ymax,zmax}
#pragma omp parallel for // parallel execution by OpenMP
    for(unsigned int m = 0; m < CellNumbs.at(3); m++) {// each Grain
        vector<tuple<double, double, double>> grain_coordinate_extremums = grains_list.at(m).Get_minmax_node_coordinates(m);
// get<0>(grain_coordinate_extremums.at(0)) -> MIN X coordinate, get<1>(grain_coordinate_extremums.at(0)) -> MIN Y coordinate, get<0>(grain_coordinate_extremums.at(1)) -> MAX X coordinate, etc..
        ///min
        // a_coeff*X + b_coeff*Y + c_coeff*Z = D
        if(D_coeff >= a_coeff*get<0>(grain_coordinate_extremums.at(0)) + b_coeff*get<1>(grain_coordinate_extremums.at(0)) + c_coeff*get<2>(grain_coordinate_extremums.at(0)) &&
           D_coeff <= a_coeff*get<0>(grain_coordinate_extremums.at(1)) + b_coeff*get<1>(grain_coordinate_extremums.at(1)) + c_coeff*get<2>(grain_coordinate_extremums.at(1)) )

            planecut_grains.push_back(m);
    } // end of for(unsigned int m = 0; m < CellNumbs.at(3); m++) {// each Grain
//a,b,c,d
    return planecut_grains;
}