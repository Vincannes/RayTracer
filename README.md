

# Ray Tracer Manon .mn
## URLs

https://matklad.github.io/2022/12/31/raytracer-construction-kit.html#Ray-Tracer-Construction-Kit
https://avikdas.com/build-your-own-raytracer/
https://raytracing.github.io/
https://github.com/roma-p/jeanpaul/blob/main/test_data/jpp_single_sphere.jpp
https://github.com/arocks/puray/tree/episode04

## Build cpp

```
cls & cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER="C:/mingw64/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/mingw64/bin/g++.exe" .. & cmake --build . --config Release & ManonTracer.exe
```