#pragma once
#include <string>
#include <string_view>
class SpreadsheetCell
{
    public:
        SpreadsheetCell() = default;
        SpreadsheetCell(double initialValue);
        SpreadsheetCell(std::string_view initialValue);
        void set(double inValue);
        double getValue() const;

        void set(std::string_view inString);
        std::string getString() const;
    private:
        static std::string doubleToString(double inValue) ;
        static double stringToDouble(std::string_view inString) ;
        double mValue;
        mutable size_t mNumAccesses = 0;
};
