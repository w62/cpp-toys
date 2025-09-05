/*
g++-15 -std=c++23 -fmodules-ts -fsearch-include-path bits/std.cc  -c -x c++ AirlineTicket.cppm
*/

export module airline_ticket;

import std;

export class AirlineTicket {
    public:
    //AirlineTicket();
    //~AirlineTicket();

    double calculatePriceInDollars();

    std::string getPassengerName();
    void setPassengerName(std::string name);

    int getNumberOfMiles();
    void setNumberOfMiles(int);

    bool hasEliteSuperRewardsStatus();

    void setHasEliteSuperRewardsStatus(bool status);

    private:
    std::string m_passengerName {"Unknown Passenger"};
    int m_numberOfMiles {0};
    bool m_hasEliteSuperRewardsStatus {false};
};