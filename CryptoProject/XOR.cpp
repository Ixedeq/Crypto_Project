std::string xoring(std::string a, std::string b){
    std::string ans = "";
    std::vector<std::string> StringA = ToBinary(a, "HEX");
    std::vector<std::string> StringB = ToBinary(b, "HEX");
    //Loop to iterate over the
    for (int i = 0; i < StringA.size(); i++){
        for (int o = 0; o < StringA[i].size(); o++)
            if (StringA[i][o] == StringB[i][o]) ans += '0';
            else ans += '1';
    }
    return ans;
}
 