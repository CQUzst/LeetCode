class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0) 
            return "";
        string res="";
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};//13个
        unordered_map<int, string> m {{1,"I"},{4,"IV"}, {5,"V"},{9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"},
                                  {100,"C"},{400,"CD"}, {500,"D"},{900,"CM"}, {1000,"M"}};//数字和字符一一对应


        for (int i = 0; i < 13 && num > 0; i++)//遍历数字，从大到小，大于number【i】就减数，字符串增加
        {
            if (num < number[i])
            {
                continue;
            }
            while (num >= number[i])
            {
                num -= number[i];
                res +=m[number[i]];
            }
        }
        return res;
    }
};