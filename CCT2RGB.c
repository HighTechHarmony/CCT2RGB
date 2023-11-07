#include <Kelvin2RGB.h>

struct RGB get_RGB_from_kelvin(uint16_t color_kelvin)
{
    // Convert kelvin to R, G, B values

    double tmpKelvin;

    // All calculations require tmpKelvin \ 100, so only do the conversion once
    tmpKelvin = fmax(1000, fmin(40000, color_kelvin)) / 100;

    struct RGB rgb;


    // Thanks to Tanner Helland for his calculations for Kelvin to RGB, with contributions from Mike D Sutton
    // Note: The R-squared values for each approximation follow each calculation
    rgb.r = tmpKelvin <= 66 ? 255 : fmax(0, fmin(255, 329.698727446 * pow(tmpKelvin - 60, -0.1332047592))); // .988

    rgb.g = tmpKelvin <= 66 ? fmax(0, fmin(255, 99.4708025861 * log(tmpKelvin) - 161.1195681661)) : // .996
                fmax(0, fmin(255, 288.1221695283 * pow(tmpKelvin - 60, -0.0755148492)));            // .987

    rgb.b = tmpKelvin >= 66 ? 255 : tmpKelvin <= 19 ? 0
                                                    : fmax(0, fmin(255, 138.5177312231 * log(tmpKelvin - 10) - 305.0447927307)); // .998

    return rgb;
}

struct RGB get_RGB_from_mireds(uint16_t color_mireds)
{
    // Convert mireds to R, G, B values

    // Mireds is the reciprocal of the color temperature in microreciprocal degrees (1,000,000 / color_temp)
    // The color temperature is defined in terms of the CIE 1931 color space and is given by the following equation:
    // CCT = 1,000,000 / Mireds
    // The valid range is 1 - 65535 corresponding to a color temperature range of 1,000,000 - 1829 Kelvin
    // The value 0xFFFF means that the light does not support a color temperature.

    double kelvin = 1000000.0 / color_mireds;
    double tmpKelvin;

    // All calculations require tmpKelvin \ 100, so only do the conversion once
    tmpKelvin = fmax(1000, fmin(40000, kelvin)) / 100;    

    struct RGB rgb;

    // Thanks to Tanner Helland for his calculations for Kelvin to RGB, with contributions from Mike D Sutton
    // Note: The R-squared values for each approximation follow each calculation
    rgb.r = tmpKelvin <= 66 ? 255 : fmax(0, fmin(255, 329.698727446 * pow(tmpKelvin - 60, -0.1332047592))); // .988

    rgb.g = tmpKelvin <= 66 ? fmax(0, fmin(255, 99.4708025861 * log(tmpKelvin) - 161.1195681661)) : // .996
                fmax(0, fmin(255, 288.1221695283 * pow(tmpKelvin - 60, -0.0755148492)));            // .987

    rgb.b = tmpKelvin >= 66 ? 255 : tmpKelvin <= 19 ? 0
                                                    : fmax(0, fmin(255, 138.5177312231 * log(tmpKelvin - 10) - 305.0447927307)); // .998
    
    return rgb;
}

