#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    int choice;
    double temperature;

    cout << "Enter temperature: ";
    cin >> temperature;

    cout << "Choose conversion:\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Celsius to Kelvin\n";
    cout << "4. Kelvin to Celsius\n";
    cout << "5. Fahrenheit to Kelvin\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << temperature << " Celsius = " << celsiusToFahrenheit(temperature) << " Fahrenheit\n";
            break;
        case 2:
            cout << temperature << " Fahrenheit = " << fahrenheitToCelsius(temperature) << " Celsius\n";
            break;
        case 3:
            cout << temperature << " Celsius = " << celsiusToKelvin(temperature) << " Kelvin\n";
            break;
        case 4:
            cout << temperature << " Kelvin = " << kelvinToCelsius(temperature) << " Celsius\n";
            break;
        case 5:
            cout << temperature << " Fahrenheit = " << fahrenheitToKelvin(temperature) << " Kelvin\n";
            break;
        case 6:
            cout << temperature << " Kelvin = " << kelvinToFahrenheit(temperature) << " Fahrenheit\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }

    return 0;
}