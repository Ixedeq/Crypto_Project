//returns a string as a vector
std::vector<char> StringToVector(std::string STRING){
    std::vector<char> v;
    std::copy(STRING.begin(), STRING.end(), std::back_inserter(v));

    return v;
}