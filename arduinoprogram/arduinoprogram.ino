#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

int SSSS,MMMM,HHHH,DDDD,CCCC; //variables
long YYYY; //variable 
DateTime rtcOutPut; //vairable for obtaininh both date and time

using namespace std;

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );



/*
 * Initialize the serial port.
 */
void setup( )
{
  Serial.begin( 9600);
  rtc.begin(); //Initialitze the RTC
}



/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every 3.0001 seconds (minimum period). */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}



/* c:\gnuplotexamples
 * Main program loop.
 */
void loop( )
{
  float temperature;
  float humidity;


  rtcOutPut = rtc.now(); //obtains the current time and date


    //Classes to variables from rtcOutPut for more comfortable use
    SSSS=rtcOutPut.second();
    MMMM=rtcOutPut.minute();
    HHHH=rtcOutPut.hour();
    DDDD=rtcOutPut.day();
    CCCC=rtcOutPut.month();
    YYYY=rtcOutPut.year();

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if( measure_environment( &temperature, &humidity ) == true )
  {
    //Print date and time
    Serial.print(YYYY);
    Serial.print("-");
    Serial.print(CCCC);
    Serial.print("-");
    Serial.print(DDDD);
    Serial.print("T");
    Serial.print(HHHH);
    Serial.print(":");
    Serial.print(MMMM);
    Serial.print(":");
    Serial.print(SSSS);

    //Print temperature (in ºC), with a comma before to separate the value
    Serial.print (",");
    Serial.print(temperature, 2); //2 decimals
    //Print humidity (in %), with a comma before to separate the value
    Serial.print (",");
    Serial.print (humidity, 2); //2 decimals

    //Print endl
    Serial.println();

  }

  //delay(1000); //DELAY IT IS NOT NEEDED BECAUSE OF LINE 39: if( millis( ) - measurement_timestamp > 3000ul )
}
