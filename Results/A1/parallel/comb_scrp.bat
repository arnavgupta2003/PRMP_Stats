for /f "tokens=*" %%a in ('dir /b /a-d fib*.txt') do type "%%a" >> combined.txt
