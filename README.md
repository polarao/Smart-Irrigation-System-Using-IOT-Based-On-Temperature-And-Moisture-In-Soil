# Smart-Irrigation-System-Using-IOT-Based-On-Temperature-And-Moisture-In-Soil
Monitoring moisture content and temperature and control water pump(on/off) in android mobile
<h2>Introduction</h2>
<p> In India, agriculture in villages plays an essential role in developing the country. Basically, agriculture depends on the monsoons which have not enough water source. To overcome this problem, the Smart Irrigation System using IOT based on temperature and moisture in soil is employed in the field of agriculture.</p> 
<p>	 In this system, based on the soil and environment conditions, the water will be provided to the agricultural field. In agriculture, there are two things, namely, the moisture content of the soil as well as environment temperature. </p>

<h2>Diagram</h2>
<img src="images/diagram.jpg" style="width:20px;height:20px;" id="psystem">


<h2>Abstract</h2>
<p> In the agriculture field, sensors are used like soil moisture and temperature. The information received from the sensors is sent to the Database folder through the Nodemcu(ESP8266). In the control section, the system is activated using the android application, this is finished using the ON/OFF buttons in the application.the appliction provide a facility to human intraction in the form of button for controlling motor in croft.</p>

<h2>Existing System</h2>
<p color="red">Automatic Plant Watering System Using Arduino Uno</p>
<img src="images/diagram2.jpg" style="width:20px;height:20px;">
<p>  (1)In this system, soil moisture sensor senses the moisture level of the soil. <br/>
  (2)If soil will get dry then sensor senses low moisture level and automatically switches on the water pump to supply water to the plant.<br/>
 (3)As plant get sufficient water and soil get wet then sensor senses enough moisture in soil. After which the water pump will automatically get stopped.<br/>
</p>

<img src="images/automatic.jpg" style="width:20px;height:20px;">

<h2>Proposed System</h2>
<h3><a href="#psystem">Smart-Irrigation-System-Using-IOT-Based-On-Temperature-And-Moisture-In-Soil</a></h3>
<p> (1)With the help of this project the soil moisture and temperature can be monitored from anywhere around the world with the help of  mobile application. 
  
(2)Based on moisture content in the soil we can on or off the water pumping manually using android app.
</p>

<h2>Requirements</h2>
<ul>
  <li>Nodemcu (WiFiModule ESP8266)</li>
  <li>DHT11</li>
  <li>Soil Moisture Meter</li>
  <li>Relay</li>  
  <li>Database</li>
  <li>Android Studio</li>
  <li>Water motor</li>
</ul>

<h2>Database Tables</h2>
<h3>Motor Table</h3>
<p>motor_table with two attributes id and status</p>
<img src="images/motor.PNG" style="width:20px;height:20px;">
<h3>Weather Table</h3>
<p>weather table with id, temp, hum and mois attributes</p>
<img src="images/weather.PNG" style="width:20px;height:20px;">

<h2>Uploading Php api files into file directorty in server</h2>
<p>Create two folders one for motor_table and another for weather table and then upload api files.</p>
<img src="images/motor_api_files.PNG" style="width:20px;height:20px;">
<img src="images/weather_api_files.PNG" style="width:20px;height:20px;">

<h3>Copy APIs links of weather and motor php files</h3>
<img src="images/motor_insert_api_link.PNG" style="width:20px;height:20px;">
<img src="images/motor_read_all_api_link.PNG" style="width:20px;height:20px;">
<img src="images/weather_insert_api_link.PNG" style="width:20px;height:20px;">
<img src="images/weather_read_all_api_link.PNG" style="width:20px;height:20px;">

<h2>Connections for Nodemcu and Sensors</h2>
<p>According to your requirement you can change pins in nodemcu(WiFiModule ESP8266)</p>
