This is my own experimental fork of the levoit component from: [tuct/esphome-projects](https://github.com/tuct/esphome-projects)

It includes my own work on implementing support for the levoit superior 6000s humidifier as well as some refactoring and cleanup.

Here be dragons, and by dragons I mean a moderate amount of vibe coding and lots of un-tested code. This is meant mostly as a quick and dirty attempt to get my devices working the way I want them. Use at your own risk.

## Tear-down Guide

Take the top segment of the humidifier off and flip it over. Unscrew these four screws from the bottom:
<img width="3024" height="4032" alt="PXL_20261006_165821135 MV" src="https://github.com/user-attachments/assets/55e426d3-7ed4-4093-a254-28075c7bf894" />

Next you need to release each of these clips. They clip in on both sides so they can be a bit tricky to remove. I use this method, just be careful not to put too much force on the thin outer edge:
<img width="3024" height="4032" alt="PXL_20261006_170311734 MV" src="https://github.com/user-attachments/assets/616bc352-82d3-4597-a0fb-68a0bcadc23f" />

After that the top rim should com off as shown in the next picture. Next you'll want to unscrew the four circled screws and pull up while unclipping the three clips indicated by arrows:
<img width="3024" height="4032" alt="PXL_20261006_170552343 MV" src="https://github.com/user-attachments/assets/ea2169e6-63cf-4e94-80c6-4c9eb5bcb597" />

For reference, this is the piece you are removing, notice that you can use any of the three thin white posts to help pull up on it:
<img width="3024" height="4032" alt="PXL_20261006_170727218 MV" src="https://github.com/user-attachments/assets/307958eb-e616-419e-bfe6-9b6de051c599" />

Once that is off you'll need a very long screw driver. First remove the three screws around the hub of the fan:
<img width="4032" height="3024" alt="PXL_20261006_170754511 MV" src="https://github.com/user-attachments/assets/f7f8986e-f0a0-4873-b0d8-6f4bfae7b9b2" />

Then go around and remove all of the screws around the outside of the fan shroud. There should be 11 I believe, although it may be 10. Here are pictures for reference:
<img width="3024" height="4032" alt="PXL_20261006_170908080 MV" src="https://github.com/user-attachments/assets/a8a55ea3-f336-448c-aa9d-1ee9711f8818" />
<img width="4032" height="3024" alt="PXL_20261006_170940677" src="https://github.com/user-attachments/assets/b4f8d899-8725-4906-840e-a58e05061cac" />

From there should should be able to flip it over and the entire black top should come off. There aren't any clips, so just make sure you got every screw. You should then have full access to the internal board.
