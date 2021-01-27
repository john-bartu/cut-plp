#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <map>
#include <atomic>
#include <iostream>
#include <chrono>
#include <condition_variable>
#include <iomanip>

using namespace std;

#define NO_PHILOSOPHERS 5

bool DEBUG = false;

mutex forks[NO_PHILOSOPHERS];

atomic<int> tableCount;
mutex tableLock;

mutex printLock;
condition_variable cv;

bool chairAvailable() { return tableCount > 0; }

class Philosopher {
private:
    int id;
    string name;

    mutex &leftFork(int i) {
        return forks[i];
    }

    mutex &rightFork(int i) {
        return forks[(i + 1) % NO_PHILOSOPHERS];
    }

public:

    Philosopher();

    Philosopher(int id) : id(id) { this->name = "Philosopher"; }

    Philosopher(int id, string name) : id(id), name(name) {}

    static void randomSleep() {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
    }

    void operator()() {

        for (int i = 0; i < 2; i++) {

            {
                const lock_guard<mutex> lock(printLock);
                cout << setw(20) << name << " id: " << id << ", is thinking 💤" << endl;
            }

            {
                unique_lock<mutex> tempLock(tableLock);
                auto sec = chrono::seconds(2);
                if (!cv.wait_for(tempLock, 2 * sec, chairAvailable)) {
                    cout << setw(20) << name << " id: " << id << ", starved to death" << endl;
                    break;
                }
                tableCount--;
            }


            if (DEBUG) printf("Philosopher id: %i, joined the table\n", id);

            randomSleep();
            if (DEBUG) printf("Philosopher id: %i, acquiring LEFT fork\n", id);
            leftFork(id).lock();
            if (DEBUG) printf("Philosopher id: %i, acquired LEFT fork\n", id);

            randomSleep();
            if (DEBUG) printf("Philosopher id: %i, acquiring RIGHT fork\n", id);
            rightFork(id).lock();
            if (DEBUG) printf("Philosopher id: %i, acquired RIGHT fork\n", id);


            if (DEBUG) printf("Philosopher id: %i, acquired forks\n", id);


            {
                const lock_guard<mutex> lock(printLock);
                cout << setw(20) << name << " id: " << i << ", is eating 🍴 now" << endl;
            }

            randomSleep();

            leftFork(id).unlock();
            rightFork(id).unlock();

            if (DEBUG) printf("Philosopher id: %i, released  forks\n", id);

            {
                unique_lock<mutex> tempLock(tableLock);
                tableCount++;
            }


            if (DEBUG) printf("Philosopher id: %i, left the table\n", id);

            {
                const lock_guard<mutex> lock(printLock);
                cout << setw(20) << name << " id: " << id << ", is full 🙂" << endl;
            }


        }
    }
};


int main(int argc, char *argv[]) {

    DEBUG = (argc == 2 && strcmp(argv[1], "-d") == 0);
    printf("Dining-philosophers problem. Example with waiter\n");
    if (DEBUG) printf("In debugging mode...\n");

    tableLock.lock();
    tableCount = NO_PHILOSOPHERS - 1;
    tableLock.unlock();
    {
        const lock_guard<mutex> lock(printLock);
        cout << "Create philosophers..." << endl;
    }
    Philosopher philosophers[NO_PHILOSOPHERS] = {{0, "Tales 👩"},
                                                 {1, "Pythagoras 🧓"},
                                                 {2, "Heraclitus 🤶"},
                                                 {3, "Platon 👳"},
                                                 {4, "Aristotle's 👵"}};

    {
        const lock_guard<mutex> lock(printLock);
        cout << "Create threads... " << endl;;
    }

    thread threads[NO_PHILOSOPHERS];
    for (int i = 0; i < NO_PHILOSOPHERS; i++) {
        threads[i] = thread(philosophers[i]);
    }


    {
        const lock_guard<mutex> lock(printLock);
        cout << "Wait for threads... " << endl;
    }

    for (auto &thread : threads) {
        thread.join();
    }

    printf("Thank you for attention.\n");
    return 0;
}