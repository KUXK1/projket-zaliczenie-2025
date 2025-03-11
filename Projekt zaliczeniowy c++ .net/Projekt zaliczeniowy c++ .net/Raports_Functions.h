#pragma once
#include "Elements.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;  

void SaveToCSV(array<Elements^>^ elementsArray, String^ filePath);

