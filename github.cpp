//this is simply a file to remind how to upload projects to github

//step 1: 
//use cd command in terminal then drag the project that you want 
//to commit into the terminal to get the directory then hit enter

//step 2: 
// must set up the git ignore.
// type:  touch .gitignore and hit enter
// use command: git status shows you what git thinks is available
//to be tracked in the repository

//step 3:
//open up the .gitignore text file that has been created in the 
//directory of the project. type in **/ followed by the name
// of the directory to ignore, individually for each directory
//
//E.G. for Juce projects:
// **/Builds
// **/JuceLibraryCode
// **/.DS_Store

//step 4:
//use: git status
//to check again what directories will be included and make sure
//git ignore file has been written properly

//step 5:
//add the files that have not ben excluded by the .gitignore
//using the command: git add .

//step 6:
//enter git status again and you will see a list of the changes to be committed

//step 7:
//enter command: git commit -m "initial commit"

//step 8: 
//enter git status to check that changes were successfully committed