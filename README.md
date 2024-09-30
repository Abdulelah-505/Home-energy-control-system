


Guidelines for Running the Code

1. Check Prerequisites

Hardware Requirements:
Ensure you have all the necessary hardware components: a current sensor (e.g., ACS712), a microcontroller board (e.g., Arduino), and a relay module.

Software Requirements:
Verify that the `Ubidots` library is available and installed in your development environment.
Ensure that the WiFi library compatible with your board "ESP32" is installed.

2. Set Up Your Development Environment

Install the Development Environment:
Use an Integrated Development Environment (IDE) such as Arduino IDE or PlatformIO.

Add Libraries:
Install necessary libraries (such as `Ubidots`) through the library manager in your IDE.

3. Configure the Code

Set Up Ubidots Token:
Replace `UBIDOTS_TOKEN` with your actual Ubidots API token.
 
Configure WiFi Credentials:
Update `SSID` and `PASSWORD` with your WiFi networkصs credentials.

Define Device and Variable Labels:
Ensure `DEVICE_LABEL`, `VARIABLE_LABEL`, `VARIABLE_SENDER`, and other labels match the names used in your Ubidots account.

Adjust Sensor and Hardware Parameters:
Set `sensorIn` to the correct analog pin connected to your sensor.
Modify `mVperAmp` according to the specifications of your current sensor.


4. Upload the Code

Connect Your Microcontroller:
Connect your microcontroller board to your computer via USB.

Select the Board and Port:
In your IDE, choose the correct board type and port.

Upload the Code:
Compile and upload the code to your microcontroller.

5. Monitor Serial Output

Open Serial Monitor:
After uploading the code, open the Serial Monitor in your IDE to view debugging and status messages.

Check WiFi Connection:
Confirm that the device connects to your WiFi network successfully. You should see a message like "Connected to WiFi".

Verify Data Transmission:
Ensure that the data (current, power, energy) is being sent to Ubidots and that the relay state changes as expected based on the commands received from Ubidots.

6. Debugging

Check for Errors:
Review any error messages in the Serial Monitor. Errors may indicate issues with library installation, connectivity, or code logic.

Verify Connections:
Ensure all hardware connections (sensor, relay, microcontroller) are correctly made and secure.

Review Code Logic:
Double-check the logic in the code to ensure it correctly handles data reading, processing, and transmission.





7. Testing and Calibration

Test Sensor Readings:
Verify that the sensor readings are accurate and make adjustments if necessary.

Calibrate the Sensor:
If required, calibrate the sensor according to its datasheet to ensure precise measurements.

Monitor Long-Term Performance:
Observe the system over time to ensure stable operation and correct data reporting.



Steps to Access the System
1. Visit the Ubidots Sign-In Page
* Open your web browser and navigate to Ubidots Sign-In.
2. Log In
* Enter the following credentials:
* Username: test_003xxr
* Password: mse991994
* Click on the "Sign In" button.
