$ScriptPath = $MyInvocation.MyCommand.Path
$ScriptDirectory = Split-Path $ScriptPath
# Change the working directory to the script's directory
Set-Location -Path $ScriptDirectory

g++ -shared src/Neptunium.cpp -Iinclude -L. -Llib -lraylib -lraylibdll -lwinmm -lgdi32 -static -o build/neptunium.dll