#include <iostream>
using namespace std;


class CPU {
 public:
	virtual void calculator() = 0;
	virtual ~CPU() {}
};

class GPU {
 public:
	virtual void display() = 0;
	virtual ~GPU() {}
};

class Memory {
 public:
	virtual void storage() = 0;
	virtual ~Memory() {}
};

class Computer {
 public:
	Computer(CPU *cpu, GPU *gpu, Memory *memory) {
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
	}
	void doWork() {
		m_cpu->calculator();
		m_gpu->display();
		m_memory->storage();
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL) {
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_memory != NULL) {
			delete m_memory;
			m_memory = NULL;
		}
	}
 private:
	CPU *m_cpu;
	GPU *m_gpu;
	Memory *m_memory;
};


class intelCPU : public CPU {
	void calculator() {
		cout << "intel CPU calaulator\n";
	}
};

class navdiaGPU : public GPU {
	void display() {
		cout << "navdia GPU display\n";
	}
};

class samsungMemory : public Memory {
	void storage() {
		cout << "samsung Memory storage\n";
	}	
};

int main(int argc, char *argv[]) {
	CPU *intel = new intelCPU;
	GPU *navdia = new navdiaGPU;
	Memory *samsung = new samsungMemory;
	Computer(intel, navdia, samsung).doWork();
	return 0;
}