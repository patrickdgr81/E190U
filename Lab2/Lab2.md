For this lab, I created some firmware to use the controller with a computer. All the code I wrote and will use is in KeyboardControl. All other files were helpful in initial testing, but do not contain significant changes from the sample state.

The week starting off quite challenging, since I did not solder some connections very well and when a wire got loss, trying to repair it caused several other wires to get loose and it was a major headache. If I had a do over, I would've tried to solder and wire more cleanly the first time for sure.

I'll talk about each component specifically. The left joystick behaves as awsd. Its programmed in a way such that you have to move the stick back to the center if you want to press a button again. If you keep the joystick in a position, one letter will be pressed and that's it. 

Each of the buttons corresponds to a specific button on the actual keyboard. For instance, right trigger key is the space button. The other buttons can be changed as needed depending on the game being played. I do a similar thing in software where I have a flag that detects the state of the button and a click is registered only if the button is let go first.

I use the right joystick for mouse movement. I find the center point is read as 325, so I just adjust the range of the values accordingly.

The switch can be used to turn off delays entirely. As of now, by default there is a small delay to make the mouse more smooth, but the user can choose to turn it off.

This lab was very nice and straightforward. Overall there was some challenges in initially getting the buttons and joysticks to register, but afterwards the firmware was straightforward.