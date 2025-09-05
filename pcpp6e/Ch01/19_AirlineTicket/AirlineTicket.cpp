
module airline_ticket;
using namespace std;



double AirlineTicket::calculatePriceInDollars()
{
    if (hasEliteSuperRewardsStatus()){
        return 0;
    }

    return getNumberOfMiles() * 0.1;

}

string AirlineTicket::getPassengerName() {

    return m_passengerName;
}

void AirlineTicket::setPassengerName(string name)

{
    m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles() {
    return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles (int miles) {
    m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus()
{
    return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status) {
    m_hasEliteSuperRewardsStatus = status;
}