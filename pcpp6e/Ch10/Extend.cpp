#include <print>
#include <string>

using namespace std;

class WeatherPrediction {
 public:
  // virtual destructor
  virtual ~WeatherPrediction() = default;
  // Sets the current temperature in Fahrenheit
  virtual void setCurrentTempFahrenheit(int temp);
  // Sets the current distance between Jupiter and Mars
  virtual void setPositionOfJupiter(int distanceFromMars);
  // Gets the prediction for tomorrow's temperature
  virtual int getTomorrowTempFahrenheit() const;
  // Gets the probability of rain tomorrow. 1 means
  // definite rain. 0 means no chance of rain.
  virtual double getChanceOfRain() const;
  // Displays the result to the user in this format:
  // Result: x.xx chance. Temp. xx
  virtual void showResult() const;
  // Returns a string representation of the temperature
  virtual std::string getTemperature() const;

 private:
  int m_currentTempFahrenheit{0};
  int m_distanceFromMars{0};
};

class MyWeatherPrediction : public WeatherPrediction {
 public:
  virtual void setCurrentTempCelsius(int temp);
  virtual int getTomorrowTempCelsius() const;

 private:
  static int convertCelsiusToFahrenheit(int celsius);
  static int convertFahrenheitToCelsius(int fahrenheit);
};

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius) {
  return celsius * 9 / 5 + 32;
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

void MyWeatherPrediction::setCurrentTempCelsius(int temp) {
  int fahrenheitTemp{convertCelsiusToFahrenheit(temp)};
  setCurrentTempFahrenheit(fahrenheitTemp);
}
int main() {
  //  MyWeatherPrediction m;
  return 0;
}
