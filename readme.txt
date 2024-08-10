FOR C++
1st - Open wgnuplot.exe
      Change the directory-> write the command: cd 'C:\gnuplotexamples' (put your actual
      Load the plot file-> write the command: load "plot.p"
2nd - Keep generating your data (in the example, run the code 'sinewithdelay.cpp')


FOR ARDUINO
1st - Your Arduino has to be connected to the PC, and running the program, it has to print the data with SerialPrint() the way you want in your file (check the example)
2nd - Open CoolTerm.exe
      Select yout port-> click on Options>Serial Port>Port and select the port where your Arduino is connectected and select the same baudrate as your Arduino program and click 'OK'
      Connect CoolTerm to the Arduino-> click on 'Connect', wait 10 seconds or 2 times the Serial.Print() rate to verify that CoolTerm is reading the Arduino output
      Connect-> go to 'Connection' foldable on the top > file capture > start; go to the same folder where the gnuplot script is and name your file 'data.csv'
3rd - Adapt the gnuplot script-> Open 'plot2.p' with the notepad, adjust the xrange to your date (don't worry, it is in autoscale) 
4th - Open wgnuplot.exe
      Change the directory-> write the command: cd 'C:\gnuplotexamples'
      Load the plot file-> write the command: load "plot2.p"


*** - If you want to stop continous plotting, close the wgnuplot command window to shut down everything;
      or open the gnuplot script 'plot.p' or 'plot2.p' with the notepad and change the command "reread" for "#reread" and save the script; for loading again, delete the "#" and save the script, then load the plot file again

*** - Need to download the programs?
      GNUPLOT: http://www.gnuplot.info/ (if you download the .zip file for avoid the install, the wgnuplot.exe file is in C:\gnuplot\bin)
      CoolTerm: https://freeware.the-meiers.org/ (the CoolTerm.exe file is in C:\CoolTermWin64Bit)