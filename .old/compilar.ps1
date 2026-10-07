#Requires -Version 5.1
param (
    [Parameter(ValueFromRemainingArguments = $true)]
    [string[]]$Args
)

# Verificar que se haya pasado al menos un argumento
if ($Args.Count -lt 0 -and (-not $Args)) {
    # Nota: El bloque parameter con ValueFromRemainingArguments captura todo, 
    # pero verificamos si está vacío de forma segura.
}

if (-not $Args -or $Args.Count -eq 0) {
    Write-Host "Uso: .\compilar.ps1 archivo1.c [archivo2.c ...] [opciones gcc ...]"
    Write-Host ""
    Write-Host "Ejemplo:"
    Write-Host "  .\compilar.ps1 main.c funciones.c -lm"
    Write-Host "  .\compilar.ps1 main.c funciones.c -Iinclude -lm -O2"
    exit 1
}

# ---------------------------------------------------------
# Buscar el primer archivo .c para utilizar su nombre
# como nombre del ejecutable.
# ---------------------------------------------------------

$C_File = ""

foreach ($arg in $Args) {
    if ($arg -like "*.c") {
        $C_File = $arg
        break
    }
}

# Verificar que haya al menos un archivo .c
if ([string]::IsNullOrEmpty($C_File)) {
    Write-Host "Error: debes proporcionar al menos un archivo .c." -ForegroundColor Red
    exit 1
}

# ---------------------------------------------------------
# Verificar que los archivos .c existan
# ---------------------------------------------------------

foreach ($arg in $Args) {
    if ($arg -like "*.c") {
        if (-not (Test-Path -Path $arg -PathType Leaf)) {
            Write-Host "Error: el archivo '$arg' no existe." -ForegroundColor Red
            exit 1
        }
    }
}

# ---------------------------------------------------------
# Crear directorio build
# ---------------------------------------------------------

if (-not (Test-Path -Path ".\build" -PathType Container)) {
    New-Item -ItemType Directory -Force -Path ".\build" | Out-Null
}

# ---------------------------------------------------------
# Obtener nombre del programa a partir del primer .c
# ---------------------------------------------------------

$ProgramName = [System.IO.Path]::GetFileNameWithoutExtension($C_File)
$Output = ".\build\$ProgramName.exe"

# ---------------------------------------------------------
# Compilar
# ---------------------------------------------------------

Write-Host "Compilando..."
Write-Host "gcc -Wall -Werror -std=c11 $($Args -join ' ') -o $Output"
Write-Host ""

# Ejecutamos gcc redirigiendo stderr y stdout a un archivo temporal
$compileLog = ".\compile.out"
& gcc -Wall -Werror -std=c11 @Args -o $Output *>&1 | Out-File -FilePath $compileLog -Encoding utf8

if ($LASTEXITCODE -eq 0) {
    Write-Host "Compilación exitosa." -ForegroundColor Green
    Write-Host "Ejecutable: $Output"
    Write-Host ""
    Write-Host "Ejecutando..."
    Write-Host ""

    # Ejecutar el binario generado
    & $Output
} else {
    Write-Host "Error de compilación:" -ForegroundColor Red
    Write-Host ""
    Get-Content $compileLog
    exit 1
}