@echo off

echo starting test

for /l %%x in (1, 1, 1000) do (
    generator > input.in
    solution < input.in > output.out
    brute < input.in > output2.out
    fc output.out output2.out > diagnostics || exit /b

    echo %%x
)

echo all tests passed
