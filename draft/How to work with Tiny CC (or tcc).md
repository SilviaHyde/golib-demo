# How to compile

Go to project folder and preprocess the template file:

```
cd C:\Portable\tcc\examples\wstp\addtwo
wsprep addtwo.tm -o tm.c
```

Note **tcc** only recognizes source file extension **.c**.

## Method 1

```
tcc -impdef "C:\Program Files\Wolfram Research\Mathematica\12.0\SystemFiles\Links\WSTP\DeveloperKit\Windows-x86-64\SystemAdditions\wstp64i4.dll" -o wstp.def
tcc -I"C:\Program Files\Wolfram Research\Mathematica\12.0\SystemFiles\Links\WSTP\DeveloperKit\Windows-x86-64\CompilerAdditions" -o bin.exe addtwo.c tm.c wstp.def
```

## Method 2

Register the **WSTP** to **tcc** permanently for once:

```
copy "C:\Program Files\Wolfram Research\Mathematica\12.0\SystemFiles\Links\WSTP\DeveloperKit\Windows-x86-64\CompilerAdditions\wstp.h" C:\Portable\tcc\include\wstp.h
tcc -impdef "C:\Program Files\Wolfram Research\Mathematica\12.0\SystemFiles\Links\WSTP\DeveloperKit\Windows-x86-64\SystemAdditions\wstp64i4.dll" -o C:\Portable\tcc\lib\wstp64i4.def
```

Refer to it with `-lwstp64i4` afterwards:

```
tcc -lwstp64i4 addtwo.c tm.c
```

# How to run

**wstp64i4.dll** needs to be discoverable by OS. So put it in `PATH` or next to the resulting executable.
