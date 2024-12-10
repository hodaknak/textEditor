#include "file.h"

#include <iostream>
#include <fstream>
#include <utility>

File::File(std::filesystem::path p) {
    path = std::move(p);
    data = openFile(path);
}

const std::string& File::getData() const {
    return data;
}

void File::setData(const std::string &d) {
    data = d;
}

std::string File::getName() const {
    return path.stem().string() + path.extension().string();
}

bool File::write() const {
    if (exists(path)) {
        std::ofstream file(path);

        file << data;

        file.close();

        return true;
    } else {
        return false;
    }
}

std::string File::openFile(const std::filesystem::path &fileName) {
    std::ifstream istream(fileName, std::ios_base::in);

    if (!istream.is_open()) std::cerr << "Error opening file " << fileName << std::endl;

    std::string output;

    std::string line;

    while (std::getline(istream, line)) {
        output += line + "\n";
    }

    return output;
}

std::vector<File> File::openFolder(const std::filesystem::path &directory) {
    std::vector<File> files;

    for (const auto & entry : std::filesystem::directory_iterator(directory))
        files.push_back(File(entry.path()));

    return files;
}