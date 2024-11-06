#pragma once
#include <string>

class Inventory {
    private:
        int serialNum;
        std::string manufactDate;
        int lotNum;
    public:
        Inventory(int serialNum = 0, std::string manufactDate = "", int lotNum = 0) // constructor
            : serialNum(serialNum), manufactDate(manufactDate), lotNum(lotNum) {} // initializer list 

        // setters
        void setSerialNum(int sn) { // sn for "serial number"
            serialNum = sn;
        }

        void setManufactDate(const std::string &date) {
            manufactDate = date;
        }

        void setLotNum(int ln) { // ln for "lot number"
            lotNum = ln;
        }

        // getters
        int getSerialNum() const {
            return serialNum;
        }

        std::string getManufactDate() const {
            return manufactDate;
        }

        int getLotNum() const {
            return lotNum;
        }
};