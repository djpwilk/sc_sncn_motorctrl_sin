SOMANET External ADC Input Demo Quickstart Guide
================================================

Pre-requisites
--------------

   * You have setup the host computer running the XMOS tools as per [DOC REF]
   * You have setup the host computer running the etherCAT master as per [ DOC REF] (if applicable)
   * You have assembled the SOMANET hardware as per [DOC REF]
   
Preparation
-----------

   * Step by step of how to prepare things to run on the host side
   
Import and build the application
--------------------------------

   #. Open the xTIMEcomposer studio and ensure that it is operating in online mode. 
   #. Open the *Edit* perspective (Window -> Open Perspective -> XMOS Edit).
   #. Open the *xSOFTip* view from (Window -> Show View -> xSOFTip). An *xSOFTip* window appears on the bottom-left.
   #. Search for *SOMANET External ADC Input Demo*.
   #. Click and drag it into the *Project Explorer* window. Doing this will open a *Import xTIMEcomposer Software* window. Click on *Finish* to download and complete the import.
   #. This will also automatically import dependencies for this application.
   #. The application will be called *app_test_adc_external_input* in the *Project Explorer* window.

Building the Webserver demo application:

   #. Click on the *app_test_adc_external_input* item in the *Project Explorer* window.
   #. Click on the *Build* (indicated by a 'Hammer' picture) icon.
   #. Check the *Console* window to verify that the application has built successfully.

Run the application
-------------------

To run the application using xTIMEcomposer studio:

   #. In the *Project Explorer* window, locate the *app_webserver_demo.xe* in the (app_webserver_demo -> Binaries).
   #. Right click on *app_webserver_demo.xe* and click on (Run As -> xCORE Application).
   #. A *Select Device* window appears.
   #. Select *SOMANET-C22-Motor_control-XScope* and click OK.

The Demo
--------

   #. When you first execute the application you should see blah blah blah
   #. Now do X. Do exactly X, nothing but X (and definitely not Y)
   #. If you have executed the step above correctly you should see Z. Otherwise, stop the demo using the red stop icon in the console window and then re-run the deme (see *Run the Application* above), and ensure to follow all instructions above in strict order.
   
Next Steps
----------

   #. Try changing the #WIDGET parameter in xyz.h  to change the frequency of the widget, then rerun the demo.
   #. Look at the code in abc.xc. Notice how wonderful it is and how rich the API seems.

