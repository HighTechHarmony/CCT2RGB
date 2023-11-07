# CCT2RGB
Simple C library for converting color temperature in mireds or kelvin to values for R, G, B 

Adapted from algorithm by [Tanner Helland](https://tannerhelland.com/2012/09/18/convert-temperature-rgb-algorithm-code.html "Tanner Helland"). This is a  high-quality approximation, suited to artistic use only. Not precise enough for scientific use.

## Usage
    include "CCT2RGB.h"
    
    struct RGB rgb;
    
    rgb = get_RGB_from_mireds(20000);
    printf ("Red: %d\n", rgb.r);
    printf ("Green: %d\n", rgb.g);
    printf ("Blue: %d\n", rgb.b);
	
	rgb = get_RGB_from_kelvin(4000);
    printf ("Red: %d\n", rgb.r);
    printf ("Green: %d\n", rgb.g);
    printf ("Blue: %d\n", rgb.b);
    
    

