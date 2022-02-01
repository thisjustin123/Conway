#include "MyForm.h"
#include "threadWorker.h"
using namespace System;

using namespace System::Windows::Forms;


[STAThreadAttribute]


void Main(array<String^>^ args)

{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	MyForm form; 
	Application::Run(% form);

}
