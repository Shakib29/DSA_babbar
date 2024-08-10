@echo off

:: Navigate to the DSA folder
cd /d C:\path\to\your\DSA-folder

:: Add all changes
git add .

:: Commit with a generic message
git commit -m "Auto-update %date% %time%"

:: Push to the GitHub repository
git push origin master
