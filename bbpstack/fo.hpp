#pragma once
#include <fstream>
#include <string>
#include <cstdlib>

std::fstream FlexibleOpen(std::string path, std::ios::openmode mode = std::ios::in, std::string envval = std::string("CSC1810"));
