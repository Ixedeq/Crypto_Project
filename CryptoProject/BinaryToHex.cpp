std::string BinToHex(std::vector<std::string> Bin){
    std::string hex = "";
    for(auto const c: Bin){
        switch (BinDec(c)){
            case 0:
                hex += "0";
                break;
            case 1:
                hex += "1";
                break;
            case 2:
                hex += "2";
                break;
            case 3:
                hex += "3";
                break;
            case 4:
                hex += "4";
                break;
            case 5:
                hex += "5";
                break;
            case 6:
                hex += "6";
                break;
            case 7:
                hex += "7";
                break;
            case 8:
                hex += "8";
                break;
            case 9:
                hex += "9";
                break;
            case 10:
                hex += "a";
                break;
            case 11:
                hex += "b";
                break;
            case 12:
                hex += "c";
                break;
            case 13:
                hex += "d";
                break;
            case 14:
                hex += "e";
                break;
            case 15:
                hex += "f";
                break;
            default: 
                throw std::invalid_argument("\nInvalid hexadecimal digit ");
        }
    }
    return hex;
}