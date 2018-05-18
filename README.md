# BeerSpectrometer

The purpose of this project is to measure the color of beer.

The Standard Reference Method is the most commonly used system to catalog beer color in the United States. It is a simple absorption measurement at a single wavelength of 430 nm. While this project does not use monochromatic light, it does use an LED peaked at 430 nm with a FWHM of approximately 50 nm, the Everlight MV5B60. Light from the LED is collected using an Adafruit CdS photoresistor after it has passed through the sample holder cell which is designed for a 1 cm pathlength cuvette.

By taking three measurements, a background, bright, and absorptive measurement, the SRM number of the beer can be calculated. To interface with the user, this project uses an a 16x2 LCD screen which instructs the user, and a button which is used to progress the measurements. The project is run using an Amica NodeMCU v2 and powered with a USB cable which can be plugged into any 5 V USB charger.

The box designed to house the components was created using TinkerCAD and designed with 3D printing in mind. There is an optional 12 mm hole which can house an Edmund Optics 430 nm bandpass with a FWHM of 10 nm centered around 430 nm.

Standard Reference Method: https://en.wikipedia.org/wiki/Standard_Reference_Method

Everlight MV5B60: https://www.mouser.com/datasheet/2/143/everlight_ds300028-1165996.pdf

Adafruit CdS Photoresistor: https://www.mouser.com/datasheet/2/737/photocells-932884.pdf

Edmund Optics 430 nm Bandpass: https://www.edmundoptics.com/optics/optical-filters/bandpass-filters/430nm-cwl-10nm-fwhm-11.8mm-unmounted-diameter/?site=EN&countryid=232
