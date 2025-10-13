#include <print>

#include "MyWeatherPrediction.h"

using namespace std;

void MyWeatherPrediction::setCurrentTempCelsius(int temp) {
  int fahrenheitTemp{convertCelsiusToFahrenheit(temp)};
  setCurrentTempFahrenheit(fahrenheitTemp);
}

#include <print>

#include "MyWeatherPrediction.h"

using namespace std;

int MyWeatherPrediction::getTomorrowTempCelsius() const {
  int fahrenheitTemp{getTomorrowTempFahrenheit()};
  return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const {
  println("Tomorrow will be {} degree Celsius ({} degree Fahrenheit)",
          getTomorrowTempCelsius(), getTomorrowTempFahrenheit());
  println("Chance if rain is {}%", getChanceOfRain() * 100);
  if (getChanceOfRain() > 0.5) {
    println("Bring an umbrella!");
  }
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius) {
  return static_cast<int>(celsius * 5 / 9 + 32);
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit) {
  return static_cast<int>((fahrenheit - 32) * 9 / 5);
}
