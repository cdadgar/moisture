/*
 * capacitance moisture tester 
 * 
 * board is labeled Moisture Sensor v1.2
 * there is a v2.0 version...how is it different?
 * VCC DC 3.3-5.5V
 * output DC 0-3.0V   (analog)
 * the wemos d1 mini analog input accepts 0-3.3V
 * it has an internal voltage divider to drop the input
 * down to 0-1.0 for the esp
 * less moisture = higher voltage
 * more moisture = lower voltage
 * 
 * how to calibrate?
 * https://www.youtube.com/watch?v=pFQaFnqpOtQ
 * 
 * ruggedized:  https://www.youtube.com/watch?v=3CSiU2CtEl4
 * clear coat eurathane sealant over the electronics
 * (multiple coats front and back)
 * heat shrink over the top of the sensor
 * size: ?  measure with normal heat shrink
 * dual wall adhesive heat shrink  (buy n ali or ebay)
 * mash the top together
 * 
 * some projects average a bunch of readings together to get a more stable
 * reading.  seems pretty stable as is.
 */

const int dry = 595;  // value for a dry sensor
const int wet = 239;  // value for a wet sensor


void setup() {
  // start serial port
  Serial.begin(115200);
  Serial.print(F("\n\n moisture test\n\n"));
}


void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  // translate to a scale of 0% to 100% using the min and max values
  int percentageHumidity = map(sensorValue, wet, dry, 100, 0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.2V):
  float voltage = sensorValue * (3.2 / 1023.0);

  Serial.print(voltage);
  Serial.print("V ");
  Serial.print(percentageHumidity);
  Serial.println("%");
  delay(100);
}
