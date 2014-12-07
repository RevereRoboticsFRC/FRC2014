Revere Robotics
=======
Robot code for 2014 FRC: Aerial Assist

Wind River Import Instructions
-------
- __In Git:__ Clone the repo to a location of your choice
- __In Wind River:__ Create a project from template: 
```
File > New > Example... > VxWorks Downloadable Kernal Module Sample Project > FRC Iterative Robot Template > Finish
```
- Rename the project: 
```
Right click on project > Rename... > Enter "FRC2014" > OK
```
- Exit __Wind River__
- Rename ```C:\WindRiver\workspace\FRC2014``` to something else (like ```FRC2014_OLD```)
- Open a command line window and enter the following command:
```
mklink /D /J "C:\WindRiver\workspace\FRC2014" "C:\PATH_TO_REPO"
```
where ```C:\PATH_TO_REPO``` is the location of the cloned repo (Usually similar to ```C:\Users\USER\My Documents\GitHub\FRC2014``` if using GitHub for Windows).
- Launch __Wind River__ and the project should now reflect the content of the repo.

Building and Deploying
-------
- Configure the deployment settings: ```Window > Preferences > FIRST Downloader Preferences```
- Set the __Team Number__ (5249)
- Set the file to download to ```C:\WindRiver\workspace\FRC2014\PPC603gnu\FRC2014\Debug\FRC2014.out```
- Build the project (using ```Project > Build Project``` or ```Ctrl-B P```
- Ensure you are connected to the cRIO

If you want the program to persist on the robot and run on startup,
- Deploy the program ```FIRST > Deploy```
- Restart the robot (using the Driver Station or by turning the robot off then on)

If you want to debug or temporarily run the program on the robot,
- TODO

