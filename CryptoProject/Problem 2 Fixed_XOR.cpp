std::string xoring(std::string a, std::string b){
    std::vector<std::string> ans;
    std::vector<std::string> StringA = ToBinary(a, "HEX");
    std::vector<std::string> StringB = ToBinary(b, "HEX");
    std::string Temp = "";
    //Loop to iterate over the
    for (int i = 0; i < StringA.size(); i++){
        for (int o = 0; o < StringA[i].size(); o++){
            if (StringA[i][o] == StringB[i][o]) Temp += '0';
            else Temp += '1';
        }
        ans.insert(ans.end(), Temp);
        Temp = "";
    }
    return BinToHex(ans);
}
 