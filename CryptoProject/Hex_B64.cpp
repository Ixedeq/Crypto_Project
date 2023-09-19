//converts Hex to Base 64 
std::string Hexb64Converter(std::string HEX){
    std::vector<std::string> Binary = ToBinary(HEX, "HEX");
    std::string Whole;
    std::vector<std::string> SixBit;
    std::string TempString;
    std::vector<int> Dec;
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="; 
    int i = 0;
    int temp;
    for (auto const&c: Binary) {
        Whole.append(c);
    }
    std::vector<char> Bin = StringToVector(Whole);
    for(auto const&c: Bin){
        temp = i % 6;
        switch(temp){
            case 0: 
                TempString = c;
                break;
            default: 
                TempString += c;
        }
        if(TempString.length() == 6){
            Dec.insert(Dec.end(), BinDec(TempString));
        }
        i++;
    }
    int tick = 0;
    while (TempString.length() != 6){
        TempString += '0';
        tick++;
        if(TempString.length() == 6){
            Dec.insert(Dec.end(), BinDec(TempString));
            if(tick == 1){
                Dec.insert(Dec.end(), 64);
            }
        }
    }
    std::string output = "";
    for(auto const&c: Dec){
        output += char_set[c];
    }
    return output;    
}
