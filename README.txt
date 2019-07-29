Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Function Pointers Tutorial!
Prerequesites: Smart Pointers

Function pointers allow you to pass a function (lets's call it FunctionA), 
as a paremeter to another function, (let's call it FunctionB). 
After FunctionB takes FunctionA as a parameter, FunctionA gets called inside
FunctionB, and this is amazing because FunctionA can be any function
in the entire program. FunctionB can use FunctionA in any way it wants
