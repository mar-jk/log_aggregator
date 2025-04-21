#include <iostream>
#include <fstream>
#include <sstream>
#include <string>




void removeWordFromFile(const std::string& filename, const std::string& wordToRemove) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();
    
    size_t pos;
    std::string wordWithSpace = " " + wordToRemove + " ";
    while ((pos = content.find(wordToRemove)) != std::string::npos) {
        content.erase(pos, wordToRemove.length());
    }
    
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error writing to file!" << std::endl;
        return;
    }
    outputFile << content;
    outputFile.close();
    
    std::cout << "Successfully removed all occurrences of '" << wordToRemove << "' from " << filename << "\n";
}

int main() {
    std::string filename = "imp.txt";
    removeWordFromFile(filename, "go");
    return 0;
}
{}
