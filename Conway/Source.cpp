#include <thread>

namespace Source {
	using namespace System::Windows::Forms;

	public class Source {
	protected: static std::thread* gameSimulator;

			 static void beginSimulation(array<Button^>^ buttons, array<bool>^ cells) {
				 gameSimulator = new std::thread([]() {
					 std::this_thread::sleep_for(std::chrono::milliseconds(1));
					 });
			 }
	};

}