#pragma once

#include <string>
#include <vector>
#include <filesystem>

class File {
    private:
    std::filesystem::path path;
    std::string data;

    public:
    explicit File(std::filesystem::path p);

    const std::string& getData() const;
    void setData(const std::string &d);

    std::string getName() const;

    static std::string openFile(const std::filesystem::path &fileName);
    static std::vector<File> openFolder(const std::filesystem::path &directory);
};