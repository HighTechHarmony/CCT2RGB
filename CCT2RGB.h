struct RGB
{
    int r;
    int g;
    int b;
};

/* Takes color temperature in mireds, returns a struct containing int values for R, G, B (0-255) */
struct RGB get_RGB_from_mireds(uint16_t color_mireds);

/* Takes color temperature in mireds, returns a struct containing int values for R, G, B (0-255) */
struct RGB get_RGB_from_kelvin(uint16_t color_kelvin);


