# Data and Telemetry System
   This is Data and Telemetry system made for monitoring the real time vehicle parameters 
   during running condition. This kit specifically made according to the guidelines of the 
   Shell Eco Marathon Global event conducted every year by shell for hyper efficient vehicles.

   # This Telemetry kit is simple and can easily be installed in any vehicle.
   This Kit consists of
   1. arduino Uno
   2. Bluetooth module
   3. Hall current sensor
   4. Hall effect speed sensor(with suitable filter)
   5. A buck regulator for constant 5V bus for the kit
   6. An Android phone with bluetooth and internet enabled

 # Working
    1. This uses Hall effect current sensor for measuring the current drawn from the 
       battery and hallsensor based speed measurement and distance calculation.
    2. Then arduino calculates current, speed, travelled distance by the vehicle,
       Efficiency of the vehicle(Km/KWh),and cosumed energy
    3. Then all the data goes from arduino to a android phone through bluetooth module 
       in the kit.
    4. The android shows the data through driver friendly interface made by MIT APP 
       INVENTOR .
    5. Then the same data is automatically get written to a google sheet , which can be
      access by anyone anywhere in the world.

   
