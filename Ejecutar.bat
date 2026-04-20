@echo off
echo Compilando...

REM Esto para facilitar a la hora de compilar pq ya eh abierto y cerrado el powershell 70 veces para ver los errores

g++ -std=c++11 Cliente.cpp DataManagerJson.cpp Empleado.cpp main.cpp Persona.cpp Producto.cpp Sistema.cpp Utils.cpp Venta.cpp -o app

if %errorlevel% neq 0 (
    echo.
    echo Error al compilar.
    pause
    exit /b
)
REM Simple pero efectivo :D
echo.
echo Abriendo...
echo.
app
echo.
pause