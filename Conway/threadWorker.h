#pragma once
#include <thread>
#include "MyForm.h"

using namespace System::Windows::Forms;
using namespace System::Threading;


public ref class ThreadWorker {
	static array<int>^ neighborArray;
	static MyForm^ form;
	static array<bool>^ cells;


public: 
	static void beginSimulation(array<Button^>^ buttons, array<bool>^ c, MyForm^ f) {
		neighborArray = gcnew array<int>(4900);
		form = f;
		cells = c;
		Thread^ gameSimulator = gcnew Thread(gcnew ThreadStart(start));
		gameSimulator->Start();
	}

	static void start() {
		calculateNeighbors(cells);
		for (int i = 0; i < 4900; i++) {
			bool cell = cells[i];
			if (cell) {
				if (neighborArray[i] != 2 && neighborArray[i] != 3) {
					//Kill the living cell.
					cells[i] = false;
					form->fillGrid(i / 70, i % 70);
				}
			}
			else {
				if (neighborArray[i] == 3) {
					//Revive the dead cell.
					cells[i] = true;
					form->fillGrid(i / 70, i % 70);
				}
			}
		}
		Thread::Sleep(1000);
		start();
	}

	static void calculateNeighbors(array<bool>^ cells) {
		for (int i = 0; i < 4900; i++) {
			int col = i % 70;
			int row = i / 70;
			std::vector<int> indexesToCheck;
			std::vector<int> rowsToCheck;
			std::vector<int> colsToCheck;
			if (row > 0 && row < 69) {
				rowsToCheck.push_back(row - 1);
				rowsToCheck.push_back(row);
				rowsToCheck.push_back(row + 1);
			}
			else if (row > 0) {
				rowsToCheck.push_back(row - 1);
				rowsToCheck.push_back(row);
			}
			else {
				rowsToCheck.push_back(row);
				rowsToCheck.push_back(row + 1);
			}

			if (col > 0 && col < 69) {
				colsToCheck.push_back(col - 1);
				colsToCheck.push_back(col);
				colsToCheck.push_back(col + 1);
			}
			else if (col > 0) {
				colsToCheck.push_back(col - 1);
				colsToCheck.push_back(col);
			}
			else {
				colsToCheck.push_back(col);
				colsToCheck.push_back(col + 1);
			}

			for (int rowIt : rowsToCheck) {
				for (int colIt : colsToCheck) {
					if (rowIt != row || colIt != col) {
						indexesToCheck.push_back(rowIt * 70 + col);
					}
				}
			}

			int total = 0;
			for (int index : indexesToCheck) {
				total += cells[index] ? 1 : 0;
			}
			neighborArray[i] = total;
		}
	}
};