for /f "tokens=*" %%a in ('dir /b /a-d fib*.txt') do type "%%a" >> combined-fib.txt
for /f "tokens=*" %%a in ('dir /b /a-d qsort*.txt') do type "%%a" >> combined-qsort.txt
for /f "tokens=*" %%a in ('dir /b /a-d iterative*.txt') do type "%%a" >> combined-iterative.txt
for /f "tokens=*" %%a in ('dir /b /a-d array_sum*.txt') do type "%%a" >> combined-array_sum.txt
