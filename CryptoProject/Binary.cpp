/*Sets values to strings since switch statement does not accept strings
I am using this for posible multiple cases of bitset*/
enum VAL{
    HEX
};

VAL HashIt(std::string TYPE){
    if(TYPE == "HEX") return HEX;
    return HEX;
}

std::vector<std::string> ToBinary(std::string STRING, std::string TYPE){
    std::vector<char> VEC = StringToVector(STRING);
    std::vector<std::string> result;

    switch (HashIt(TYPE))
    {
        case HEX: 
            for (auto const&c: VEC) {
                switch (c) {
                    case '0':
                        result.insert(result.end(), "0000");
                        break;
                    case '1':
                        result.insert(result.end(), "0001");
                        break;
                    case '2':
                        result.insert(result.end(), "0010");
                        break;
                    case '3':
                        result.insert(result.end(), "0011");
                        break;
                    case '4':
                        result.insert(result.end(), "0100");
                        break;
                    case '5':
                        result.insert(result.end(), "0101");
                        break;
                    case '6':
                        result.insert(result.end(), "0110");
                        break;
                    case '7':
                        result.insert(result.end(), "0111");
                        break;
                    case '8':
                        result.insert(result.end(), "1000");
                        break;
                    case '9':
                        result.insert(result.end(), "1001");
                        break;
                    case 'A':
                    case 'a':
                        result.insert(result.end(), "1010");
                        break;
                    case 'B':
                    case 'b':
                        result.insert(result.end(), "1011");
                        break;
                    case 'C':
                    case 'c':
                        result.insert(result.end(), "1100");
                        break;
                    case 'D':
                    case 'd':
                        result.insert(result.end(), "1101");
                        break;
                    case 'E':
                    case 'e':
                        result.insert(result.end(), "1110");
                        break;
                    case 'F':
                    case 'f':
                        result.insert(result.end(), "1111");
                        break;
                    case '.':
                        result.insert(result.end(), ".");
                        break;
                    default:
                        throw std::invalid_argument("\nInvalid hexadecimal digit ");
                        
                    }
            }
            break;
        case "BIN": 
            ull B_Number = 0;
            int cnt = 0;
            while (N != 0) {
            int rem = N % 2;
            ull c = pow(10, cnt);
            B_Number += rem * c;
            N /= 2;
            // Count used to store exponent value
            cnt++;
    }
    return B_Number;
        
        default:
            std::cout<< "Default\n";
            break;
    }
    return result;
}