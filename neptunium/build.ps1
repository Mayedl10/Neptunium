$ScriptPath = $MyInvocation.MyCommand.Path
$ScriptDirectory = Split-Path $ScriptPath
# Change the working directory to the script's directory
Set-Location -Path $ScriptDirectory

$srcfiles = "src/*.cpp"

$includepaths = @("include")
$includeoption = ""

$librarypaths = @(".", "lib")
$librarypathoption = ""

$libraries = @("raylib", "raylibdll", "winmm", "gdi32")
$libraryoption = ""

$exeout = "build/main"

foreach ($headerPath in $includepaths) {
    $includeoption += "-I$headerPath "
}

foreach ($libfolderPath in $librarypaths) {
    $librarypathoption += "-L$libfolderPath "
}

foreach ($lib in $libraries) {
    $libraryoption += "-l$lib "
}

try {
    $command = "g++ $srcfiles $includeoption $librarypathoption $libraryoption -o $exeout"

    Write-Host ""
    Write-Host ""
    Write-Host "$command"
    Write-Host ""
    Write-Host ""

    Invoke-Expression $command
    Write-Output "Compilation successful. Starting program."
    Start-Process .\build\main.exe
}
catch {
    Write-Output ""
    Write-Output "-----"
    Write-Output "Failed compilation."
    Write-Output "-----"
    Write-Output ""
}
