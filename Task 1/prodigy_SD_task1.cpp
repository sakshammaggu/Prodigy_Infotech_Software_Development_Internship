#include <iostream>
using namespace std;
int main() 
{
    // Prompt the user to input a temperature value and the original unit of measurement.
    float temperature;
    char unit;
    cout << "Enter a temperature value: ";
    cin >> temperature;
    cout << "Enter the original unit of measurement (C, F, or K): ";
    cin >> unit;

    // Convert the temperature to the other two units.
    float fahrenheit, kelvin, celcius;
    if (unit == 'C') 
    {
        fahrenheit = (9.0 / 5.0) * temperature + 32.0;
        kelvin = temperature + 273.15;
    } 
    else if (unit == 'F') 
    {
        celcius = (5.0 / 9.0) * (temperature - 32.0);
        kelvin = (5.0 / 9.0) * (temperature - 32.0) + 273.15;
    } 
    else if (unit == 'K') 
    {
        celcius = temperature - 273.15;
        fahrenheit = (9.0 / 5.0) * (temperature - 273.15) + 32.0;
    } 
    else 
    {
        cout << "Invalid unit of measurement." << endl;
        return 1;
    }

    // Display the converted values to the user.
    cout << "The temperature in Fahrenheit is: " << fahrenheit << endl;
    cout << "The temperature in Kelvin is: " << kelvin << endl;

    return 0;
}